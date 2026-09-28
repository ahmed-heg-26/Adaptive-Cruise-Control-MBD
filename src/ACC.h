/*
 * File: ACC.h
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

#ifndef RTW_HEADER_ACC_h_
#define RTW_HEADER_ACC_h_
#include <stddef.h>
#include <string.h>
#ifndef ACC_COMMON_INCLUDES_
# define ACC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_ACC;            /* '<S1>/ACC_Mode_Manager' */
  uint8_T is_c3_ACC;                   /* '<S1>/ACC_Mode_Manager' */
} DW_ACC_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T ACC_Enable;                   /* '<Root>/ACC_Enable' */
  real_T V_ego;                        /* '<Root>/V_ego' */
  real_T V_set;                        /* '<Root>/V_set' */
  real_T D_rel;                        /* '<Root>/D_rel' */
  real_T V_rel;                        /* '<Root>/V_rel' */
} ExtU_ACC_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Torque_Demand;                /* '<Root>/Torque_Demand' */
  real_T ACC_Mode;                     /* '<Root>/ACC_Mode' */
} ExtY_ACC_T;

/* Parameters (auto storage) */
struct P_ACC_T_ {
  real32_T D_clear;                    /* Variable: D_clear
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T D_min;                      /* Variable: D_min
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real32_T Kp_dist;                    /* Variable: Kp_dist
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real32_T Kp_spd;                     /* Variable: Kp_spd
                                        * Referenced by: '<S1>/Gain_Kp_spd'
                                        */
  real32_T Kv_rel;                     /* Variable: Kv_rel
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real32_T T_gap;                      /* Variable: T_gap
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T T_max;                      /* Variable: T_max
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real32_T T_min;                      /* Variable: T_min
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ACC_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_ACC_T ACC_P;

/* Block states (auto storage) */
extern DW_ACC_T ACC_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_ACC_T ACC_Y;

/* Model entry point functions */
extern void ACC_initialize(void);
extern void ACC_step(void);
extern void ACC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACC_T *const ACC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ACC_Controller/ACC Algorithm')    - opens subsystem ACC_Controller/ACC Algorithm
 * hilite_system('ACC_Controller/ACC Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACC_Controller'
 * '<S1>'   : 'ACC_Controller/ACC Algorithm'
 * '<S2>'   : 'ACC_Controller/ACC Algorithm/ACC_Mode_Manager'
 */
#endif                                 /* RTW_HEADER_ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
