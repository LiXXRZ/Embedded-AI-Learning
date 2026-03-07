%% === AM System Performance Plot (MSE vs SNR) ===
% 这是一个专门用来画报告折线图的脚本
% 只需要修改下面的 mse_data 即可

clc; clear; close all;

% ---------------------------------------------------------
% 1. 数据录入区 (在这里填你测出来的数据)
% ---------------------------------------------------------

% 横坐标：SNR (dB)
% 假设你每隔 5dB 或 10dB 测了一次，保持和你的实验一致
snr_axis = [0, 5, 10, 20, 30]; 

% 纵坐标：MSE (Mean Square Error)
% 【重要】：请把下面的数字换成你 Display 模块上记录的真实数字！
mse_data = [0.03347, 0.006091, 0.004197, 0.001932, 0.002248]; 

% ---------------------------------------------------------
% 2. 绘图代码 (这一部分不用改，直接运行)
% ---------------------------------------------------------

figure('Color', 'w'); % 创建白底画布

% 画图指令
% 'b-o': 蓝色实线(b-)，带圆圈标记(o)
% LineWidth: 线条加粗
% MarkerFaceColor: 标记点填充颜色
plot(snr_axis, mse_data, 'b-o', 'LineWidth', 2, 'MarkerSize', 8, 'MarkerFaceColor', 'b');

% ---------------------------------------------------------
% 3. 图表美化 (让图看起来更专业)
% ---------------------------------------------------------

grid on; % 打开网格，方便读数
grid minor; % 打开细微网格

% 设置坐标轴标签 (字号设大一点，报告里才看得清)
xlabel('Signal-to-Noise Ratio (SNR) [dB]', 'FontSize', 12, 'FontWeight', 'bold');
ylabel('Mean Square Error (MSE)', 'FontSize', 12, 'FontWeight', 'bold');

% 设置标题
title('AM System Performance: MSE vs. SNR', 'FontSize', 14);

% 设置坐标轴范围 (留一点边距)
xlim([min(snr_axis)-2, max(snr_axis)+2]); 
ylim([0, max(mse_data)*1.1]); % Y轴稍微高一点，防止最高点顶格

% ---------------------------------------------------------
% 4. 自动标注数值 (可选)
% ---------------------------------------------------------
% 这段代码会在每个数据点旁边自动写上数字，方便老师看
for i = 1:length(snr_axis)
    text(snr_axis(i)+0.5, mse_data(i), num2str(mse_data(i)), ...
        'FontSize', 10, 'Color', 'k');
end

disp('✅ 图表已生成！请直接复制图片到 Word 报告中。');