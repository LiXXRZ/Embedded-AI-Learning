import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import linregress

plt.rcParams['font.sans-serif'] = ['SimHei']  # 解决中文显示问题
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# ===== 模拟实验数据（需替换为实际数据）=====
# 限流特性数据 (RL/R, R_AC/R, I)
current_limiting_data = {
    0.5: [0.0, 0.2, 0.4, 0.6, 0.8, 1.0],
    'I': {
        0.5: [5.00 , 3.21, 2.72, 2.07, 1.85, 1.43],  # 示例数据
        1: [4.99, 4.17, 3.54, 3.09, 2.74, 2.44],
        5: [4.99, 4.80, 4.62, 4.42, 4.27, 4.08]
    }
}

# 分压特性数据 (RL/R, R_AC/R, V)
voltage_divider_data = {
    0.1: [0.0, 0.2, 0.4, 0.6, 0.8, 1.0],
    'V': {
        0.1: [0.00, 0.398, 0.611, 0.942, 1.713, 5.006],  # 示例数据
        1: [0.00, 0.861, 1.612, 2.469, 3.509, 5.001],
        10: [0.00, 0.987, 1.972, 2.997, 4.054, 5.000]
    }
}

# 二极管特性数据
V = np.array([0.40, 0.50, 0.54, 0.58, 0.59, 0.60, 0.61, 0.62, 0.63, 0.64, 0.68, 0.72])
I = np.array([0.00, 0.07, 0.21, 0.55, 0.70, 0.88, 1.11, 1.40, 1.77, 2.26, 5.67, 14.20])


# ===== 限流特性分析 =====
def analyze_current_limiting():
    plt.figure(figsize=(12, 5))

    # I/I0 曲线
    plt.subplot(121)
    for rl_ratio in [0.5, 1, 5]:
        R_AC = np.array(current_limiting_data[0.5])
        I = np.array(current_limiting_data['I'][rl_ratio])
        I0 = max(I)  # 假设I0是滑动端在A端时的电流
        plt.plot(R_AC, I / I0, 'o-', label=f'R_L/R={rl_ratio}')

    plt.xlabel('R_AC/R')
    plt.ylabel('I/I0')
    plt.title('限流特性曲线')
    plt.legend()
    plt.grid()

    # I0/I 线性拟合
    plt.subplot(122)
    for rl_ratio in [0.5, 1, 5]:
        R_AC = np.array(current_limiting_data[0.5])
        I = np.array(current_limiting_data['I'][rl_ratio])
        I0 = max(I)
        y = I0 / I
        slope, intercept, r_value, _, _ = linregress(R_AC, y)

        plt.plot(R_AC, y, 'o', label=f'R_L/R={rl_ratio}')
        plt.plot(R_AC, slope * R_AC + intercept, '--',
                 label=f'拟合: y={slope:.2f}x+{intercept:.2f}')

        # 根据斜率计算 R_L/R
        calc_rl_ratio = 1 / slope
        print(
            f'设定值 R_L/R={rl_ratio}, 计算值={calc_rl_ratio:.2f}, 误差={abs(rl_ratio - calc_rl_ratio) / rl_ratio * 100:.1f}%')

    plt.xlabel('R_AC/R')
    plt.ylabel('I0/I')
    plt.title('线性拟合分析')
    plt.legend()
    plt.grid()
    plt.tight_layout()
    plt.show()


# ===== 分压特性分析 =====
def analyze_voltage_divider():
    plt.figure(figsize=(8, 5))
    for rl_ratio in [0.1, 1, 10]:
        R_AC = np.array(voltage_divider_data[0.1])
        V = np.array(voltage_divider_data['V'][rl_ratio])
        V0 = max(V)  # 假设V0是滑动端在B端时的电压
        plt.plot(R_AC, V / V0, 'o-', label=f'R_L/R={rl_ratio}')

    plt.xlabel('R_AC/R')
    plt.ylabel('V/V0')
    plt.title('分压特性曲线')
    plt.legend()
    plt.grid()
    plt.show()


# ===== 执行分析 =====
analyze_current_limiting()
analyze_voltage_divider()


# 绘制曲线
plt.figure(figsize=(10, 6))
plt.plot(V, I, 'ro-', linewidth=1.5, markersize=8, label='实验数据')  # 数据点用红色圆圈标记
plt.xlabel('电压 $V$ (V)', fontsize=12)
plt.ylabel('电流 $I$ (mA)', fontsize=12)
plt.title('二极管正向伏安特性曲线', fontsize=14)
plt.grid(True, linestyle='--', alpha=0.6)

# 标注阈值电压和关键区域
plt.axvline(x=0.6, color='blue', linestyle='--', linewidth=1, label='阈值电压 ($V_{\\text{th}} = 0.6$ V)')
plt.fill_betweenx(I, 0.4, 0.6, color='lightgray', alpha=0.3, label='截止区')
plt.fill_betweenx(I, 0.6, 0.72, color='lightgreen', alpha=0.3, label='导通区')

# 添加数据标签（可选）
for i, (x, y) in enumerate(zip(V, I)):
    if i % 2 == 0:  # 每隔一个点标注
        plt.text(x, y, f'({x:.2f}V, {y:.2f}mA)', fontsize=8, ha='left', va='bottom')

plt.legend()
plt.show()