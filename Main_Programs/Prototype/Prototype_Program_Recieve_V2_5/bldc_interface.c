#include "bldc_interface.h"
#include "buffer.h"
#include <string.h>

// Private variables
static unsigned char send_buffer[512];
static int32_t can_fwd_vesc = -1;

// Private variables for received data
static mc_values values;
static int fw_major;
static int fw_minor;
static float rotor_pos;
static mc_configuration mcconf;
static app_configuration appconf;
static float detect_cycle_int_limit;
static float detect_coupling_k;
static signed char detect_hall_table[8];
static signed char detect_hall_res;
static float dec_ppm;
static float dec_ppm_len;
static float dec_adc;
static float dec_adc_voltage;
static float dec_chuk;

// Private functions
void send_packet_no_fwd(unsigned char *data, unsigned int len);
static void fwd_can_append(uint8_t *data, int32_t *ind);

// Function pointers
static void(*send_func)(unsigned char *data, unsigned int len) = 0;
static void(*forward_func)(unsigned char *data, unsigned int len) = 0;

// Function pointers for received data
static void(*rx_value_func)(mc_values *values) = 0;
static void(*rx_printf_func)(char *str) = 0;
static void(*rx_fw_func)(int major, int minor) = 0;
static void(*rx_rotor_pos_func)(float pos) = 0;
static void(*rx_mcconf_func)(mc_configuration *conf) = 0;
static void(*rx_appconf_func)(app_configuration *conf) = 0;
static void(*rx_detect_func)(float cycle_int_limit, float coupling_k,
		const signed char *hall_table, signed char hall_res) = 0;
static void(*rx_dec_ppm_func)(float val, float ms) = 0;
static void(*rx_dec_adc_func)(float val, float voltage) = 0;
static void(*rx_dec_chuk_func)(float val) = 0;
static void(*rx_mcconf_received_func)(void) = 0;
static void(*rx_appconf_received_func)(void) = 0;

/**
 * Initialize bldc_interface.
 *
 * @param func
 * A function to be used when sending packets. Null (0) means that no packets will be sent.
 */
void bldc_interface_init(void(*func)(unsigned char *data, unsigned int len)) {
	send_func = func;
}

/**
 * Enable or disable can forwarding to other VESCs.
 *
 * @param vesc_id
 * The VESC ID to forward to. Setting this to -1 disables this feature.
 */
void bldc_interface_set_forward_can(int32_t vesc_id) {
	can_fwd_vesc = vesc_id;
}

/**
 * Provide a function to forward received data to instead of processing it and calling handlers.
 * This will also prevent data from being sent.
 *
 * @param func
 * The forward function. Null (0) to disable forwarding.
 */
void bldc_interface_set_forward_func(void(*func)(unsigned char *data, unsigned int len)) {
	forward_func = func;
}

/**
 * Send a packet using the set send function.
 *
 * @param data
 * The packet data.
 *
 * @param len
 * The data length.
 */
void bldc_interface_send_packet(unsigned char *data, unsigned int len) {
	if (send_func) {
		send_func(data, len);
	}
}

/**
 * Process a received buffer with commands and data.
 *
 * @param data
 * The buffer to process.
 *
 * @param len
 * The length of the buffer.
 */
