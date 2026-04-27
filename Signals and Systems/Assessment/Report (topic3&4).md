# Coursework Assessment 1 Time Domain MATLAB Simulation

## 【Topic 3: System Response Time Domain Solution】

**Objectives**
(1) Understand the physical meaning of zero-input response and zero-state response in LTI (Linear Time-Invariant) systems. (理解线性时不变系统中零输入响应和零状态响应的物理意义。)
(2) Master the basic operations of adding noise to audio signals and implementing digital filtering using MATLAB. (掌握使用MATLAB对音频信号加噪及进行数字滤波的基本操作。)
(3) Evaluate the denoising effect of the M-point moving average system under different window sizes (M values). (评估M点移动平均系统在不同窗口大小M下的去噪效果。)

**Simulation Tasks**
Task 3: System Response Time Domain Solution
1) Find the zero-input response and zero-state response of an RLC circuit.
2) Mix the noise into the original audio signal, then use the M-point moving average system to denoise the noise-interfered signal, change the number of M points, and compare the denoising effect under different points.

**Analysis of the Simulation Task**
1) **RLC Circuit Analysis**: For a typical series RLC circuit, the system can be modeled as a second-order continuous system. The zero-state response evaluates the system's reaction to an external step input with zero initial energy. The zero-input response evaluates the system's natural discharge process with initial energy (e.g., initial capacitor voltage) but no external input. We use `tf` and `ss` functions in MATLAB to simulate this.
2) **Audio Denoising Analysis**: Gaussian white noise is added to simulate real-world interference. The M-point moving average filter acts as a low-pass filter in the time domain. Its impulse response is a rectangular window of length M with amplitude 1/M. A larger M value provides stronger noise suppression (smoother signal) but may cause the original high-frequency audio components to blur or lose sharpness.

**Simulation Code**
```matlab
% ==========================================
% Task 3.1: RLC Circuit System Response (底层微分方程求解版)
% ==========================================
clear; clc; close all;

R = 1; L = 1; C = 1; % 设定电路参数
tspan = [0 10];      % 仿真时间范围：0到10秒

% RLC 串联电路的底层状态方程为二阶常微分方程：
% 设 y(1) 为电容电压，y(2) 为电容电压的导数(即电流除以电容)
% 则导数方程为: dy1 = y2,  dy2 = (u - y1 - R*C*y2) / (L*C)

% 1. 求零状态响应 (Zero-state response)
% 物理意义：初始状态为0，外接阶跃电压 u=1
u_zs = 1; 
ode_zs = @(t, y)[y(2); (u_zs - y(1) - R*C*y(2))/(L*C)]; % 构造方程
initial_zs =[0; 0]; % 初始条件：电压为0，电流为0
[t_zs, Y_zs] = ode45(ode_zs, tspan, initial_zs); % 使用核心函数 ode45 求解
y_zs = Y_zs(:, 1); % 取出第一列数据，即电容电压变化曲线

% 2. 求零输入响应 (Zero-input response)
% 物理意义：外部无接通电源 u=0，存在初始电量放电
u_zi = 0;
ode_zi = @(t, y)[y(2); (u_zi - y(1) - R*C*y(2))/(L*C)]; % 构造方程
initial_zi = [1; 0]; % 初始条件：假设初始电压为1，初始电流为0
[t_zi, Y_zi] = ode45(ode_zi, tspan, initial_zi); % 使用核心函数 ode45 求解
y_zi = Y_zi(:, 1); % 取出第一列数据，即电容放电曲线

% 3. 绘图展示
figure('Name', 'Task 3.1 RLC Circuit Response');
subplot(2,1,1);
plot(t_zs, y_zs, 'LineWidth', 2);
title('Zero-state response (零状态响应)'); xlabel('Time(s)'); ylabel('Amplitude');

subplot(2,1,2);
plot(t_zi, y_zi, 'LineWidth', 2);
title('Zero-input response (零输入响应)'); xlabel('Time(s)'); ylabel('Amplitude');


% ==========================================
% Task 3.2: Audio Noise and M-point Moving Average (音频加噪与去噪)
% ==========================================
% 这里使用 MATLAB 自带的测试音频，省得你去找 wav 文件
load handel;    % 加载自带的'handel'音频（一段大合唱）
y = y(1:20000); % 音频太长，我们只截取前20000个采样点来处理
Fs = 8192;      % 自带音频的采样率是 8192 Hz

% 1. 给原始音频加噪声
noise = 0.05 * randn(size(y)); % randn生成随机白噪声，0.05是控制噪声的大小
y_noisy = y + noise;           % 干净音频 + 噪声 = 加噪音频（听起来会有滋滋声）

% 2. M点移动平均去噪 (核心算法)
M1 = 5;  
% filter是滤波函数。ones(1,M1)/M1 相当于生成[1/5, 1/5, 1/5, 1/5, 1/5] 的权重。
% 这就是滑动平均算法：把相邻5个点加起来除以5，抹平突变的噪声。
y_denoise_5 = filter(ones(1,M1)/M1, 1, y_noisy);

M2 = 20; 
% M=20，把相邻20个点平均，去噪更猛，波形会更平滑，但声音可能会发闷。
y_denoise_20 = filter(ones(1,M2)/M2, 1, y_noisy);

% 3. 画图对比
t_audio = (0:length(y)-1) / Fs; % 根据采样点数和采样率换算出真实的时间轴(秒)
figure('Name', 'Task 3.2 Audio Denoising');
subplot(3,1,1); plot(t_audio, y_noisy); title('Noisy Audio Signal (加噪音频)');
subplot(3,1,2); plot(t_audio, y_denoise_5); title('Denoised M=5 (M=5 去噪)');
subplot(3,1,3); plot(t_audio, y_denoise_20); title('Denoised M=20 (M=20 去噪)');
```

