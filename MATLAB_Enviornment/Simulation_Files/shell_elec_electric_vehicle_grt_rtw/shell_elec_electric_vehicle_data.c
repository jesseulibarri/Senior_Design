/*
 * shell_elec_electric_vehicle_data.c
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

#include "shell_elec_electric_vehicle.h"
#include "shell_elec_electric_vehicle_private.h"

/* Block parameters (auto storage) */
P_shell_elec_electric_vehicle_T shell_elec_electric_vehicle_P = {
  293.15,                              /* Variable: T_init
                                        * Referenced by: '<S46>/STATE_1'
                                        */
  -4.0,                                /* Variable: braking_torque_to_pedal_force_ratio
                                        * Referenced by:
                                        *   '<S32>/Torque per unit brake pedal force'
                                        *   '<S50>/Torque per unit brake pedal force'
                                        */
  500.0,                               /* Variable: force_max_pedal
                                        * Referenced by:
                                        *   '<S32>/Force for max pedal deflection'
                                        *   '<S50>/Force for max pedal deflection'
                                        */
  6.0,                                 /* Variable: gear_ratio
                                        * Referenced by:
                                        *   '<S32>/Dead Zone'
                                        *   '<S47>/1//ratio'
                                        *   '<S50>/1//ratio'
                                        */
  9.81,                                /* Variable: gravity
                                        * Referenced by:
                                        *   '<S6>/g'
                                        *   '<S33>/ M*g '
                                        *   '<S33>/M*g'
                                        */
  50000.0,                             /* Variable: max_power
                                        * Referenced by: '<S11>/max_power'
                                        */
  220.0,                               /* Variable: max_torque
                                        * Referenced by:
                                        *   '<S11>/Torque limits'
                                        *   '<S32>/Dead Zone'
                                        *   '<S50>/Max torque demand'
                                        *   '<S50>/Only permit negative torque values'
                                        *   '<S53>/Discrete-Time Integrator'
                                        */
  0.015,                               /* Variable: rolling_res_ratio
                                        * Referenced by: '<S33>/Rolling resistance (fraction of normal force)'
                                        */
  1000.0,                              /* Variable: vehicle_mass
                                        * Referenced by:
                                        *   '<S33>/ M*g '
                                        *   '<S33>/M*g'
                                        *   '<S47>/ M '
                                        */
  0.25,                                /* Variable: wheel_radius
                                        * Referenced by: '<S47>/Wheel radius'
                                        */
  100.0,                               /* Mask Parameter: Speedcontroller_Kp
                                        * Referenced by: '<S53>/Kp'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S50>/Only permit negative torque values'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S50>/Only use forward braking'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S33>/Convert degrees to radians'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  2.2369362920544025,                  /* Expression: pm_unit('m/s', 'mph', 'linear')
                                        * Referenced by: '<S44>/GAIN'
                                        */
  -273.15,                             /* Expression: pm_unit('K', 'degC', 'offset')
                                        * Referenced by: '<S26>/CONSTANT'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S6>/d2r'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Prevent divide by zero'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S11>/-1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S53>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S50>/Constant'
                                        */
  0.001,                               /* Expression: 1e-3
                                        * Referenced by: '<S8>/Mechanical'
                                        */
  0.001,                               /* Expression: 1e-3
                                        * Referenced by: '<S8>/ Electrical '
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S54>/Q'
                                        */
  1,                                   /* Expression: ~initial_condition
                                        * Referenced by: '<S54>/!Q'
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S54>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S54>/Logic'
   */
  { 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
  0,                                   /* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                        * Referenced by: synthesized block
                                        */
  0                                    /* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                        * Referenced by: synthesized block
                                        */
};
