% 引力透镜光线追踪模拟程序
% 基于点质量透镜模型，模拟光线偏折和爱因斯坦环现象

clear all; close all; clc;

%% 物理常数与模拟参数设置
G = 6.67430e-11;      % 万有引力常数 (m^3 kg^-1 s^-2)
c = 2.99792458e8;     % 光速 (m/s)
Msun = 1.989e30;      % 太阳质量 (kg)

% 天体物理参数
M = 1e12 * Msun;      % 透镜质量 (10^12 太阳质量，类似星系质量)
D_d = 1e24;           % 观测者到透镜的距离 (约32.6亿光年，以米为单位)
D_s = 2e24;           % 观测者到光源的距离
D_ds = D_s - D_d;     % 透镜到光源的距离

% 计算爱因斯坦环半径 (弧度)
theta_E = sqrt((4*G*M)/(c^2) * (D_ds/(D_d*D_s)));

% 光源参数
sigma_source = 0.5*theta_E;  % 光源大小 (高斯分布标准差)
I0 = 1.0;                   % 光源中心强度

%% 网格设置 (观测平面)
theta_max = 5*theta_E;      % 最大角距离 (以爱因斯坦环半径为单位)
N = 500;                    % 网格点数
theta = linspace(-theta_max, theta_max, N);
[theta_x, theta_y] = meshgrid(theta, theta);
theta_r = sqrt(theta_x.^2 + theta_y.^2);

%% 光线追踪映射 (观测平面 -> 光源平面)
% 计算偏转角 (弧度) - 修正此处的矩阵运算错误
alpha = (4*G*M)./(c^2 * theta_r * D_d);  % 使用 ./ 进行逐元素除法
alpha(isnan(alpha)) = 0;  % 处理中心点

% 映射到光源平面
beta_x = theta_x - alpha .* (theta_x./theta_r);
beta_y = theta_y - alpha .* (theta_y./theta_r);
beta_x(isnan(beta_x)) = 0;
beta_y(isnan(beta_y)) = 0;

%% 计算光源平面光强分布
% 高斯分布光源
I_source = I0 * exp(-(beta_x.^2 + beta_y.^2)/(2*sigma_source^2));

%% 计算放大率 (可选)
% 雅可比矩阵行列式的倒数
dx_dtheta = 1 - (4*G*M)/(c^2*D_d) * (1./theta_r.^2 - theta_x.^2./theta_r.^4);
dy_dtheta = 1 - (4*G*M)/(c^2*D_d) * (1./theta_r.^2 - theta_y.^2./theta_r.^4);
dx_dphi = (4*G*M)/(c^2*D_d) * (theta_x.*theta_y./theta_r.^4);
dy_dphi = (4*G*M)/(c^2*D_d) * (theta_x.*theta_y./theta_r.^4);
mu = 1./abs(dx_dtheta.*dy_dtheta - dx_dphi.*dy_dphi);
mu(isnan(mu)) = 0;

%% 可视化结果
figure('Position', [100, 100, 1200, 500]);

% 显示模拟结果 (观测平面)
subplot(1, 2, 1);
imagesc(theta/theta_E, theta/theta_E, I_source);
axis square tight;
colormap('hot');
title('引力透镜成像 (观测平面)');
xlabel('角度距离 (\theta_x/\theta_E)');
ylabel('角度距离 (\theta_y/\theta_E)');
colorbar;

% 标记爱因斯坦环位置
hold on;
t = linspace(0, 2*pi, 100);
plot(cos(t), sin(t), 'w--', 'LineWidth', 1.5);
text(0, 1.1, '\theta_E', 'Color', 'w', 'HorizontalAlignment', 'center');
hold off;

% 显示光源平面 (无透镜时)
subplot(1, 2, 2);
I_original = I0 * exp(-(theta_x.^2 + theta_y.^2)/(2*sigma_source^2));
imagesc(theta/theta_E, theta/theta_E, I_original);
axis square tight;
colormap('hot');
title('原始光源 (无透镜)');
xlabel('角度距离 (\beta_x/\theta_E)');
ylabel('角度距离 (\beta_y/\theta_E)');
colorbar;

%% 输出关键参数
fprintf('模拟参数总结:\n');
fprintf('----------------------------------------\n');
fprintf('透镜质量: %.2e 太阳质量\n', M/Msun);
fprintf('爱因斯坦环半径: %.6e 弧度\n', theta_E);
fprintf('观测者到透镜距离: %.2e 米\n', D_d);
fprintf('观测者到光源距离: %.2e 米\n', D_s);
fprintf('光源大小: %.2f x 爱因斯坦环半径\n', sigma_source/theta_E);
fprintf('----------------------------------------\n'); 