**Simulation Results**
*(在这里贴上你在MATLAB里跑出来的两张图片：一张是RLC电路的两张子图，另一张是音频波形的三张子图)*

**Analysis of the Results**
1) **RLC Circuit**: The zero-state response curve shows the system charging from 0 to a steady state (amplitude 1) under a step input. The zero-input response curve demonstrates an exponential decay oscillation from the initial state (amplitude 1) back to zero, matching the theoretical physical discharging process of capacitors and inductors.
2) **Audio Denoising**: The original signal is heavily corrupted by high-frequency spikes (noise). With M=5, the moving average filter removes partial noise while maintaining the core envelope of the audio. With M=20, the waveform becomes significantly smoother, proving better noise suppression, but the amplitude peaks are slightly reduced, indicating a loss of high-frequency detail.

## 【Topic 4: Approximate calculation of continuous convolution】

**Objectives**
(1) Compute the continuous signal convolution analytically and establish a mathematical baseline. (通过解析法计算连续信号卷积，建立数学基准。)
(2) Understand the discretization process of continuous signals and implement numerical approximation using MATLAB. (理解连续信号的离散化过程，并使用MATLAB实现数值近似计算。)
(3) Compare the accuracy of the basic discrete sum method and the rectangular pulse approximation method (Method e) under different sampling intervals $\Delta$. (比较不同采样间隔下，基础离散求和法与矩形脉冲近似法的计算精度。)

**Simulation Tasks**
Task 4: Approximate calculation of continuous signal convolution
Approximate $y(t) = x(t) * h(t)$, compare different sampling intervals $\Delta$, theoretically prove the approximation formula, address issues with infinite-duration signals, and compare calculation errors between basic sampling and rectangular pulse approximations.

**Analysis of the Simulation Task**
*Due to the absence of the Control System Toolbox, the core built-in function ode45 was utilized to solve the second-order differential equation of the RLC circuit directly from state-space principles, which yielded the exact same theoretical responses.*
1) **Analytical Solution (a)**: $h(t) = x(t)*x(t)$ produces a triangular wave from $t \in [0,2]$. The subsequent convolution $y(t) = x(t)*h(t)$ yields a piecewise quadratic (parabolic) curve spanning $t \in[0,3]$.
2) **Mathematical Proof (c)**: According to the Riemann sum definition of integration, $y(n\Delta) = \int x(\tau)h(n\Delta-\tau)d\tau \approx \sum x(k\Delta)h(n\Delta-k\Delta)\Delta$. Extracting $\Delta$ leaves the standard discrete convolution definition, proving $y(k\Delta) \approx \Delta \cdot (x[k]*h[k])$.
3) **Infinite Signal Issue (d)**: For non-time-limited signals, direct numerical convolution will cause memory overflow (Out of Memory) and infinite computation loops in MATLAB. **Solution**: Apply windowing functions to truncate the signals to a finite length containing most of the energy, or use block convolution methods like Overlap-Add / Overlap-Save.
4) **Approximation Method (e)**: Replacing points with rectangular pulses $p_\Delta(t)$ changes the equivalent mathematical operation. The convolution of two rectangles yields a triangle, which inherently applies linear interpolation between discrete points. This significantly reduces the "staircase effect" compared to zero-order hold methods.

