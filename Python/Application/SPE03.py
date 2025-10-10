import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置黑体或其他支持中文的字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 然后正常绘制你的图表

# ===== 输入参数 =====
# 基础参数（单位：mm）
L = 720.2          # 钢丝长度
H = 682.7         # 镜轴到标尺距离
D = 38.54          # 光杠杆常数
u_L = 0.5          # L的不确定度
u_H = 0.5          # H的不确定度
u_D = 0.02         # D的不确定度
g = 9.8            # 重力加速度 (m/s²)

# 钢丝直径测量数据（单位：mm，已修正零差）
d_measured = np.array([0.485, 0.485, 0.484, 0.485, 0.485, 0.485])
d0 = -0.03        # 螺旋测微器零差
d = d_measured - d0 # 修正后的直径
d_mean = np.mean(d) # 平均直径
u_di = 0.004       # 单次直径测量仪器误差

# 标尺刻度与拉力数据（单位：mm, kg）
m = np.array([0.00, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00, 7.00])  # 拉力 (kg)
x_plus = np.array([8.0, 12.5, 17.2, 23.4, 32.0, 38.2, 42.9, 44.6])  # 加力时标尺读数
x_minus = np.array([9.2, 13.5, 19.9, 25.8, 32.7, 38.8, 44.4, 49.1]) # 减力时标尺读数

# ===== 数据处理 =====
# 1. 计算平均标尺刻度和标尺变化量
x_avg = (x_plus + x_minus) / 2
delta_x = x_avg - x_avg[0]

print("\n=== 标尺刻度数据处理 ===")
print(f"{'拉力 (kg)':<10} {'加力 x+ (mm)':<15} {'减力 x- (mm)':<15} {'平均 x_avg (mm)':<18} {'Δx (mm)':<10}")
print("-" * 65)
for i in range(len(m)):
    print(f"{m[i]:<10} {x_plus[i]:<15} {x_minus[i]:<15} {x_avg[i]:<18.2f} {delta_x[i]:<10.2f}")

# 2. 计算杨氏模量 E
# 作图法（取首尾两点计算斜率）
k_graph = (delta_x[-1] - delta_x[1]) / (m[-1] - m[1])  # 斜率 (mm/kg)
E_graph = (8 * g * (L/1000) * (H/1000)) / (np.pi * (d_mean/1000)**2 * (D/1000) * k_graph/1000)

# 最小二乘法
n = len(m)
m_kg = m  # 拉力单位已为kg，转换为N: F = m_kg * g
A = np.vstack([m_kg, np.ones(n)]).T
k_ls, _ = np.linalg.lstsq(A, delta_x, rcond=None)[0]
E_ls = (8 * g * (L/1000) * (H/1000)) / (np.pi * (d_mean/1000)**2 * (D/1000) * k_ls/1000)

# 3. 不确定度分析
# 各分量的不确定度
u_d_mean = u_di / np.sqrt(len(d))  # 直径平均值的A类不确定度
u_d_total = np.sqrt(u_d_mean**2 + (0.004/np.sqrt(3))**2)  # 合成不确定度（含B类）

u_E_terms = [
    (u_H / H)**2,
    (u_L / L)**2,
    (u_D / D)**2,
    (2 * u_d_total / d_mean)**2,
    (0.5 / delta_x[-1])**2  # 假设最大Δx的不确定度为0.5mm
]
u_E_relative = np.sqrt(np.sum(u_E_terms))
u_E = E_ls * u_E_relative

# ===== 结果输出 =====
print("=============== 杨氏模量计算结果 ===============")
print(f"[作图法] 斜率 k = {k_graph:.2f} mm/kg")
print(f"        杨氏模量 E = {E_graph/1e11:.2f} x 10^11 N/m²")
print(f"[最小二乘法] 斜率 k = {k_ls:.2f} mm/kg")
print(f"        杨氏模量 E = {E_ls/1e11:.2f} ± {u_E/1e11:.2f} x 10^11 N/m²")
print("==============================================")

# ===== 可视化 =====
plt.figure(figsize=(8, 5))
plt.plot(m, delta_x, 'bo-', label='实验数据')
plt.plot(m, k_ls*m, 'r--', label=f'最小二乘拟合 (k={k_ls:.2f} mm/kg)')
plt.xlabel("拉力 m (kg)", fontsize=12)
plt.ylabel("标尺变化量 Δx (mm)", fontsize=12)
plt.title("拉力-标尺变化量关系", fontsize=14)
plt.legend()
plt.grid(linestyle='--', alpha=0.6)
plt.show()