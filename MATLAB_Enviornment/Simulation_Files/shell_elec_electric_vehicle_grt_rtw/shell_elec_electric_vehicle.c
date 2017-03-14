/*
 * shell_elec_electric_vehicle.c
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

/* Block signals (auto storage) */
B_shell_elec_electric_vehicle_T shell_elec_electric_vehicle_B;

/* Block states (auto storage) */
DW_shell_elec_electric_vehicl_T shell_elec_electric_vehicle_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_shell_elec_electric_v_T shell_elec_electric_veh_PrevZCX;

/* Real-time model */
RT_MODEL_shell_elec_electric__T shell_elec_electric_vehicle_M_;
RT_MODEL_shell_elec_electric__T *const shell_elec_electric_vehicle_M =
  &shell_elec_electric_vehicle_M_;

/* Model step function */
void shell_elec_electric_vehicle_step(void)
{
  /* local block i/o variables */
  real_T rtb_GAIN;
  real_T rtb_OUTPUT_1_0[6];
  real_T rtb_Electrical;
  real_T rtb_Mechanical;
  real_T rtb_SUM;
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[20];
  int_T tmp_1[6];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T time_0;
  real_T tmp_2[294];
  int_T tmp_3[7];
  int32_T rowIdx;
  real_T time_1;
  real_T tmp_4[20];
  int_T tmp_5[6];
  real_T rtb_ZOH4;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_DataTypeConversion1;
  real_T rtb_Product;
  ZCEventType zcEvent;
  real_T rtb_PulseGenerator;
  real_T rtb_TrigonometricFunction1;
  real_T rtb_TrigonometricFunction;

  /* FromWorkspace: '<S4>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      shell_elec_electric_vehicle_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      shell_elec_electric_vehicle_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = shell_elec_electric_vehicle_DW.FromWs_IWORK.PrevIndex;
    real_T t = shell_elec_electric_vehicle_M->Timing.taskTime0;

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[16]) {
      currTimeIndex = 15;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    shell_elec_electric_vehicle_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 8; ++elIdx) {
              (&shell_elec_electric_vehicle_B.FromWs[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 17;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 8; ++elIdx) {
              (&shell_elec_electric_vehicle_B.FromWs[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 17;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 8; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&shell_elec_electric_vehicle_B.FromWs[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 17;
          }
        }
      }
    }
  }

  /* Gain: '<S32>/Torque per unit brake pedal force' incorporates:
   *  Gain: '<S32>/Force for max pedal deflection'
   */
  rtb_SUM = shell_elec_electric_vehicle_P.force_max_pedal *
    shell_elec_electric_vehicle_B.FromWs[2] *
    shell_elec_electric_vehicle_P.braking_torque_to_pedal_force_ratio;

  /* DeadZone: '<S32>/Dead Zone' */
  if (rtb_SUM > shell_elec_electric_vehicle_P.max_torque *
      shell_elec_electric_vehicle_P.gear_ratio) {
    shell_elec_electric_vehicle_B.DeadZone = rtb_SUM -
      shell_elec_electric_vehicle_P.max_torque *
      shell_elec_electric_vehicle_P.gear_ratio;
  } else if (rtb_SUM >= -shell_elec_electric_vehicle_P.max_torque *
             shell_elec_electric_vehicle_P.gear_ratio) {
    shell_elec_electric_vehicle_B.DeadZone = 0.0;
  } else {
    shell_elec_electric_vehicle_B.DeadZone = rtb_SUM -
      -shell_elec_electric_vehicle_P.max_torque *
      shell_elec_electric_vehicle_P.gear_ratio;
  }

  /* End of DeadZone: '<S32>/Dead Zone' */

  /* Gain: '<S33>/Convert degrees to radians' */
  rtb_SUM = shell_elec_electric_vehicle_P.Convertdegreestoradians_Gain *
    shell_elec_electric_vehicle_B.FromWs[0];

  /* Trigonometry: '<S33>/Trigonometric Function' */
  rtb_TrigonometricFunction = sin(rtb_SUM);

  /* Trigonometry: '<S33>/Trigonometric Function1' */
  rtb_TrigonometricFunction1 = cos(rtb_SUM);

  /* Memory: '<S33>/Memory' */
  rtb_SUM = shell_elec_electric_vehicle_DW.Memory_PreviousInput;

  /* Sum: '<S33>/Sum' incorporates:
   *  Gain: '<S33>/ M*g '
   *  Gain: '<S33>/M*g'
   *  Gain: '<S33>/Rolling resistance (fraction of normal force)'
   *  Product: '<S33>/Sign and ensure zero for zero speed'
   *  Trigonometry: '<S33>/Trigonometric Function2'
   */
  shell_elec_electric_vehicle_B.Sum = (0.0 -
    shell_elec_electric_vehicle_P.vehicle_mass *
    shell_elec_electric_vehicle_P.gravity * rtb_TrigonometricFunction) -
    shell_elec_electric_vehicle_P.vehicle_mass *
    shell_elec_electric_vehicle_P.gravity * rtb_TrigonometricFunction1 *
    shell_elec_electric_vehicle_P.rolling_res_ratio * tanh(rtb_SUM);

  /* SimscapeInputBlock: '<S46>/INPUT_5_1_1' */
  shell_elec_electric_vehicle_B.INPUT_5_1_1[0] =
    shell_elec_electric_vehicle_B.FromWs[7] + 273.15;
  shell_elec_electric_vehicle_B.INPUT_5_1_1[1] = 0.0;
  shell_elec_electric_vehicle_B.INPUT_5_1_1[2] = 0.0;
  shell_elec_electric_vehicle_DW.INPUT_5_1_1_discrete[0] =
    !(shell_elec_electric_vehicle_B.INPUT_5_1_1[0] ==
      shell_elec_electric_vehicle_DW.INPUT_5_1_1_discrete[1]);
  shell_elec_electric_vehicle_DW.INPUT_5_1_1_discrete[1] =
    shell_elec_electric_vehicle_B.INPUT_5_1_1[0];
  shell_elec_electric_vehicle_B.INPUT_5_1_1[3] =
    shell_elec_electric_vehicle_DW.INPUT_5_1_1_discrete[0];

  /* UnitDelay: '<Root>/Unit Delay' */
  shell_elec_electric_vehicle_B.UnitDelay =
    shell_elec_electric_vehicle_DW.UnitDelay_DSTATE;

  /* SimscapeInputBlock: '<S46>/INPUT_1_1_1' */
  shell_elec_electric_vehicle_B.INPUT_1_1_1[0] =
    shell_elec_electric_vehicle_B.UnitDelay;
  shell_elec_electric_vehicle_B.INPUT_1_1_1[1] = 0.0;
  shell_elec_electric_vehicle_B.INPUT_1_1_1[2] = 0.0;
  shell_elec_electric_vehicle_DW.INPUT_1_1_1_discrete[0] =
    !(shell_elec_electric_vehicle_B.INPUT_1_1_1[0] ==
      shell_elec_electric_vehicle_DW.INPUT_1_1_1_discrete[1]);
  shell_elec_electric_vehicle_DW.INPUT_1_1_1_discrete[1] =
    shell_elec_electric_vehicle_B.INPUT_1_1_1[0];
  shell_elec_electric_vehicle_B.INPUT_1_1_1[3] =
    shell_elec_electric_vehicle_DW.INPUT_1_1_1_discrete[0];

  /* SimscapeInputBlock: '<S46>/INPUT_2_1_1' */
  shell_elec_electric_vehicle_B.INPUT_2_1_1[0] =
    shell_elec_electric_vehicle_B.FromWs[1];
  shell_elec_electric_vehicle_B.INPUT_2_1_1[1] = 0.0;
  shell_elec_electric_vehicle_B.INPUT_2_1_1[2] = 0.0;
  shell_elec_electric_vehicle_DW.INPUT_2_1_1_discrete[0] =
    !(shell_elec_electric_vehicle_B.INPUT_2_1_1[0] ==
      shell_elec_electric_vehicle_DW.INPUT_2_1_1_discrete[1]);
  shell_elec_electric_vehicle_DW.INPUT_2_1_1_discrete[1] =
    shell_elec_electric_vehicle_B.INPUT_2_1_1[0];
  shell_elec_electric_vehicle_B.INPUT_2_1_1[3] =
    shell_elec_electric_vehicle_DW.INPUT_2_1_1_discrete[0];

  /* SimscapeInputBlock: '<S46>/INPUT_3_1_1' */
  shell_elec_electric_vehicle_B.INPUT_3_1_1[0] =
    shell_elec_electric_vehicle_B.DeadZone;
  shell_elec_electric_vehicle_B.INPUT_3_1_1[1] = 0.0;
  shell_elec_electric_vehicle_B.INPUT_3_1_1[2] = 0.0;
  shell_elec_electric_vehicle_DW.INPUT_3_1_1_discrete[0] =
    !(shell_elec_electric_vehicle_B.INPUT_3_1_1[0] ==
      shell_elec_electric_vehicle_DW.INPUT_3_1_1_discrete[1]);
  shell_elec_electric_vehicle_DW.INPUT_3_1_1_discrete[1] =
    shell_elec_electric_vehicle_B.INPUT_3_1_1[0];
  shell_elec_electric_vehicle_B.INPUT_3_1_1[3] =
    shell_elec_electric_vehicle_DW.INPUT_3_1_1_discrete[0];

  /* SimscapeInputBlock: '<S46>/INPUT_4_1_1' */
  shell_elec_electric_vehicle_B.INPUT_4_1_1[0] =
    shell_elec_electric_vehicle_B.Sum;
  shell_elec_electric_vehicle_B.INPUT_4_1_1[1] = 0.0;
  shell_elec_electric_vehicle_B.INPUT_4_1_1[2] = 0.0;
  shell_elec_electric_vehicle_DW.INPUT_4_1_1_discrete[0] =
    !(shell_elec_electric_vehicle_B.INPUT_4_1_1[0] ==
      shell_elec_electric_vehicle_DW.INPUT_4_1_1_discrete[1]);
  shell_elec_electric_vehicle_DW.INPUT_4_1_1_discrete[1] =
    shell_elec_electric_vehicle_B.INPUT_4_1_1[0];
  shell_elec_electric_vehicle_B.INPUT_4_1_1[3] =
    shell_elec_electric_vehicle_DW.INPUT_4_1_1_discrete[0];

  /* SimscapeExecutionBlock: '<S46>/STATE_1' */
  simulationData = (NeslSimulationData *)
    shell_elec_electric_vehicle_DW.STATE_1_SimulationData;
  time = shell_elec_electric_vehicle_M->Timing.taskTime0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 130;
  simulationData->mData->mDiscStates.mX = (real_T *)
    &shell_elec_electric_vehicle_DW.STATE_1_DiscStates;
  simulationData->mData->mModeVector.mN = 144;
  simulationData->mData->mModeVector.mX = (int32_T *)
    &shell_elec_electric_vehicle_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = shell_elec_electric_vehicle_B.INPUT_5_1_1[0];
  tmp_0[1] = shell_elec_electric_vehicle_B.INPUT_5_1_1[1];
  tmp_0[2] = shell_elec_electric_vehicle_B.INPUT_5_1_1[2];
  tmp_0[3] = shell_elec_electric_vehicle_B.INPUT_5_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = shell_elec_electric_vehicle_B.INPUT_1_1_1[0];
  tmp_0[5] = shell_elec_electric_vehicle_B.INPUT_1_1_1[1];
  tmp_0[6] = shell_elec_electric_vehicle_B.INPUT_1_1_1[2];
  tmp_0[7] = shell_elec_electric_vehicle_B.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = shell_elec_electric_vehicle_B.INPUT_2_1_1[0];
  tmp_0[9] = shell_elec_electric_vehicle_B.INPUT_2_1_1[1];
  tmp_0[10] = shell_elec_electric_vehicle_B.INPUT_2_1_1[2];
  tmp_0[11] = shell_elec_electric_vehicle_B.INPUT_2_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = shell_elec_electric_vehicle_B.INPUT_3_1_1[0];
  tmp_0[13] = shell_elec_electric_vehicle_B.INPUT_3_1_1[1];
  tmp_0[14] = shell_elec_electric_vehicle_B.INPUT_3_1_1[2];
  tmp_0[15] = shell_elec_electric_vehicle_B.INPUT_3_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = shell_elec_electric_vehicle_B.INPUT_4_1_1[0];
  tmp_0[17] = shell_elec_electric_vehicle_B.INPUT_4_1_1[1];
  tmp_0[18] = shell_elec_electric_vehicle_B.INPUT_4_1_1[2];
  tmp_0[19] = shell_elec_electric_vehicle_B.INPUT_4_1_1[3];
  tmp_1[5] = 20;
  simulationData->mData->mInputValues.mN = 20;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 6;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mOutputs.mN = 274;
  simulationData->mData->mOutputs.mX = &shell_elec_electric_vehicle_B.STATE_1[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  tmp = 1;
  simulationData->mData->mIsFundamentalSampleHit = tmp;
  diagnosticManager = (NeuDiagnosticManager *)
    shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)
    shell_elec_electric_vehicle_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS,
    simulationData, diagnosticManager);
  if (rowIdx != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(shell_elec_electric_vehicle_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S46>/STATE_1' */

  /* SimscapeExecutionBlock: '<S46>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_SimulationData;
  time_0 = shell_elec_electric_vehicle_M->Timing.taskTime0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_3[0] = 0;
  tmp_2[0] = shell_elec_electric_vehicle_B.INPUT_5_1_1[0];
  tmp_2[1] = shell_elec_electric_vehicle_B.INPUT_5_1_1[1];
  tmp_2[2] = shell_elec_electric_vehicle_B.INPUT_5_1_1[2];
  tmp_2[3] = shell_elec_electric_vehicle_B.INPUT_5_1_1[3];
  tmp_3[1] = 4;
  tmp_2[4] = shell_elec_electric_vehicle_B.INPUT_1_1_1[0];
  tmp_2[5] = shell_elec_electric_vehicle_B.INPUT_1_1_1[1];
  tmp_2[6] = shell_elec_electric_vehicle_B.INPUT_1_1_1[2];
  tmp_2[7] = shell_elec_electric_vehicle_B.INPUT_1_1_1[3];
  tmp_3[2] = 8;
  tmp_2[8] = shell_elec_electric_vehicle_B.INPUT_2_1_1[0];
  tmp_2[9] = shell_elec_electric_vehicle_B.INPUT_2_1_1[1];
  tmp_2[10] = shell_elec_electric_vehicle_B.INPUT_2_1_1[2];
  tmp_2[11] = shell_elec_electric_vehicle_B.INPUT_2_1_1[3];
  tmp_3[3] = 12;
  tmp_2[12] = shell_elec_electric_vehicle_B.INPUT_3_1_1[0];
  tmp_2[13] = shell_elec_electric_vehicle_B.INPUT_3_1_1[1];
  tmp_2[14] = shell_elec_electric_vehicle_B.INPUT_3_1_1[2];
  tmp_2[15] = shell_elec_electric_vehicle_B.INPUT_3_1_1[3];
  tmp_3[4] = 16;
  tmp_2[16] = shell_elec_electric_vehicle_B.INPUT_4_1_1[0];
  tmp_2[17] = shell_elec_electric_vehicle_B.INPUT_4_1_1[1];
  tmp_2[18] = shell_elec_electric_vehicle_B.INPUT_4_1_1[2];
  tmp_2[19] = shell_elec_electric_vehicle_B.INPUT_4_1_1[3];
  tmp_3[5] = 20;
  memcpy(&tmp_2[20], &shell_elec_electric_vehicle_B.STATE_1[0], 274U * sizeof
         (real_T));
  tmp_3[6] = 294;
  simulationData->mData->mInputValues.mN = 294;
  simulationData->mData->mInputValues.mX = &tmp_2[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_3[0];
  simulationData->mData->mOutputs.mN = 6;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  tmp = 1;
  simulationData->mData->mIsFundamentalSampleHit = tmp;
  diagnosticManager = (NeuDiagnosticManager *)
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
    simulationData, diagnosticManager);
  if (rowIdx != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(shell_elec_electric_vehicle_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S46>/OUTPUT_1_0' */

  /* Gain: '<S44>/GAIN' */
  rtb_GAIN = shell_elec_electric_vehicle_P.GAIN_Gain * rtb_OUTPUT_1_0[5];

  /* Sum: '<S26>/SUM' incorporates:
   *  Constant: '<S26>/CONSTANT'
   */
  rtb_SUM = rtb_OUTPUT_1_0[2] + shell_elec_electric_vehicle_P.CONSTANT_Value;

  /* ZeroOrderHold: '<Root>/ZOH//4' */
  rtb_ZOH4 = rtb_OUTPUT_1_0[3];

  /* Abs: '<S11>/Abs' */
  rtb_TrigonometricFunction = fabs(rtb_ZOH4);

  /* Switch: '<S11>/Prevent divide by zero' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (!(rtb_TrigonometricFunction >
        shell_elec_electric_vehicle_P.Preventdividebyzero_Threshold)) {
    rtb_TrigonometricFunction = shell_elec_electric_vehicle_P.Constant_Value;
  }

  /* End of Switch: '<S11>/Prevent divide by zero' */

  /* Gain: '<S11>/max_power' incorporates:
   *  Math: '<S11>/Math Function'
   *
   * About '<S11>/Math Function':
   *  Operator: reciprocal
   */
  rtb_TrigonometricFunction = 1.0 / rtb_TrigonometricFunction *
    shell_elec_electric_vehicle_P.max_power;

  /* Gain: '<S11>/-1' */
  rtb_TrigonometricFunction1 = shell_elec_electric_vehicle_P.u_Gain *
    rtb_TrigonometricFunction;

  /* DiscretePulseGenerator: '<S48>/Pulse Generator' */
  rtb_PulseGenerator = (shell_elec_electric_vehicle_DW.clockTickCounter <
                        shell_elec_electric_vehicle_P.PulseGenerator_Duty) &&
    (shell_elec_electric_vehicle_DW.clockTickCounter >= 0) ?
    shell_elec_electric_vehicle_P.PulseGenerator_Amp : 0.0;
  if (shell_elec_electric_vehicle_DW.clockTickCounter >=
      shell_elec_electric_vehicle_P.PulseGenerator_Period - 1.0) {
    shell_elec_electric_vehicle_DW.clockTickCounter = 0;
  } else {
    shell_elec_electric_vehicle_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S48>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S52>/J-K Flip-Flop' incorporates:
   *  TriggerPort: '<S54>/Trigger'
   */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &shell_elec_electric_veh_PrevZCX.JKFlipFlop_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* CombinatorialLogic: '<S54>/Logic' incorporates:
     *  Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport1'
     *  Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport2'
     *  Memory: '<S54>/Memory'
     */
    rowIdx = (int32_T)(((((uint32_T)
                          shell_elec_electric_vehicle_DW.Memory_PreviousInput_n <<
                          1) +
                         shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport1_Pre)
                        << 1) +
                       shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport2_Pre);
    shell_elec_electric_vehicle_B.Logic[0U] =
      shell_elec_electric_vehicle_P.Logic_table[(uint32_T)rowIdx];
    shell_elec_electric_vehicle_B.Logic[1U] =
      shell_elec_electric_vehicle_P.Logic_table[rowIdx + 8U];

    /* Update for Memory: '<S54>/Memory' */
    shell_elec_electric_vehicle_DW.Memory_PreviousInput_n =
      shell_elec_electric_vehicle_B.Logic[0];
  }

  /* End of Outputs for SubSystem: '<S52>/J-K Flip-Flop' */

  /* Outputs for Triggered SubSystem: '<S48>/Capture speed' incorporates:
   *  TriggerPort: '<S51>/Trigger'
   */
  if (shell_elec_electric_vehicle_B.Logic[0] &&
      (shell_elec_electric_veh_PrevZCX.Capturespeed_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S51>/In1' */
    shell_elec_electric_vehicle_B.In1 = rtb_ZOH4;
  }

  shell_elec_electric_veh_PrevZCX.Capturespeed_Trig_ZCE =
    shell_elec_electric_vehicle_B.Logic[0];

  /* End of Outputs for SubSystem: '<S48>/Capture speed' */

  /* ZeroOrderHold: '<Root>/ZOH//3' */
  rtb_Electrical = shell_elec_electric_vehicle_B.FromWs[5];

  /* DataTypeConversion: '<S48>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (rtb_Electrical != 0.0);

  /* ZeroOrderHold: '<Root>/ZOH//7' */
  rtb_Electrical = shell_elec_electric_vehicle_B.FromWs[6];

  /* ZeroOrderHold: '<Root>/ZOH//1' */
  rtb_Mechanical = shell_elec_electric_vehicle_B.FromWs[4];

  /* Logic: '<S48>/Logical Operator' */
  rtb_LogicalOperator = ((rtb_Electrical != 0.0) || (rtb_Mechanical != 0.0));

  /* Sum: '<S53>/Add' */
  rtb_PulseGenerator = shell_elec_electric_vehicle_B.In1 - rtb_ZOH4;

  /* Switch: '<S11>/Switch between torque control and speed control' incorporates:
   *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator'
   *  Gain: '<S47>/ M '
   *  Gain: '<S47>/1//ratio'
   *  Gain: '<S47>/Wheel radius'
   *  Gain: '<S50>/Max torque demand'
   *  Gain: '<S53>/Kp'
   *  Gain: '<S6>/d2r'
   *  Gain: '<S6>/g'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S53>/Add1'
   *  Switch: '<S50>/Only use forward braking'
   *  Trigonometry: '<S6>/Trigonometric Function'
   *  ZeroOrderHold: '<Root>/ZOH//2'
   */
  if (shell_elec_electric_vehicle_B.Logic[0]) {
    rtb_Mechanical = shell_elec_electric_vehicle_P.Speedcontroller_Kp *
      rtb_PulseGenerator +
      shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    if (rtb_ZOH4 >=
        shell_elec_electric_vehicle_P.Onlyuseforwardbraking_Threshold) {
      /* Gain: '<S50>/1//ratio' incorporates:
       *  Gain: '<S50>/Force for max pedal deflection'
       *  Gain: '<S50>/Torque per unit brake pedal force'
       *  Switch: '<S50>/Only use forward braking'
       *  ZeroOrderHold: '<Root>/ZOH//5'
       */
      rtb_ZOH4 = shell_elec_electric_vehicle_P.force_max_pedal *
        shell_elec_electric_vehicle_B.FromWs[2] *
        shell_elec_electric_vehicle_P.braking_torque_to_pedal_force_ratio * (1.0
        / shell_elec_electric_vehicle_P.gear_ratio);

      /* Saturate: '<S50>/Only permit negative torque values' incorporates:
       *  Switch: '<S50>/Only use forward braking'
       */
      if (rtb_ZOH4 >
          shell_elec_electric_vehicle_P.Onlypermitnegativetorquevalues_) {
        rtb_ZOH4 = shell_elec_electric_vehicle_P.Onlypermitnegativetorquevalues_;
      } else {
        if (rtb_ZOH4 < -shell_elec_electric_vehicle_P.max_torque) {
          rtb_ZOH4 = -shell_elec_electric_vehicle_P.max_torque;
        }
      }

      /* End of Saturate: '<S50>/Only permit negative torque values' */
    } else {
      /* Switch: '<S50>/Only use forward braking' incorporates:
       *  Constant: '<S50>/Constant'
       */
      rtb_ZOH4 = shell_elec_electric_vehicle_P.Constant_Value_p;
    }

    rtb_Mechanical = sin(shell_elec_electric_vehicle_P.d2r_Gain *
                         shell_elec_electric_vehicle_B.FromWs[0]) *
      shell_elec_electric_vehicle_P.gravity *
      shell_elec_electric_vehicle_P.vehicle_mass *
      shell_elec_electric_vehicle_P.wheel_radius * (1.0 /
      shell_elec_electric_vehicle_P.gear_ratio) +
      (shell_elec_electric_vehicle_P.max_torque *
       shell_elec_electric_vehicle_B.FromWs[3] + rtb_ZOH4);
  }

  /* End of Switch: '<S11>/Switch between torque control and speed control' */

  /* Saturate: '<S11>/Torque limits' */
  if (rtb_Mechanical > shell_elec_electric_vehicle_P.max_torque) {
    rtb_ZOH4 = shell_elec_electric_vehicle_P.max_torque;
  } else if (rtb_Mechanical < -shell_elec_electric_vehicle_P.max_torque) {
    rtb_ZOH4 = -shell_elec_electric_vehicle_P.max_torque;
  } else {
    rtb_ZOH4 = rtb_Mechanical;
  }

  /* End of Saturate: '<S11>/Torque limits' */

  /* Product: '<S8>/Product' */
  rtb_Product = shell_elec_electric_vehicle_B.UnitDelay * rtb_OUTPUT_1_0[3];

  /* Gain: '<S8>/Mechanical' */
  rtb_Mechanical = shell_elec_electric_vehicle_P.Mechanical_Gain * rtb_Product;

  /* Product: '<S8>/Product1' */
  rtb_Product = rtb_OUTPUT_1_0[1] * rtb_OUTPUT_1_0[0];

  /* Gain: '<S8>/ Electrical ' */
  rtb_Electrical = shell_elec_electric_vehicle_P.Electrical_Gain * rtb_Product;

  /* Update for Memory: '<S33>/Memory' */
  shell_elec_electric_vehicle_DW.Memory_PreviousInput = rtb_GAIN;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   *  RelationalOperator: '<S49>/UpperRelop'
   *  Switch: '<S49>/Switch'
   */
  if (rtb_ZOH4 > rtb_TrigonometricFunction) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    shell_elec_electric_vehicle_DW.UnitDelay_DSTATE = rtb_TrigonometricFunction;
  } else if (rtb_ZOH4 < rtb_TrigonometricFunction1) {
    /* Switch: '<S49>/Switch' incorporates:
     *  Update for UnitDelay: '<Root>/Unit Delay'
     */
    shell_elec_electric_vehicle_DW.UnitDelay_DSTATE = rtb_TrigonometricFunction1;
  } else {
    /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
     *  Switch: '<S49>/Switch'
     */
    shell_elec_electric_vehicle_DW.UnitDelay_DSTATE = rtb_ZOH4;
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Update for SimscapeExecutionBlock: '<S46>/STATE_1' */
  simulationData = (NeslSimulationData *)
    shell_elec_electric_vehicle_DW.STATE_1_SimulationData;
  time_1 = shell_elec_electric_vehicle_M->Timing.taskTime0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 130;
  simulationData->mData->mDiscStates.mX = (real_T *)
    &shell_elec_electric_vehicle_DW.STATE_1_DiscStates;
  simulationData->mData->mModeVector.mN = 144;
  simulationData->mData->mModeVector.mX = (int32_T *)
    &shell_elec_electric_vehicle_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_5[0] = 0;
  tmp_4[0] = shell_elec_electric_vehicle_B.INPUT_5_1_1[0];
  tmp_4[1] = shell_elec_electric_vehicle_B.INPUT_5_1_1[1];
  tmp_4[2] = shell_elec_electric_vehicle_B.INPUT_5_1_1[2];
  tmp_4[3] = shell_elec_electric_vehicle_B.INPUT_5_1_1[3];
  tmp_5[1] = 4;
  tmp_4[4] = shell_elec_electric_vehicle_B.INPUT_1_1_1[0];
  tmp_4[5] = shell_elec_electric_vehicle_B.INPUT_1_1_1[1];
  tmp_4[6] = shell_elec_electric_vehicle_B.INPUT_1_1_1[2];
  tmp_4[7] = shell_elec_electric_vehicle_B.INPUT_1_1_1[3];
  tmp_5[2] = 8;
  tmp_4[8] = shell_elec_electric_vehicle_B.INPUT_2_1_1[0];
  tmp_4[9] = shell_elec_electric_vehicle_B.INPUT_2_1_1[1];
  tmp_4[10] = shell_elec_electric_vehicle_B.INPUT_2_1_1[2];
  tmp_4[11] = shell_elec_electric_vehicle_B.INPUT_2_1_1[3];
  tmp_5[3] = 12;
  tmp_4[12] = shell_elec_electric_vehicle_B.INPUT_3_1_1[0];
  tmp_4[13] = shell_elec_electric_vehicle_B.INPUT_3_1_1[1];
  tmp_4[14] = shell_elec_electric_vehicle_B.INPUT_3_1_1[2];
  tmp_4[15] = shell_elec_electric_vehicle_B.INPUT_3_1_1[3];
  tmp_5[4] = 16;
  tmp_4[16] = shell_elec_electric_vehicle_B.INPUT_4_1_1[0];
  tmp_4[17] = shell_elec_electric_vehicle_B.INPUT_4_1_1[1];
  tmp_4[18] = shell_elec_electric_vehicle_B.INPUT_4_1_1[2];
  tmp_4[19] = shell_elec_electric_vehicle_B.INPUT_4_1_1[3];
  tmp_5[5] = 20;
  simulationData->mData->mInputValues.mN = 20;
  simulationData->mData->mInputValues.mX = &tmp_4[0];
  simulationData->mData->mInputOffsets.mN = 6;
  simulationData->mData->mInputOffsets.mX = &tmp_5[0];
  diagnosticManager = (NeuDiagnosticManager *)
    shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)
    shell_elec_electric_vehicle_DW.STATE_1_Simulator, NESL_SIM_UPDATE,
    simulationData, diagnosticManager);
  if (rowIdx != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(shell_elec_electric_vehicle_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
    }
  }

  /* End of Update for SimscapeExecutionBlock: '<S46>/STATE_1' */

  /* Update for Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport1' */
  shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport1_Pre =
    rtb_DataTypeConversion1;

  /* Update for Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport2' */
  shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport2_Pre =
    rtb_LogicalOperator;

  /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator' */
  shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE +=
    shell_elec_electric_vehicle_P.DiscreteTimeIntegrator_gainval *
    rtb_PulseGenerator;
  if (shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE >=
      shell_elec_electric_vehicle_P.max_torque) {
    shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE =
      shell_elec_electric_vehicle_P.max_torque;
  } else {
    if (shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE <=
        -shell_elec_electric_vehicle_P.max_torque) {
      shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE =
        -shell_elec_electric_vehicle_P.max_torque;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(shell_elec_electric_vehicle_M->rtwLogInfo,
                      (&shell_elec_electric_vehicle_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(shell_elec_electric_vehicle_M)!=-1) &&
        !((rtmGetTFinal(shell_elec_electric_vehicle_M)-
           shell_elec_electric_vehicle_M->Timing.taskTime0) >
          shell_elec_electric_vehicle_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(shell_elec_electric_vehicle_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++shell_elec_electric_vehicle_M->Timing.clockTick0)) {
    ++shell_elec_electric_vehicle_M->Timing.clockTickH0;
  }

  shell_elec_electric_vehicle_M->Timing.taskTime0 =
    shell_elec_electric_vehicle_M->Timing.clockTick0 *
    shell_elec_electric_vehicle_M->Timing.stepSize0 +
    shell_elec_electric_vehicle_M->Timing.clockTickH0 *
    shell_elec_electric_vehicle_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void shell_elec_electric_vehicle_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)shell_elec_electric_vehicle_M, 0,
                sizeof(RT_MODEL_shell_elec_electric__T));
  rtmSetTFinal(shell_elec_electric_vehicle_M, 200.0);
  shell_elec_electric_vehicle_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    shell_elec_electric_vehicle_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(shell_elec_electric_vehicle_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(shell_elec_electric_vehicle_M->rtwLogInfo, (NULL));
    rtliSetLogT(shell_elec_electric_vehicle_M->rtwLogInfo, "tout");
    rtliSetLogX(shell_elec_electric_vehicle_M->rtwLogInfo, "");
    rtliSetLogXFinal(shell_elec_electric_vehicle_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(shell_elec_electric_vehicle_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(shell_elec_electric_vehicle_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(shell_elec_electric_vehicle_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(shell_elec_electric_vehicle_M->rtwLogInfo, 1);
    rtliSetLogY(shell_elec_electric_vehicle_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(shell_elec_electric_vehicle_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(shell_elec_electric_vehicle_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &shell_elec_electric_vehicle_B), 0,
                sizeof(B_shell_elec_electric_vehicle_T));

  /* states (dwork) */
  (void) memset((void *)&shell_elec_electric_vehicle_DW, 0,
                sizeof(DW_shell_elec_electric_vehicl_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(shell_elec_electric_vehicle_M->rtwLogInfo,
    0.0, rtmGetTFinal(shell_elec_electric_vehicle_M),
    shell_elec_electric_vehicle_M->Timing.stepSize0, (&rtmGetErrorStatus
    (shell_elec_electric_vehicle_M)));

  {
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    real_T modelParameters_mSolverToleranc;
    real_T modelParameters_mFixedStepSize;
    boolean_T modelParameters_mVariableStepSo;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_0;
    char *msg;
    real_T *parameterBundle_mRealParameters;
    real_T tmp_1;
    NeslSimulationData *simulationData;
    real_T time;
    real_T time_0;
    NeModelParameters expl_temp;
    NeParameterBundle expl_temp_0;
    NeModelParameters expl_temp_1;

    /* Start for FromWorkspace: '<S4>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.1, 0.3, 0.3, 7.5, 7.5, 8.0, 8.0,
        10.0, 10.0, 25.0, 25.0, 100.0, 100.0, 180.0, 180.0, 200.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 0.0, 0.0, 0.0, -0.01, 0.99, 0.99, 0.96142857142857152,
        0.96142857142857152, 0.8471428571428572, 0.8471428571428572, -0.01,
        -0.01, 0.0, 1.0, 0.19999999999999996, 0.19999999999999996, -0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 25.0, 25.0, 25.0, 25.0,
        25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0 }
      ;

      shell_elec_electric_vehicle_DW.FromWs_PWORK.TimePtr = (void *)
        pTimeValues0;
      shell_elec_electric_vehicle_DW.FromWs_PWORK.DataPtr = (void *)
        pDataValues0;
      shell_elec_electric_vehicle_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for SimscapeExecutionBlock: '<S46>/STATE_1' */
    tmp = nesl_lease_simulator(
      "shell_elec_electric_vehicle/Solver Configuration_1", 0, 0);
    shell_elec_electric_vehicle_DW.STATE_1_Simulator = (void *)tmp;
    modelParameters_mVariableStepSo = pointer_is_null
      (shell_elec_electric_vehicle_DW.STATE_1_Simulator);
    if (modelParameters_mVariableStepSo) {
      shell_elec_electric_vehicle_442b803b_1_gateway();
      tmp = nesl_lease_simulator(
        "shell_elec_electric_vehicle/Solver Configuration_1", 0, 0);
      shell_elec_electric_vehicle_DW.STATE_1_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    shell_elec_electric_vehicle_DW.STATE_1_SimulationData = (void *)
      simulationData;
    diagnosticManager = rtw_create_diagnostics();
    shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager = (void *)
      diagnosticManager;
    modelParameters_mSolverToleranc = 0.001;
    modelParameters_mFixedStepSize = 0.01;
    modelParameters_mVariableStepSo = false;
    diagnosticManager = (NeuDiagnosticManager *)
      shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    expl_temp.mVariableStepSolver = modelParameters_mVariableStepSo;
    expl_temp.mUseSimState = false;
    expl_temp.mStartTime = 0.0;
    expl_temp.mSolverType = NE_SOLVER_TYPE_DAE;
    expl_temp.mSolverTolerance = modelParameters_mSolverToleranc;
    expl_temp.mLoggingMode = SSC_LOGGING_ALL;
    expl_temp.mLoadInitialState = false;
    expl_temp.mLinTrimCompile = false;
    expl_temp.mFixedStepSize = modelParameters_mFixedStepSize;
    tmp_0 = nesl_initialize_simulator((NeslSimulator *)
      shell_elec_electric_vehicle_DW.STATE_1_Simulator, expl_temp,
      diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSo = error_buffer_is_empty(rtmGetErrorStatus
        (shell_elec_electric_vehicle_M));
      if (modelParameters_mVariableStepSo) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
      }
    }

    tmp_1 = shell_elec_electric_vehicle_P.T_init;
    parameterBundle_mRealParameters = &tmp_1;
    expl_temp_0.mRealParameters.mN = 1;
    expl_temp_0.mRealParameters.mX = parameterBundle_mRealParameters;
    expl_temp_0.mLogicalParameters.mN = 0;
    expl_temp_0.mLogicalParameters.mX = NULL;
    expl_temp_0.mIntegerParameters.mN = 0;
    expl_temp_0.mIntegerParameters.mX = NULL;
    expl_temp_0.mIndexParameters.mN = 0;
    expl_temp_0.mIndexParameters.mX = NULL;
    nesl_simulator_set_rtps((NeslSimulator *)
      shell_elec_electric_vehicle_DW.STATE_1_Simulator, expl_temp_0);
    simulationData = (NeslSimulationData *)
      shell_elec_electric_vehicle_DW.STATE_1_SimulationData;
    time = shell_elec_electric_vehicle_M->Timing.taskTime0;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 130;
    simulationData->mData->mDiscStates.mX = (real_T *)
      &shell_elec_electric_vehicle_DW.STATE_1_DiscStates;
    simulationData->mData->mModeVector.mN = 144;
    simulationData->mData->mModeVector.mX = (int32_T *)
      &shell_elec_electric_vehicle_DW.STATE_1_Modes;
    modelParameters_mVariableStepSo = false;
    simulationData->mData->mFoundZcEvents = modelParameters_mVariableStepSo;
    simulationData->mData->mIsMajorTimeStep = true;
    modelParameters_mVariableStepSo = false;
    simulationData->mData->mIsSolverAssertCheck =
      modelParameters_mVariableStepSo;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)
      shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_0 = ne_simulator_method((NeslSimulator *)
      shell_elec_electric_vehicle_DW.STATE_1_Simulator, NESL_SIM_INITIALIZEONCE,
      simulationData, diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSo = error_buffer_is_empty(rtmGetErrorStatus
        (shell_elec_electric_vehicle_M));
      if (modelParameters_mVariableStepSo) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S46>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S46>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator(
      "shell_elec_electric_vehicle/Solver Configuration_1", 2, 0);
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    modelParameters_mVariableStepSo = pointer_is_null
      (shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator);
    if (modelParameters_mVariableStepSo) {
      shell_elec_electric_vehicle_442b803b_1_gateway();
      tmp = nesl_lease_simulator(
        "shell_elec_electric_vehicle/Solver Configuration_1", 2, 0);
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_SimulationData = (void *)
      simulationData;
    diagnosticManager = rtw_create_diagnostics();
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_DiagnosticManager = (void *)
      diagnosticManager;
    modelParameters_mSolverToleranc = 0.001;
    modelParameters_mFixedStepSize = 0.01;
    modelParameters_mVariableStepSo = false;
    diagnosticManager = (NeuDiagnosticManager *)
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    expl_temp_1.mVariableStepSolver = modelParameters_mVariableStepSo;
    expl_temp_1.mUseSimState = false;
    expl_temp_1.mStartTime = 0.0;
    expl_temp_1.mSolverType = NE_SOLVER_TYPE_DAE;
    expl_temp_1.mSolverTolerance = modelParameters_mSolverToleranc;
    expl_temp_1.mLoggingMode = SSC_LOGGING_ALL;
    expl_temp_1.mLoadInitialState = false;
    expl_temp_1.mLinTrimCompile = false;
    expl_temp_1.mFixedStepSize = modelParameters_mFixedStepSize;
    tmp_0 = nesl_initialize_simulator((NeslSimulator *)
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator, expl_temp_1,
      diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSo = error_buffer_is_empty(rtmGetErrorStatus
        (shell_elec_electric_vehicle_M));
      if (modelParameters_mVariableStepSo) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_SimulationData;
    time_0 = shell_elec_electric_vehicle_M->Timing.taskTime0;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = NULL;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = NULL;
    modelParameters_mVariableStepSo = false;
    simulationData->mData->mFoundZcEvents = modelParameters_mVariableStepSo;
    simulationData->mData->mIsMajorTimeStep = true;
    modelParameters_mVariableStepSo = false;
    simulationData->mData->mIsSolverAssertCheck =
      modelParameters_mVariableStepSo;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_0 = ne_simulator_method((NeslSimulator *)
      shell_elec_electric_vehicle_DW.OUTPUT_1_0_Simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSo = error_buffer_is_empty(rtmGetErrorStatus
        (shell_elec_electric_vehicle_M));
      if (modelParameters_mVariableStepSo) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(shell_elec_electric_vehicle_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S46>/OUTPUT_1_0' */
  }

  shell_elec_electric_veh_PrevZCX.Capturespeed_Trig_ZCE = POS_ZCSIG;
  shell_elec_electric_veh_PrevZCX.JKFlipFlop_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S33>/Memory' */
  shell_elec_electric_vehicle_DW.Memory_PreviousInput =
    shell_elec_electric_vehicle_P.Memory_X0;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  shell_elec_electric_vehicle_DW.UnitDelay_DSTATE =
    shell_elec_electric_vehicle_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport1' */
  shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport1_Pre =
    shell_elec_electric_vehicle_P.TmpLatchAtJKFlipFlopInport1_X0;

  /* InitializeConditions for Memory: '<S52>/TmpLatchAtJ-K Flip-FlopInport2' */
  shell_elec_electric_vehicle_DW.TmpLatchAtJKFlipFlopInport2_Pre =
    shell_elec_electric_vehicle_P.TmpLatchAtJKFlipFlopInport2_X0;

  /* InitializeConditions for DiscretePulseGenerator: '<S48>/Pulse Generator' */
  shell_elec_electric_vehicle_DW.clockTickCounter = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator' */
  shell_elec_electric_vehicle_DW.DiscreteTimeIntegrator_DSTATE =
    shell_elec_electric_vehicle_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for Triggered SubSystem: '<S52>/J-K Flip-Flop' */
  /* InitializeConditions for Memory: '<S54>/Memory' */
  shell_elec_electric_vehicle_DW.Memory_PreviousInput_n =
    shell_elec_electric_vehicle_P.Memory_X0_f;

  /* SystemInitialize for Outport: '<S54>/Q' */
  shell_elec_electric_vehicle_B.Logic[0] = shell_elec_electric_vehicle_P.Q_Y0;

  /* SystemInitialize for Outport: '<S54>/!Q' */
  shell_elec_electric_vehicle_B.Logic[1] = shell_elec_electric_vehicle_P.Q_Y0_j;

  /* End of SystemInitialize for SubSystem: '<S52>/J-K Flip-Flop' */
}

/* Model terminate function */
void shell_elec_electric_vehicle_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S46>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    shell_elec_electric_vehicle_DW.STATE_1_DiagnosticManager);
  nesl_destroy_simulation_data((NeslSimulationData *)
    shell_elec_electric_vehicle_DW.STATE_1_SimulationData);
  nesl_erase_simulator("shell_elec_electric_vehicle/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S46>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_DiagnosticManager);
  nesl_destroy_simulation_data((NeslSimulationData *)
    shell_elec_electric_vehicle_DW.OUTPUT_1_0_SimulationData);
  nesl_erase_simulator("shell_elec_electric_vehicle/Solver Configuration_1");
}