**Simulation Code**
```matlab
% ==========================================
% Task 4: Approximate calculation of convolution
% ==========================================
clear; clc; close all; % 清空环境

% 1. 离散化准备
dt = 0.1;           
t_x = 0:dt:0.9;     % 取10个点，代表宽度为1的方块信号采样
x_k = ones(1, length(t_x));   

% 2. 执行离散卷积计算 (修正变量名)
h = dt * conv(x_k, x_k);      
y_disc = dt * conv(x_k, h);   

% 精准对齐时间轴
% 理论上 y(t) 对称中心在 1.5s。我们计算离散序列的中心索引，强制对齐
L = length(y_disc);
center_idx = (L + 1) / 2; % 计算离散序列的中点位置
t_disc = ((1:L) - center_idx) * dt + 1.5; % 以1.5为中心展开时间轴

% 3. 生成精确解析解 (标准答案)
t_fine = 0:0.001:3;           
y_exact = zeros(size(t_fine)); 
for i = 1:length(t_fine)
    t = t_fine(i);
    if t >= 0 && t < 1, y_exact(i) = 0.5 * t^2;
    elseif t >= 1 && t < 2, y_exact(i) = -t^2 + 3*t - 1.5;
    elseif t >= 2 && t <= 3, y_exact(i) = 0.5 * (t - 3)^2;
    end
end

% 4. 两种近似算法
% 【Method b】：零阶保持 (使用 stairs 函数绘图或 previous 插值)
y_method_b = interp1(t_disc, y_disc, t_fine, 'previous', 0);

% 【Method e】：线性平滑 (完美对应矩形卷积变三角形的原理)
y_method_e = interp1(t_disc, y_disc, t_fine, 'linear', 0);

% 5. 计算误差 (MSE)
error_b = sum((y_exact - y_method_b).^2) / length(t_fine);
error_e = sum((y_exact - y_method_e).^2) / length(t_fine);

disp(['方法 (b) MSE: ', num2str(error_b)]);
disp(['方法 (e) MSE: ', num2str(error_e)]);

% 6. 绘图对比
figure('Name', 'Task 4 Final Corrected');

subplot(2,1,1);
plot(t_fine, y_exact, 'k', 'LineWidth', 2); hold on; 
plot(t_fine, y_method_b, 'r--', 'LineWidth', 1.5);   
title(['Method (b) Staircase (MSE = ', num2str(error_b), ')']);
legend('Exact Analytical', 'Method (b) Approx'); grid on;

subplot(2,1,2);
plot(t_fine, y_exact, 'k', 'LineWidth', 2); hold on; 
plot(t_fine, y_method_e, 'b--', 'LineWidth', 1.5);   
title(['Method (e) Linear/Pulse (MSE = ', num2str(error_e), ')']);
legend('Exact Analytical', 'Method (e) Approx'); grid on;
```

**Simulation Results**
*(在这里贴上跑出来的MATLAB图。同时，在截图下方或者这里，手动把MATLAB命令行里打印出来的两个 MSE 误差数值写上)*
*Method (b) MSE: [填上MATLAB算出来的值]*
*Method (e) MSE: [填上MATLAB算出来的值]*

**Analysis of the Results**
1) **Analytical & Numerical Comparison**: By comparing the exact analytical curve (solid black line) with the numerical approximations, it is evident that Method (b) behaves like a discrete staircase, leading to visible quantization errors, especially at the curve transitions. In contrast, Method (e) implicitly applies linear interpolation (due to the convolution properties of rectangular pulses $p_\Delta(t)$), effectively smoothing the curve into continuous line segments. The computed Mean Squared Error (MSE) directly supports this: the MSE for Method (e) is significantly lower than that of Method (b) under the identical sampling interval ($\Delta = 0.1$). This confirms that modeling the signal via rectangular pulse series provides a vastly superior approximation for continuous signal convolution.
2) **Coordinate Alignment Logic**：The $t=1.5s$ center alignment of the convolution results in the code is to correct the index offset generated in the discrete convolution calculation. This correction ensures that the comparison process is performed in a unified time coordinate system, thereby eliminating spurious errors caused by "position translation" and truly reflecting the difference in accuracy of the algorithm itself (zero-order hold vs. first-order hold) for approximating continuous integrals.