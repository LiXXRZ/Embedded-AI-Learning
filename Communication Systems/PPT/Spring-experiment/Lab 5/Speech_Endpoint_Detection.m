% ==========================================
% CNSCC.160 Lab 5: Speech Endpoint Detection
% ==========================================
clear; clc; close all;

% 我们将用一个循环依次处理两个文件
audio_files = {'Harvard_sentences.wav', 'moon.wav'};

for file_idx = 1:length(audio_files)
    filename = audio_files{file_idx};
    fprintf('Processing %s...\n', filename);
    
    %% Task 3.1: Pre-processing & Framing (预处理与分帧)
    
    % 1. 导入音频
    [x, fs] = audioread(filename);
    
    % 如果是双声道，转为单声道 (取第一列或求均值)
    if size(x, 2) > 1
        x = mean(x, 2);
    end
    
    % 2. 去除直流偏移 (Remove DC offset) - 即减去均值
    x = x - mean(x);
    
    % 3. 归一化振幅 (Normalize to 1.0)
    x = x / max(abs(x));
    
    % 4. 分帧 (Framing)
    % 帧长 = 25ms, 重叠 = 50%
    frame_length_ms = 25;
    frame_length = round((frame_length_ms / 1000) * fs); % 转换毫秒为样本数 N
    overlap = round(frame_length * 0.5);                 % 50% 重叠
    
    % 使用 buffer 函数分帧
    % frames 是一个矩阵，每一列代表一帧
    frames = buffer(x, frame_length, overlap, 'nodelay'); 
    num_frames = size(frames, 2);
    
    % 创建时间轴用于后续画图
    t_signal = (0:length(x)-1) / fs; % 原始信号时间轴
    t_frames = (0:num_frames-1) * (frame_length - overlap) / fs; % 帧级别的时间轴
    
    %% Task 3.2: Short-Time Energy (STE) Analysis
    
    % 1. 计算每一帧的 STE
    % 按照公式 Ei = sum(x(n)^2)
    STE = sum(frames.^2, 1); 
    
    % 2. 自适应阈值计算 (基于前10帧背景噪音)
    silence_frames_STE = STE(1:10);
    STE_mean = mean(silence_frames_STE);
    STE_std = std(silence_frames_STE);
    
    % 注意：你需要为两个不同的文件设置不同的 k 值！
    if contains(filename, 'moon')
        k_STE = 5; % Moon文件背景噪音极大，需要更高的k值
    else
        k_STE = 2; % Harvard文件相对干净，k值可以小一点
    end
    
    Threshold_STE = STE_mean + k_STE * STE_std;
    
    % 3. 生成 STE Mask (二进制掩码)
    Mask_STE = STE > Threshold_STE;
    
    % 4. 绘图 Figure 1: STE Analysis
    figure('Name',['STE Analysis - ', filename], 'Position',[100, 100, 800, 600]);
    
    subplot(3,1,1);
    plot(t_signal, x); title(['Signal: ', filename]); xlabel('Time (s)'); ylabel('Amplitude');
    
    subplot(3,1,2);
    plot(t_frames, STE, 'b'); hold on;
    yline(Threshold_STE, 'r--', 'LineWidth', 1.5); 
    title('Short-Time Energy (STE)'); xlabel('Time (s)'); ylabel('Energy');
    legend('STE', 'Threshold'); hold off;
    
    subplot(3,1,3);
    stairs(t_frames, Mask_STE, 'k', 'LineWidth', 1.5); ylim([-0.2 1.2]);
    title('STE Mask'); xlabel('Time (s)'); ylabel('VAD (0/1)');
    
    %% Task 3.3: Zero Crossing Rate (ZCR) Analysis
    
    % 1. 计算每一帧的 ZCR
    % 公式: ZCR = 1/(2N) * sum(|sgn(x(n)) - sgn(x(n-1))|)
    % 利用 diff 和 sign 计算交变次数
    ZCR = sum(abs(diff(sign(frames))), 1) / (2 * frame_length);
    
    % 2. 自适应阈值计算 (基于前10帧)
    silence_frames_ZCR = ZCR(1:10);
    ZCR_mean = mean(silence_frames_ZCR);
    ZCR_std = std(silence_frames_ZCR);
    
    if contains(filename, 'moon')
        k_ZCR = 3; 
    else
        k_ZCR = 2; 
    end
    
    Threshold_ZCR = ZCR_mean + k_ZCR * ZCR_std;
    
    % 3. 生成 ZCR Mask
    Mask_ZCR = ZCR > Threshold_ZCR;
    
    % 4. 绘图 Figure 2: ZCR Analysis
    figure('Name',['ZCR Analysis - ', filename], 'Position', [150, 150, 800, 600]);
    
    subplot(3,1,1);
    plot(t_signal, x); title(['Signal: ', filename]); xlabel('Time (s)'); ylabel('Amplitude');
    
    subplot(3,1,2);
    plot(t_frames, ZCR, 'b'); hold on;
    yline(Threshold_ZCR, 'r--', 'LineWidth', 1.5);
    title('Zero Crossing Rate (ZCR)'); xlabel('Time (s)'); ylabel('ZCR Rate');
    legend('ZCR', 'Threshold'); hold off;
    
    subplot(3,1,3);
    stairs(t_frames, Mask_ZCR, 'k', 'LineWidth', 1.5); ylim([-0.2 1.2]);
    title('ZCR Mask'); xlabel('Time (s)'); ylabel('VAD (0/1)');
    
    %% Task 3.4: Combined Feature Endpoint Detection
    
    % 1. 逻辑 OR 结合掩码
    Mask_Combined = Mask_STE | Mask_ZCR;
    
    % 2. 应用中值滤波 (Mask Refinement)
    % 窗口大小 (例如：31 帧，大约 31 * 12.5ms = 387.5ms 的平滑时间)
    filter_order = 31; 
    Mask_Final = medfilt1(double(Mask_Combined), filter_order);
    
    % 确保过滤后仍然是严格的 0 和 1 (防备double转换中的极小误差)
    Mask_Final = Mask_Final > 0.5;
    
    % 3. 寻找绝对的 Start 和 End time
    % 找到第一个和最后一个为 1 的索引
    start_idx = find(Mask_Final, 1, 'first');
    end_idx = find(Mask_Final, 1, 'last');
    
    start_time = t_frames(start_idx);
    end_time = t_frames(end_idx);
    
    fprintf('Detected Endpoints for %s: Start = %.2f s, End = %.2f s\n\n', filename, start_time, end_time);
    
    % 4. 绘图 Figure 3: Final Detected Endpoints
    figure('Name', ['Combined Detection - ', filename], 'Position',[200, 200, 800, 400]);
    
    plot(t_signal, x, 'Color', [0.7 0.7 0.7]); hold on; % 浅灰色画出原始信号
    
    % 将最终的Mask转换回样本级别的时间点用于高亮显示
    % （这里采用简单的方式：用stairs在同一张图上画出缩放后的Mask包络）
    scaled_mask = Mask_Final * max(x); 
    stairs(t_frames, scaled_mask, 'r', 'LineWidth', 2);
    
    % 画出 Start 和 End markers
    xline(start_time, 'g-', 'Start', 'LineWidth', 2, 'LabelVerticalAlignment', 'bottom');
    xline(end_time, 'm-', 'End', 'LineWidth', 2, 'LabelVerticalAlignment', 'bottom');
    
    title(['Final Endpoint Detection: ', filename]);
    xlabel('Time (s)'); ylabel('Amplitude');
    legend('Signal', 'VAD Mask (Refined)', 'Location', 'best');
    hold off;
    
end