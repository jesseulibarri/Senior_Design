/*
 * shell_elec_electric_vehicle.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "shell_elec_electric_vehicle".
 *
 * Model version              : 1.437
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Mar 13 20:25:58 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_shell_elec_electric_vehicle_h_
#define RTW_HEADER_shell_elec_electric_vehicle_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef shell_elec_electric_vehicle_COMMON_INCLUDES_
# define shell_elec_electric_vehicle_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "shell_elec_electric_vehicle_442b803b_1_gateway.h"
#endif                                 /* shell_elec_electric_vehicle_COMMON_INCLUDES_ */

#include "shell_elec_electric_vehicle_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FromWs[8];                    /* '<S4>/FromWs' */
  real_T DeadZone;                     /* '<S32>/Dead Zone' */
  real_T Sum;                          /* '<S33>/Sum' */
  real_T INPUT_5_1_1[4];               /* '<S46>/INPUT_5_1_1' */
  real_T UnitDelay;                    /* '<Root>/Unit Delay' */
  real_T INPUT_1_1_1[4];               /* '<S46>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S46>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S46>/INPUT_3_1_1' */
  real_T INPUT_4_1_1[4];               /* '<S46>/INPUT_4_1_1' */
  real_T STATE_1[274];                 /* '<S46>/STATE_1' */
  real_T In1;                          /* '<S51>/In1' */
  boolean_T Logic[2];                  /* '<S54>/Logic' */
} B_shell_elec_electric_vehicle_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T INPUT_5_1_1_discrete[2];      /* '<S46>/INPUT_5_1_1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T INPUT_1_1_1_discrete[2];      /* '<S46>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_discrete[2];      /* '<S46>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_discrete[2];      /* '<S46>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_discrete[2];      /* '<S46>/INPUT_4_1_1' */
  real_T STATE_1_DiscStates[130];      /* '<S46>/STATE_1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S53>/Discrete-Time Integrator' */
  real_T Memory_PreviousInput;         /* '<S33>/Memory' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  void* STATE_1_Simulator;             /* '<S46>/STATE_1' */
  void* STATE_1_SimulationData;        /* '<S46>/STATE_1' */
  void* STATE_1_DiagnosticManager;     /* '<S46>/STATE_1' */
  void* STATE_1_Logger;                /* '<S46>/STATE_1' */
  void* STATE_1_SampleTimeIdx;         /* '<S46>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S46>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimulationData;     /* '<S46>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagnosticManager;  /* '<S46>/OUTPUT_1_0' */
  void* OUTPUT_1_0_Logger;             /* '<S46>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SampleTimeIdx;      /* '<S46>/OUTPUT_1_0' */
  struct {
    void *LoggedData;
  } PowerkW_PWORK;                     /* '<S8>/Power (kW)' */

  struct {
    void *LoggedData;
  } TorqueNm_PWORK;                    /* '<S8>/Torque (Nm)' */

  struct {
    void *LoggedData;
  } BatteryvoltageV_PWORK;             /* '<S8>/Battery voltage (V)' */

  struct {
    void *LoggedData;
  } VehiclespeedMPH_PWORK;             /* '<S8>/Vehicle speed (MPH)' */

  struct {
    void *LoggedData;
  } MotortemperaturedegC_PWORK;        /* '<S8>/Motor temperature (deg C)' */

  void* SINK_1_Simulator;              /* '<S46>/SINK_1' */
  void* SINK_1_SimulationData;         /* '<S46>/SINK_1' */
  void* SINK_1_DiagnosticManager;      /* '<S46>/SINK_1' */
  void* SINK_1_Logger;                 /* '<S46>/SINK_1' */
  void* SINK_1_SampleTimeIdx;          /* '<S46>/SINK_1' */
  int32_T clockTickCounter;            /* '<S48>/Pulse Generator' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  int_T STATE_1_Modes[144];            /* '<S46>/STATE_1' */
  boolean_T STATE_1_CallSimulatorOutput;/* '<S46>/STATE_1' */
  boolean_T OUTPUT_1_0_CallSimulatorOutput;/* '<S46>/OUTPUT_1_0' */
  boolean_T TmpLatchAtJKFlipFlopInport1_Pre;/* synthesized block */
  boolean_T TmpLatchAtJKFlipFlopInport2_Pre;/* synthesized block */
  boolean_T SINK_1_CallSimulatorOutput;/* '<S46>/SINK_1' */
  boolean_T Memory_PreviousInput_n;    /* '<S54>/Memory' */
} DW_shell_elec_electric_vehicl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S52>/J-K Flip-Flop' */
  ZCSigState Capturespeed_Trig_ZCE;    /* '<S48>/Capture speed' */
} PrevZCX_shell_elec_electric_v_T;

