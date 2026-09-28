# Adaptive Cruise Control (ACC) - Model-Based Development & SIL Testing
An automotive Adaptive Cruise Control (ACC) system developed using MATLAB/Simulink and Embedded Coder following Model-Based Development (MBD) practices. This project demonstrates control algorithm design, production C-code generation, and Software-in-the-Loop (SIL) verification.
---
## Architecture & Control Modes
The ACC algorithm operates in two core control modes based on target distance metrics:
1. **Speed Control Mode:** Maintains the driver-selected set speed ($V_{set}$) when no lead vehicle is detected within the clear distance threshold ($D_{clear}$).
2. **Distance Control Mode:** Maintains a safe time-headway gap ($T_{gap}$) and minimum standstill distance ($D_{min}$) behind a detected lead vehicle.
### Key Data Dictionary Parameters

| Parameter | Description | Value / Type |
| :--- | :--- | :--- |
| `D_min` | Minimum standstill distance | `10.0` (meter, `single`) |
| `T_gap` | Target time headway gap | `1.5` (second, `single`) |
| `D_clear` | Lead vehicle detection threshold | `50.0` (meter, `single`) |
| `dt_single` | Floating-point data type | `'single'` |
| `dt_bool` | Standard boolean flag type | `'boolean'` |

---
## Model-Based Development Workflow
1. **MIL (Model-in-the-Loop) Simulation:** Functional validation of control logic against synthesized drive cycles.
2. **Production Code Generation:** Embedded C code generated using Embedded Coder (`ert.tlc`) with target scalar types.
3. **SIL (Software-in-the-Loop) Verification:** Compiled C code executed via S-Function back-to-back against the Simulink reference model to ensure $0\%$ numerical discrepancy.
---
## Directory Structure
```text
**models/** # Simulink models (MIL and SIL models)
**results/** # SIL simulation scope output plots
**scripts/** # Workspace initialization script (setup_ACC_data.m)
**src/** # Generated C/C++ source files (ACC_ert_rtw)
**README.md**: Project documentation


How to Run
1. Run 'scripts/setup_ACC_data.m' in MATLAB to load workspace variables.

2.Open 'models/ACC_Controller_SIL.slx'.

3.Run the simulation to view the SIL scope execution results.