void bldc_interface_process_packet(unsigned char *data, unsigned int len) {
	if (!len) {
		return;
	}

	if (forward_func) {
		forward_func(data, len);
		return;
	}

	int32_t ind = 0;
	int i = 0;
	unsigned char id = data[0];
	data++;
	len--;

	switch (id) {
	case COMM_FW_VERSION:
		if (len == 2) {
			ind = 0;
			fw_major = data[ind++];
			fw_minor = data[ind++];
		} else {
			fw_major = -1;
			fw_minor = -1;
		}
		break;

	case COMM_ERASE_NEW_APP:
	case COMM_WRITE_NEW_APP_DATA:
		// TODO
		break;

	case COMM_GET_VALUES:
		ind = 0;
		values.temp_mos1 = buffer_get_float16(data, 10.0, &ind);
		values.temp_mos2 = buffer_get_float16(data, 10.0, &ind);
		values.temp_mos3 = buffer_get_float16(data, 10.0, &ind);
		values.temp_mos4 = buffer_get_float16(data, 10.0, &ind);
		values.temp_mos5 = buffer_get_float16(data, 10.0, &ind);
		values.temp_mos6 = buffer_get_float16(data, 10.0, &ind);
		values.temp_pcb = buffer_get_float16(data, 10.0, &ind);
		values.current_motor = buffer_get_float32(data, 100.0, &ind);
		values.current_in = buffer_get_float32(data, 100.0, &ind);
		values.duty_now = buffer_get_float16(data, 1000.0, &ind);
		values.rpm = buffer_get_float32(data, 1.0, &ind);
		values.v_in = buffer_get_float16(data, 10.0, &ind);
		values.amp_hours = buffer_get_float32(data, 10000.0, &ind);
		values.amp_hours_charged = buffer_get_float32(data, 10000.0, &ind);
		values.watt_hours = buffer_get_float32(data, 10000.0, &ind);
		values.watt_hours_charged = buffer_get_float32(data, 10000.0, &ind);
		values.tachometer = buffer_get_int32(data, &ind);
		values.tachometer_abs = buffer_get_int32(data, &ind);
		values.fault_code = (mc_fault_code)data[ind++];

		if (rx_value_func) {
			rx_value_func(&values);
		}
		break;

	case COMM_PRINT:
		if (rx_printf_func) {
			data[len] = '\0';
			rx_printf_func((char*)data);
		}
		break;

	case COMM_SAMPLE_PRINT:
		// TODO
		break;

	case COMM_ROTOR_POSITION:
		ind = 0;
		rotor_pos = buffer_get_float32(data, 100000.0, &ind);

		if (rx_rotor_pos_func) {
			rx_rotor_pos_func(rotor_pos);
		}
		break;

	case COMM_EXPERIMENT_SAMPLE:
		// TODO
		break;

	case COMM_GET_MCCONF:
	case COMM_GET_MCCONF_DEFAULT:
		ind = 0;
		mcconf.pwm_mode = (mc_pwm_mode)data[ind++];
		mcconf.comm_mode = (mc_comm_mode)data[ind++];
		mcconf.motor_type = (mc_motor_type)data[ind++];
		mcconf.sensor_mode = (mc_sensor_mode)data[ind++];

		mcconf.l_current_max = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_current_min = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_in_current_max = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_in_current_min = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_abs_current_max = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_min_erpm = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_max_erpm = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_max_erpm_fbrake = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_max_erpm_fbrake_cc = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_min_vin = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_max_vin = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_battery_cut_start = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_battery_cut_end = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_slow_abs_current = data[ind++];
		mcconf.l_rpm_lim_neg_torque = data[ind++];
		mcconf.l_temp_fet_start = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_temp_fet_end = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_temp_motor_start = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_temp_motor_end = buffer_get_float32(data, 1000.0, &ind);
		mcconf.l_min_duty = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.l_max_duty = buffer_get_float32(data, 1000000.0, &ind);

		mcconf.sl_min_erpm = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_min_erpm_cycle_int_limit = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_max_fullbreak_current_dir_change = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_cycle_int_limit = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_phase_advance_at_br = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_cycle_int_rpm_br = buffer_get_float32(data, 1000.0, &ind);
		mcconf.sl_bemf_coupling_k = buffer_get_float32(data, 1000.0, &ind);

		memcpy(mcconf.hall_table, data + ind, 8);
		ind += 8;
		mcconf.hall_sl_erpm = buffer_get_float32(data, 1000.0, &ind);

		mcconf.foc_current_kp = buffer_get_float32(data, 1e5, &ind);
		mcconf.foc_current_ki = buffer_get_float32(data, 1e5, &ind);
		mcconf.foc_f_sw = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_dt_us = buffer_get_float32(data, 1e6, &ind);
		mcconf.foc_encoder_inverted = data[ind++];
		mcconf.foc_encoder_offset = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_encoder_ratio = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_sensor_mode = (mc_foc_sensor_mode)data[ind++];
		mcconf.foc_pll_kp = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_pll_ki = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_motor_l = buffer_get_float32(data, 1e8, &ind);
		mcconf.foc_motor_r = buffer_get_float32(data, 1e5, &ind);
		mcconf.foc_motor_flux_linkage = buffer_get_float32(data, 1e5, &ind);
		mcconf.foc_observer_gain = buffer_get_float32(data, 1e0, &ind);
		mcconf.foc_duty_dowmramp_kp = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_duty_dowmramp_ki = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_openloop_rpm = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_sl_openloop_hyst = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_sl_openloop_time = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_sl_d_current_duty = buffer_get_float32(data, 1e3, &ind);
		mcconf.foc_sl_d_current_factor = buffer_get_float32(data, 1e3, &ind);
		memcpy(mcconf.foc_hall_table, data + ind, 8);
		ind += 8;
		mcconf.foc_hall_sl_erpm = buffer_get_float32(data, 1000.0, &ind);

		mcconf.s_pid_kp = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.s_pid_ki = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.s_pid_kd = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.s_pid_min_erpm = buffer_get_float32(data, 1000.0, &ind);

		mcconf.p_pid_kp = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.p_pid_ki = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.p_pid_kd = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.p_pid_ang_div = buffer_get_float32(data, 1e5, &ind);

		mcconf.cc_startup_boost_duty = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.cc_min_current = buffer_get_float32(data, 1000.0, &ind);
		mcconf.cc_gain = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.cc_ramp_step_max = buffer_get_float32(data, 1000000.0, &ind);

		mcconf.m_fault_stop_time_ms = buffer_get_int32(data, &ind);
		mcconf.m_duty_ramp_step = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.m_duty_ramp_step_rpm_lim = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.m_current_backoff_gain = buffer_get_float32(data, 1000000.0, &ind);
		mcconf.m_encoder_counts = buffer_get_uint32(data, &ind);

		if (rx_mcconf_func) {
			rx_mcconf_func(&mcconf);
		}
		break;

	case COMM_GET_APPCONF:
	case COMM_GET_APPCONF_DEFAULT:
		ind = 0;
		appconf.controller_id = data[ind++];
		appconf.timeout_msec = buffer_get_uint32(data, &ind);
		appconf.timeout_brake_current = buffer_get_float32(data, 1000.0, &ind);
		appconf.send_can_status = data[ind++];
		appconf.send_can_status_rate_hz = buffer_get_uint16(data, &ind);

		appconf.app_to_use = (app_use)data[ind++];

		appconf.app_ppm_conf.ctrl_type = (ppm_control_type)data[ind++];
		appconf.app_ppm_conf.pid_max_erpm = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.hyst = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.pulse_start = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.pulse_end = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.median_filter = data[ind++];
		appconf.app_ppm_conf.safe_start = data[ind++];
		appconf.app_ppm_conf.rpm_lim_start = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.rpm_lim_end = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_ppm_conf.multi_esc = data[ind++];
		appconf.app_ppm_conf.tc = data[ind++];
		appconf.app_ppm_conf.tc_max_diff = buffer_get_float32(data, 1000.0, &ind);

		appconf.app_adc_conf.ctrl_type = (adc_control_type)data[ind++];
		appconf.app_adc_conf.hyst = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.voltage_start = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.voltage_end = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.use_filter = data[ind++];
		appconf.app_adc_conf.safe_start = data[ind++];
		appconf.app_adc_conf.cc_button_inverted = data[ind++];
		appconf.app_adc_conf.rev_button_inverted = data[ind++];
		appconf.app_adc_conf.voltage_inverted = data[ind++];
		appconf.app_adc_conf.rpm_lim_start = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.rpm_lim_end = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.multi_esc = data[ind++];
		appconf.app_adc_conf.tc = data[ind++];
		appconf.app_adc_conf.tc_max_diff = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_adc_conf.update_rate_hz = buffer_get_uint16(data, &ind);

		appconf.app_uart_baudrate = buffer_get_uint32(data, &ind);

		appconf.app_chuk_conf.ctrl_type = (chuk_control_type)data[ind++];
		appconf.app_chuk_conf.hyst = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.rpm_lim_start = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.rpm_lim_end = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.ramp_time_pos = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.ramp_time_neg = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.stick_erpm_per_s_in_cc = buffer_get_float32(data, 1000.0, &ind);
		appconf.app_chuk_conf.multi_esc = data[ind++];
		appconf.app_chuk_conf.tc = data[ind++];
		appconf.app_chuk_conf.tc_max_diff = buffer_get_float32(data, 1000.0, &ind);

		appconf.app_nrf_conf.speed = (NRF_SPEED)data[ind++];
		appconf.app_nrf_conf.power = (NRF_POWER)data[ind++];
		appconf.app_nrf_conf.crc_type = (NRF_CRC)data[ind++];
		appconf.app_nrf_conf.retry_delay = (NRF_RETR_DELAY)data[ind++];
		appconf.app_nrf_conf.retries = data[ind++];
		appconf.app_nrf_conf.channel = data[ind++];
		memcpy(appconf.app_nrf_conf.address, data + ind, 3);
		ind += 3;
		appconf.app_nrf_conf.send_crc_ack = data[ind++];

		if (rx_appconf_func) {
			rx_appconf_func(&appconf);
		}
		break;

	case COMM_DETECT_MOTOR_PARAM:
		ind = 0;
		detect_cycle_int_limit = buffer_get_float32(data, 1000.0, &ind);
		detect_coupling_k = buffer_get_float32(data, 1000.0, &ind);
		for (i = 0;i < 8;i++) {
			detect_hall_table[i] = (const signed char)(data[ind++]);
		}
		detect_hall_res = (const signed char)(data[ind++]);

		if (rx_detect_func) {
			rx_detect_func(detect_cycle_int_limit, detect_coupling_k,
					detect_hall_table, detect_hall_res);
		}
		break;

	case COMM_DETECT_MOTOR_R_L: {
		// TODO!
	} break;

	case COMM_DETECT_MOTOR_FLUX_LINKAGE: {
		// TODO!
	} break;

	case COMM_DETECT_ENCODER: {
		// TODO!
	} break;

	case COMM_DETECT_HALL_FOC: {
		// TODO!
	} break;

	case COMM_GET_DECODED_PPM:
		ind = 0;
		dec_ppm = buffer_get_float32(data, 1000000.0, &ind);
		dec_ppm_len = buffer_get_float32(data, 1000000.0, &ind);

		if (rx_dec_ppm_func) {
			rx_dec_ppm_func(dec_ppm, dec_ppm_len);
		}
		break;

	case COMM_GET_DECODED_ADC:
		ind = 0;
		dec_adc = buffer_get_float32(data, 1000000.0, &ind);
		dec_adc_voltage = buffer_get_float32(data, 1000000.0, &ind);
		// TODO for adc2

		if (rx_dec_adc_func) {
			rx_dec_adc_func(dec_adc, dec_adc_voltage);
		}
		break;

	case COMM_GET_DECODED_CHUK:
		ind = 0;
		dec_chuk = buffer_get_float32(data, 1000000.0, &ind);

		if (rx_dec_chuk_func) {
			rx_dec_chuk_func(dec_chuk);
		}
		break;

	case COMM_SET_MCCONF:
		// This is a confirmation that the new mcconf is received.
		if (rx_mcconf_received_func) {
			rx_mcconf_received_func();
		}
		break;

	case COMM_SET_APPCONF:
		// This is a confirmation that the new appconf is received.
		if (rx_appconf_received_func) {
			rx_appconf_received_func();
		}
		break;

	default:
		break;
	}
}

