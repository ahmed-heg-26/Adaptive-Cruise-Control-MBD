%===================================================================
%Adaptive Cruise Control (ACC) Parameter setup
%===================================================================

%1. Data types
dt_single = 'single';
dt_bool = 'boolean';

%2. System Thresholds & Calibration  Parameters
D_min = single(10.0);  % Minimum standstill distance (meter)
T_gap = single(1.5);   % Target time headway gap (seconds)
D_clear = single(50.0); % Detection threshold for lead vehicle (meters)

%3. Control Gains
Kp_dist = single(5.0);  % Proportional gain for distance error
Kv_rel =  single(12.0);  % Proportional gain for relative speed;
Kp_spd = single(8.0);    %proportional gain for cruise speed errror

%4. Actuator Limits
T_max = single(150.0);   %Maximum acceleration torque  (Nm)
T_min = single(-150.0);  %Maximum decceleration torque (Nm)

disp('>>> ACC parameters successfully loaded into workspace! <<<');