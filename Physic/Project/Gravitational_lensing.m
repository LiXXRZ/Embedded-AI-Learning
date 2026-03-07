function lens_simulation()

% 创建主窗口
h.fig = figure('Position', [100 100 800 800], ...
    'Name', '引力透镜模拟器', ...
    'NumberTitle', 'off');

% 物理常数
G = 6.67430e-11;      % 引力常数 [m³ kg⁻¹ s⁻²]
c = 299792458;        % 光速 [m/s]
D_d = 1.0e21;         % 观测者到透镜的距离 [m]
D_s = 1.5e21;         % 观测者到光源的距离 [m]
% 注意：此处D_ds为简化处理，实际应为角直径距离
D_ds = D_s - D_d;     % 简化假设下的共动距离

% 创建滑块控制质量
h.slider = uicontrol(h.fig, ...
    'Style', 'slider', ...
    'Position', [100 100 600 30], ...
    'Min', 5e14, ...
    'Max', 2e18, ...
    'Value', 5e14, ...
    'Tag', 'MassSlider');

% 质量读数显示
h.massDisplay = uicontrol(h.fig, ...
    'Style', 'text', ...
    'Position', [250 70 300 20], ...
    'String', '透镜质量: 2.0e+15 kg', ...
    'Tag', 'MassDisplay');

% 创建图像区域
h.axes = axes(h.fig, 'Position', [0.1 0.3 0.8 0.6]);

% 设置滑块的回调函数
set(h.slider, 'Callback', @update_lens);

% 初始化模拟
update_lens(h.slider, []); % 初始化时传递空事件数据

% 更新函数定义（关键修正）
function update_lens(src, ~) % 添加 ~ 忽略第二个参数
    % 获取当前质量值
    M = get(src, 'Value');
    
    % 更新质量读数显示
    set(findobj(src.Parent, 'Tag', 'MassDisplay'), 'String', sprintf('透镜质量: %.1e kg', M));
    
    % 计算爱因斯坦环半径
    theta_E = sqrt((4*G*M / c^2) * (D_ds / (D_d * D_s)));
    
    % 计算网格
    grid_size = 600;
    x_range = 5 * theta_E;
    [X, Y] = meshgrid(linspace(-x_range, x_range, grid_size));
    
    % 计算光线偏转
    theta = sqrt(X.^2 + Y.^2) + eps;
    deflection = theta_E^2 ./ theta;
    
    % 反向光线追踪
    X_source = X - deflection .* X ./ theta;
    Y_source = Y - deflection .* Y ./ theta;
    
    % 光源模型（高斯分布）
    source_intensity = exp(-(X_source.^2 + Y_source.^2) / (0.6*theta_E)^2);
    
    % 更新图像显示
    imagesc(h.axes, linspace(-x_range, x_range, grid_size), ...
           linspace(-x_range, x_range, grid_size), ...
           source_intensity);
    colormap(h.axes, 'hot');
    colorbar(h.axes);
    axis(h.axes, 'image');
    title(h.axes, sprintf('引力透镜效应模拟\nM=%.1e kg', M), 'FontSize', 14);
    xlabel(h.axes, '观测平面X轴 (rad)');
    ylabel(h.axes, '观测平面Y轴 (rad)');
    
    % 添加比例标注
    line_length = 2 * theta_E;
    start_x = 0.8 * x_range - line_length;
    start_y = 0.85 * x_range;
    end_x = start_x + line_length;
    end_y = start_y;
    
    hold(h.axes, 'on');
    plot(h.axes, [start_x, end_x], [start_y, end_y], 'w-', 'LineWidth', 2);
    text(h.axes, (start_x + end_x)/2, start_y + 0.05*x_range, ...
        sprintf('2θ_E = %.2e rad', line_length), ...
        'Color', 'white', 'FontSize', 10, 'HorizontalAlignment', 'center');
    hold(h.axes, 'off');
end

end