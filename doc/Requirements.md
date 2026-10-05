# Software Requirements Specification: Adaptive Cruise Control (ACC) System
## 1. System Overview
The Adaptive Cruise Control (ACC) system automatically adjusts the ego vehicle's torque output to maintain either a driver-selected target speed or a safe trailing distance behind a lead vehicle based on sensor feedback.
---
## 2. System Inputs & Outputs
### Inputs
* **ACC_Enable** (boolean): System enable flag.
* **V_ego** (single): Ego vehicle current speed (m/s).
* **V_set** (single): Desired cruise speed setpoint (m/s).
* **D_rel** (single): Relative distance to the lead vehicle (m).
* **V_rel** (single): Relative velocity to the lead vehicle (m/s).
### Outputs
* **Torque_Demand** (single): Calculated torque request (Nm) bounded between [-150.0, 150.0].
* **ACC_Mode** (single/int): Current operational mode identifier (0, 1, 2, or 3).
---

## 3. System Calibration Parameters

| Parameter | Value | Data Type | Description |
| :--- | :--- | :--- | :--- |
| **D_min** | 10.0 | single | Minimum standstill distance (m) |
| **T_gap** | 1.5 | single | Target time headway gap (s) |
| **D_clear** | 50.0 | single | Detection threshold for lead vehicle (m) |
| **Kp_dist** | 5.0 | single | Proportional gain for distance error |
| **Kv_rel** | 12.0 | single | Proportional gain for relative speed error |
| **Kp_spd** | 8.0 | single | Proportional gain for cruise speed error |
| **T_max** | 150.0 | single | Maximum allowable torque output (Nm) |
| **T_min** | -150.0 | single | Maximum allowable braking/deceleration torque output (Nm) |

---

## 4. Functional Requirements
### 4.1 State Machine & Operating Modes (ACC_Mode_Manager)
* **REQ-ACC-01 (Off Mode):** If ACC_Enable == 0, the system shall enter Off state (mode = 0). Torque output shall remain zero.
* **REQ-ACC-02 (Standby Mode):** When ACC_Enable == 1 transitions from 0, the system shall enter Standby state (mode = 1).
* **REQ-ACC-03 (Speed Control Mode):** When ACC_Enable == 1 and D_rel > D_clear (50 m), the system shall enter Speed Control state (mode = 2).
* **REQ-ACC-04 (Distance Control Mode):** When ACC_Enable == 1 and D_rel <= D_clear (50 m), the system shall enter Distance Control state (mode = 3).
* **REQ-ACC-05 (Transition to Off):** If ACC_Enable == 0 at any point during operation, the system shall immediately revert to Off state (mode = 0).
---
### 4.2 Control Algorithms & Calculations
* **REQ-ACC-06 (Safe Distance Calculation):**
  D_safe = D_min + (V_ego * T_gap)
  Where D_min = 10.0 m and T_gap = 1.5 s.
* **REQ-ACC-07 (Speed Control Mode Output):**
  When in Speed Control (mode = 2), torque demand shall be calculated as:
  Torque = Kp_spd * (V_set - V_ego)
* **REQ-ACC-08 (Distance Control Mode Output):**
  When in Distance Control (mode = 3), torque demand shall be calculated as:
  Torque = Kp_dist * (D_rel - D_safe) + Kv_rel * V_rel
* **REQ-ACC-09 (Actuator Saturation):**
  The final calculated Torque_Demand must be saturated to remain within [T_min, T_max], strictly constraining output values to [-150.0 Nm, 150.0 Nm].