/**
 * Function pointer setters. When data that is requested with the get functions
 * is received, the corresponding function pointer will be called with the
 * received data.
 *
 * @param func
 * A function to be called when the corresponding data is received.
 */

void bldc_interface_set_rx_value_func(void(*func)(mc_values *values)) {
	rx_value_func = func;
}

void bldc_interface_set_rx_printf_func(void(*func)(char *str)) {
	rx_printf_func = func;
}

void bldc_interface_set_rx_fw_func(void(*func)(int major, int minor)) {
	rx_fw_func = func;
}

void bldc_interface_set_rx_rotor_pos_func(void(*func)(float pos)) {
	rx_rotor_pos_func = func;
}

void bldc_interface_set_rx_mcconf_func(void(*func)(mc_configuration *conf)) {
	rx_mcconf_func = func;
}

void bldc_interface_set_rx_appconf_func(void(*func)(app_configuration *conf)) {
	rx_appconf_func = func;
}

void bldc_interface_set_rx_detect_func(void(*func)(float cycle_int_limit, float coupling_k,
		const signed char *hall_table, signed char hall_res)) {
	rx_detect_func = func;
}

void bldc_interface_set_rx_dec_ppm_func(void(*func)(float val, float ms)) {
	rx_dec_ppm_func = func;
}