/* Parameters (auto storage) */
struct P_shell_elec_electric_vehicle_T_ {
  real_T T_init;                       /* Variable: T_init
                                        * Referenced by: '<S46>/STATE_1'
                                        */
  real_T braking_torque_to_pedal_force_ratio;/* Variable: braking_torque_to_pedal_force_ratio
                                              * Referenced by:
                                              *   '<S32>/Torque per unit brake pedal force'
                                              *   '<S50>/Torque per unit brake pedal force'
                                              */
  real_T force_max_pedal;              /* Variable: force_max_pedal
                                        * Referenced by:
                                        *   '<S32>/Force for max pedal deflection'
                                        *   '<S50>/Force for max pedal deflection'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by:
                                        *   '<S32>/Dead Zone'
                                        *   '<S47>/1//ratio'
                                        *   '<S50>/1//ratio'
                                        */
  real_T gravity;                      /* Variable: gravity
                                        * Referenced by:
                                        *   '<S6>/g'
                                        *   '<S33>/ M*g '
                                        *   '<S33>/M*g'
                                        */
  real_T max_power;                    /* Variable: max_power
                                        * Referenced by: '<S11>/max_power'
                                        */
  real_T max_torque;                   /* Variable: max_torque
                                        * Referenced by:
                                        *   '<S11>/Torque limits'
                                        *   '<S32>/Dead Zone'
                                        *   '<S50>/Max torque demand'
                                        *   '<S50>/Only permit negative torque values'
                                        *   '<S53>/Discrete-Time Integrator'
                                        */
  real_T rolling_res_ratio;            /* Variable: rolling_res_ratio
                                        * Referenced by: '<S33>/Rolling resistance (fraction of normal force)'
                                        */
  real_T vehicle_mass;                 /* Variable: vehicle_mass
                                        * Referenced by:
                                        *   '<S33>/ M*g '
                                        *   '<S33>/M*g'
                                        *   '<S47>/ M '
                                        */
  real_T wheel_radius;                 /* Variable: wheel_radius
                                        * Referenced by: '<S47>/Wheel radius'
                                        */
  real_T Speedcontroller_Kp;           /* Mask Parameter: Speedcontroller_Kp
                                        * Referenced by: '<S53>/Kp'
                                        */
  real_T Onlypermitnegativetorquevalues_;/* Expression: -10
                                          * Referenced by: '<S50>/Only permit negative torque values'
                                          */
  real_T Onlyuseforwardbraking_Threshold;/* Expression: 0.5
                                          * Referenced by: '<S50>/Only use forward braking'
                                          */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Convertdegreestoradians_Gain; /* Expression: pi/180
                                        * Referenced by: '<S33>/Convert degrees to radians'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S33>/Memory'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T GAIN_Gain;                    /* Expression: pm_unit('m/s', 'mph', 'linear')
                                        * Referenced by: '<S44>/GAIN'
                                        */
  real_T CONSTANT_Value;               /* Expression: pm_unit('K', 'degC', 'offset')
                                        * Referenced by: '<S26>/CONSTANT'
                                        */
  real_T d2r_Gain;                     /* Expression: pi/180
                                        * Referenced by: '<S6>/d2r'
                                        */
  real_T Preventdividebyzero_Threshold;/* Expression: 1
                                        * Referenced by: '<S11>/Prevent divide by zero'
                                        */
  real_T u_Gain;                       /* Expression: -1
                                        * Referenced by: '<S11>/-1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S53>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S53>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Mechanical_Gain;              /* Expression: 1e-3
                                        * Referenced by: '<S8>/Mechanical'
                                        */
  real_T Electrical_Gain;              /* Expression: 1e-3
                                        * Referenced by: '<S8>/ Electrical '
                                        */
  boolean_T Q_Y0;                      /* Expression: initial_condition
                                        * Referenced by: '<S54>/Q'
                                        */
  boolean_T Q_Y0_j;                    /* Expression: ~initial_condition
                                        * Referenced by: '<S54>/!Q'
                                        */
  boolean_T Memory_X0_f;               /* Expression: initial_condition
                                        * Referenced by: '<S54>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S54>/Logic'
                                        */
  boolean_T TmpLatchAtJKFlipFlopInport1_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                            * Referenced by: synthesized block
                                            */
  boolean_T TmpLatchAtJKFlipFlopInport2_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                            * Referenced by: synthesized block
                                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_shell_elec_electric_v_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_shell_elec_electric_vehicle_T shell_elec_electric_vehicle_P;

/* Block signals (auto storage) */
extern B_shell_elec_electric_vehicle_T shell_elec_electric_vehicle_B;

/* Block states (auto storage) */
extern DW_shell_elec_electric_vehicl_T shell_elec_electric_vehicle_DW;

/* Model entry point functions */
extern void shell_elec_electric_vehicle_initialize(void);
extern void shell_elec_electric_vehicle_step(void);
extern void shell_elec_electric_vehicle_terminate(void);

/* Real-time Model object */
extern RT_MODEL_shell_elec_electric__T *const shell_elec_electric_vehicle_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'shell_elec_electric_vehicle'
 * '<S1>'   : 'shell_elec_electric_vehicle/Battery'
 * '<S2>'   : 'shell_elec_electric_vehicle/Cooling system'
 * '<S3>'   : 'shell_elec_electric_vehicle/DC-DC converter (averaged)'
 * '<S4>'   : 'shell_elec_electric_vehicle/Drive cycles & HIL inputs'
 * '<S5>'   : 'shell_elec_electric_vehicle/Energy-based PMSM drive model'
 * '<S6>'   : 'shell_elec_electric_vehicle/Inclinometer'
 * '<S7>'   : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics'
 * '<S8>'   : 'shell_elec_electric_vehicle/Scopes & HIL outputs'
 * '<S9>'   : 'shell_elec_electric_vehicle/Simulink-PS Converter1'
 * '<S10>'  : 'shell_elec_electric_vehicle/Solver Configuration'
 * '<S11>'  : 'shell_elec_electric_vehicle/Vehicle control system'
 * '<S12>'  : 'shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells'
 * '<S13>'  : 'shell_elec_electric_vehicle/Battery/Thermal Model'
 * '<S14>'  : 'shell_elec_electric_vehicle/Cooling system/Expansion tank'
 * '<S15>'  : 'shell_elec_electric_vehicle/Cooling system/Radiator'
 * '<S16>'  : 'shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors'
 * '<S17>'  : 'shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/PS-Simulink Converter'
 * '<S18>'  : 'shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/PS-Simulink Converter1'
 * '<S19>'  : 'shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/PS-Simulink Converter/EVAL_KEY'
 * '<S20>'  : 'shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/PS-Simulink Converter1/EVAL_KEY'
 * '<S21>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger'
 * '<S22>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/PS-Simulink Converter'
 * '<S23>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Simulink-PS G1'
 * '<S24>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor'
 * '<S25>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS-Simulink Converter'
 * '<S26>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS-Simulink Converter/EVAL_KEY'
 * '<S27>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/PS-Simulink Converter/EVAL_KEY'
 * '<S28>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Simulink-PS G1/EVAL_KEY'
 * '<S29>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/PS-Simulink Converter2'
 * '<S30>'  : 'shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/PS-Simulink Converter2/EVAL_KEY'
 * '<S31>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag'
 * '<S32>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque'
 * '<S33>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Gravitational & rolling forces'
 * '<S34>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement'
 * '<S35>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/Simulink-PS Converter2'
 * '<S36>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)'
 * '<S37>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/Simulink-PS Converter2/EVAL_KEY'
 * '<S38>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Simulink-PS Converter1'
 * '<S39>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)'
 * '<S40>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Simulink-PS Converter1/EVAL_KEY'
 * '<S41>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Gravitational & rolling forces/Simulink-PS Converter1'
 * '<S42>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Gravitational & rolling forces/Simulink-PS Converter1/EVAL_KEY'
 * '<S43>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/PS-Simulink Converter3'
 * '<S44>'  : 'shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/PS-Simulink Converter3/EVAL_KEY'
 * '<S45>'  : 'shell_elec_electric_vehicle/Simulink-PS Converter1/EVAL_KEY'
 * '<S46>'  : 'shell_elec_electric_vehicle/Solver Configuration/EVAL_KEY'
 * '<S47>'  : 'shell_elec_electric_vehicle/Vehicle control system/Add feedforward term to counter effect of gravity when on an incline. Results in regenerative braking when moving downhill.'
 * '<S48>'  : 'shell_elec_electric_vehicle/Vehicle control system/Cruise control'
 * '<S49>'  : 'shell_elec_electric_vehicle/Vehicle control system/Power limits'
 * '<S50>'  : 'shell_elec_electric_vehicle/Vehicle control system/Torque demand management'
 * '<S51>'  : 'shell_elec_electric_vehicle/Vehicle control system/Cruise control/Capture speed'
 * '<S52>'  : 'shell_elec_electric_vehicle/Vehicle control system/Cruise control/J-K Flip-Flop'
 * '<S53>'  : 'shell_elec_electric_vehicle/Vehicle control system/Cruise control/Speed controller'
 * '<S54>'  : 'shell_elec_electric_vehicle/Vehicle control system/Cruise control/J-K Flip-Flop/J-K Flip-Flop'
 */
#endif                                 /* RTW_HEADER_shell_elec_electric_vehicle_h_ */
