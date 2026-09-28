/*
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Mon Sep 28 16:19:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->64-bit Embedded Processor (LLP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include "ACC_private.h"

/* Named constants for Chart: '<S1>/ACC_Mode_Manager' */
#define ACC_IN_Distance_Control        ((uint8_T)1U)
#define ACC_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define ACC_IN_Off                     ((uint8_T)2U)
#define ACC_IN_Speed_Control           ((uint8_T)3U)
#define ACC_IN_Standby                 ((uint8_T)4U)

/* Block states (auto storage) */
DW_ACC_T ACC_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_ACC_T ACC_Y;

/* Real-time model */
RT_MODEL_ACC_T ACC_M_;
RT_MODEL_ACC_T *const ACC_M = &ACC_M_;

/* Model step function */
void ACC_step(void)
{
  real_T rtb_MultiportSwitch;

  /* Outputs for Atomic SubSystem: '<Root>/ACC Algorithm' */
  /* Chart: '<S1>/ACC_Mode_Manager' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/ACC_Enable'
   *  Inport: '<Root>/D_rel'
   */
  /* Gateway: ACC Algorithm/ACC_Mode_Manager */
  /* During: ACC Algorithm/ACC_Mode_Manager */
  if (ACC_DW.is_active_c3_ACC == 0U) {
    /* Entry: ACC Algorithm/ACC_Mode_Manager */
    ACC_DW.is_active_c3_ACC = 1U;

    /* Entry Internal: ACC Algorithm/ACC_Mode_Manager */
    /* Transition: '<S2>:16' */
    ACC_DW.is_c3_ACC = ACC_IN_Off;

    /* Outport: '<Root>/ACC_Mode' */
    /* Entry 'Off': '<S2>:2' */
    ACC_Y.ACC_Mode = 0.0;
  } else {
    switch (ACC_DW.is_c3_ACC) {
     case ACC_IN_Distance_Control:
      /* During 'Distance_Control': '<S2>:4' */
      if (ACC_U.D_rel > ACC_P.D_clear) {
        /* Transition: '<S2>:13' */
        ACC_DW.is_c3_ACC = ACC_IN_Speed_Control;

        /* Outport: '<Root>/ACC_Mode' */
        /* Entry 'Speed_Control': '<S2>:3' */
        ACC_Y.ACC_Mode = 2.0;
      } else {
        if (ACC_U.ACC_Enable == 0.0) {
          /* Transition: '<S2>:15' */
          ACC_DW.is_c3_ACC = ACC_IN_Off;

          /* Outport: '<Root>/ACC_Mode' */
          /* Entry 'Off': '<S2>:2' */
          ACC_Y.ACC_Mode = 0.0;
        }
      }
      break;

     case ACC_IN_Off:
      /* During 'Off': '<S2>:2' */
      if (ACC_U.ACC_Enable == 1.0) {
        /* Transition: '<S2>:7' */
        ACC_DW.is_c3_ACC = ACC_IN_Standby;

        /* Outport: '<Root>/ACC_Mode' */
        /* Entry 'Standby': '<S2>:1' */
        ACC_Y.ACC_Mode = 1.0;
      }
      break;

     case ACC_IN_Speed_Control:
      /* During 'Speed_Control': '<S2>:3' */
      if (ACC_U.D_rel <= ACC_P.D_clear) {
        /* Transition: '<S2>:12' */
        ACC_DW.is_c3_ACC = ACC_IN_Distance_Control;

        /* Outport: '<Root>/ACC_Mode' */
        /* Entry 'Distance_Control': '<S2>:4' */
        ACC_Y.ACC_Mode = 3.0;
      } else {
        if (ACC_U.ACC_Enable == 0.0) {
          /* Transition: '<S2>:14' */
          ACC_DW.is_c3_ACC = ACC_IN_Off;

          /* Outport: '<Root>/ACC_Mode' */
          /* Entry 'Off': '<S2>:2' */
          ACC_Y.ACC_Mode = 0.0;
        }
      }
      break;

     default:
      /* During 'Standby': '<S2>:1' */
      if (ACC_U.ACC_Enable == 0.0) {
        /* Transition: '<S2>:8' */
        ACC_DW.is_c3_ACC = ACC_IN_Off;

        /* Outport: '<Root>/ACC_Mode' */
        /* Entry 'Off': '<S2>:2' */
        ACC_Y.ACC_Mode = 0.0;
      } else if ((ACC_U.ACC_Enable == 1.0) && (ACC_U.D_rel > ACC_P.D_clear)) {
        /* Transition: '<S2>:9' */
        ACC_DW.is_c3_ACC = ACC_IN_Speed_Control;

        /* Outport: '<Root>/ACC_Mode' */
        /* Entry 'Speed_Control': '<S2>:3' */
        ACC_Y.ACC_Mode = 2.0;
      } else {
        if ((ACC_U.ACC_Enable == 1.0) && (ACC_U.D_rel <= ACC_P.D_clear)) {
          /* Transition: '<S2>:11' */
          ACC_DW.is_c3_ACC = ACC_IN_Distance_Control;

          /* Outport: '<Root>/ACC_Mode' */
          /* Entry 'Distance_Control': '<S2>:4' */
          ACC_Y.ACC_Mode = 3.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/ACC_Mode_Manager' */

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain_Kp_spd'
   *  Inport: '<Root>/D_rel'
   *  Inport: '<Root>/V_ego'
   *  Inport: '<Root>/V_rel'
   *  Inport: '<Root>/V_set'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Subtract'
   *  Sum: '<S1>/Subtract_speed'
   */
  switch ((int32_T)ACC_Y.ACC_Mode) {
   case 0:
    rtb_MultiportSwitch = ACC_P.Constant2_Value;
    break;

   case 1:
    rtb_MultiportSwitch = ACC_P.Constant2_Value;
    break;

   case 2:
    rtb_MultiportSwitch = (ACC_U.V_set - ACC_U.V_ego) * ACC_P.Kp_spd;
    break;

   default:
    rtb_MultiportSwitch = (ACC_U.D_rel - (ACC_P.T_gap * ACC_U.V_ego +
      ACC_P.D_min)) * ACC_P.Kp_dist + ACC_P.Kv_rel * ACC_U.V_rel;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Saturate: '<S1>/Saturation' */
  if (rtb_MultiportSwitch > ACC_P.T_max) {
    /* Outport: '<Root>/Torque_Demand' */
    ACC_Y.Torque_Demand = ACC_P.T_max;
  } else if (rtb_MultiportSwitch < ACC_P.T_min) {
    /* Outport: '<Root>/Torque_Demand' */
    ACC_Y.Torque_Demand = ACC_P.T_min;
  } else {
    /* Outport: '<Root>/Torque_Demand' */
    ACC_Y.Torque_Demand = rtb_MultiportSwitch;
  }

  /* End of Saturate: '<S1>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/ACC Algorithm' */
}

/* Model initialize function */
void ACC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ACC_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&ACC_DW, 0,
                sizeof(DW_ACC_T));

  /* external inputs */
  (void) memset((void *)&ACC_U, 0,
                sizeof(ExtU_ACC_T));

  /* external outputs */
  (void) memset((void *)&ACC_Y, 0,
                sizeof(ExtY_ACC_T));

  /* InitializeConditions for Atomic SubSystem: '<Root>/ACC Algorithm' */
  /* InitializeConditions for Chart: '<S1>/ACC_Mode_Manager' */
  ACC_DW.is_active_c3_ACC = 0U;
  ACC_DW.is_c3_ACC = ACC_IN_NO_ACTIVE_CHILD;

  /* End of InitializeConditions for SubSystem: '<Root>/ACC Algorithm' */
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