void bldc_interface_set_rx_dec_adc_func(void(*func)(float val, float voltage)) {
	rx_dec_adc_func = func;
}

void bldc_interface_set_rx_dec_chuk_func(void(*func)(float val)) {
	rx_dec_chuk_func = func;
}

void bldc_interface_set_rx_mcconf_received_func(void(*func)(void)) {
	rx_mcconf_received_func = func;
}

void bldc_interface_set_rx_appconf_received_func(void(*func)(void)) {
	rx_appconf_received_func = func;
}

// Setters
void bldc_interface_set_current(float current) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_SET_CURRENT;
	buffer_append_float32(send_buffer, current, 1000.0, &send_index);
	send_packet_no_fwd(send_buffer, send_index);
}


// Getters
void bldc_interface_get_fw_version(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_FW_VERSION;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_values(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_VALUES;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_mcconf(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_MCCONF;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_appconf(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_APPCONF;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_decoded_ppm(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_DECODED_PPM;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_decoded_adc(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_DECODED_ADC;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_get_decoded_chuk(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_GET_DECODED_CHUK;
	send_packet_no_fwd(send_buffer, send_index);
}

// Other functions
void bldc_interface_detect_motor_param(float current, float min_rpm, float low_duty) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_DETECT_MOTOR_PARAM;
	buffer_append_float32(send_buffer, current, 1000.0, &send_index);
	buffer_append_float32(send_buffer, min_rpm, 1000.0, &send_index);
	buffer_append_float32(send_buffer, low_duty, 1000.0, &send_index);
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_reboot(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_REBOOT;
	send_packet_no_fwd(send_buffer, send_index);
}

void bldc_interface_send_alive(void) {
	int32_t send_index = 0;
	fwd_can_append(send_buffer, &send_index);
	send_buffer[send_index++] = COMM_ALIVE;
	send_packet_no_fwd(send_buffer, send_index);
}

// Helpers
const char* bldc_interface_fault_to_string(mc_fault_code fault) {
	switch (fault) {
	case FAULT_CODE_NONE: return "FAULT_CODE_NONE";
	case FAULT_CODE_OVER_VOLTAGE: return "FAULT_CODE_OVER_VOLTAGE";
	case FAULT_CODE_UNDER_VOLTAGE: return "FAULT_CODE_UNDER_VOLTAGE";
	case FAULT_CODE_DRV8302: return "FAULT_CODE_DRV8302";
	case FAULT_CODE_ABS_OVER_CURRENT: return "FAULT_CODE_ABS_OVER_CURRENT";
	case FAULT_CODE_OVER_TEMP_FET: return "FAULT_CODE_OVER_TEMP_FET";
	case FAULT_CODE_OVER_TEMP_MOTOR: return "FAULT_CODE_OVER_TEMP_MOTOR";
	default: return "Unknown fault";
	}
}

// Private functions
void send_packet_no_fwd(unsigned char *data, unsigned int len) {
	if (!forward_func) {
		bldc_interface_send_packet(data, len);
	}
}

static void fwd_can_append(uint8_t *data, int32_t *ind) {
	if (can_fwd_vesc >= 0) {
		data[(*ind)++] = COMM_FORWARD_CAN;
		data[(*ind)++] = can_fwd_vesc;
	}
}
