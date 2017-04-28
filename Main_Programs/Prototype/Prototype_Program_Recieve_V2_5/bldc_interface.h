#ifndef BLDC_INTERFACE_H_
#define BLDC_INTERFACE_H_

#include "datatypes.h"

// interface functions
void bldc_interface_init(void(*func)(unsigned char *data, unsigned int len));
void bldc_interface_set_forward_can(int32_t vesc_id);
void bldc_interface_set_forward_func(void(*func)(unsigned char *data, unsigned int len));
void bldc_interface_send_packet(unsigned char *data, unsigned int len);
void bldc_interface_process_packet(unsigned char *data, unsigned int len);

// Function pointer setters
void bldc_interface_set_rx_value_func(void(*func)(mc_values *values));
void bldc_interface_set_rx_printf_func(void(*func)(char *str));
void bldc_interface_set_rx_fw_func(void(*func)(int major, int minor));
void bldc_interface_set_rx_rotor_pos_func(void(*func)(float pos));
void bldc_interface_set_rx_mcconf_func(void(*func)(mc_configuration *conf));
void bldc_interface_set_rx_appconf_func(void(*func)(app_configuration *conf));
void bldc_interface_set_rx_detect_func(void(*func)(float cycle_int_limit, float coupling_k,
		const signed char *hall_table, signed char hall_res));
void bldc_interface_set_rx_dec_ppm_func(void(*func)(float val, float ms));
void bldc_interface_set_rx_dec_adc_func(void(*func)(float val, float voltage));
void bldc_interface_set_rx_dec_chuk_func(void(*func)(float val));
void bldc_interface_set_rx_mcconf_received_func(void(*func)(void));
void bldc_interface_set_rx_appconf_received_func(void(*func)(void));

// Setters
void bldc_interface_set_current(float current);

// Getters
void bldc_interface_get_fw_version(void);
void bldc_interface_get_values(void);
void bldc_interface_get_mcconf(void);
void bldc_interface_get_appconf(void);
void bldc_interface_get_decoded_ppm(void);
void bldc_interface_get_decoded_adc(void);
void bldc_interface_get_decoded_chuk(void);

// Other functions
void bldc_interface_detect_motor_param(float current, float min_rpm, float low_duty);
void bldc_interface_reboot(void);
void bldc_interface_send_alive(void);

// Helpers
const char* bldc_interface_fault_to_string(mc_fault_code fault);

#endif /* BLDC_INTERFACE_H_ */
