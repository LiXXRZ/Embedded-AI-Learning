import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import linregress

# ================ 设置中文字体 ================
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定黑体（根据系统安装的字体调整）
plt.rcParams['axes.unicode_minus'] = False    # 解决负号显示问题

# ================ 实验参数 ================
C = 0.262  # 电磁铁线圈常数 (mT/mA)
d = 0.26  # 霍尔元件厚度 (mm)
e = 1.6e-19  # 电子电荷量 (C)

# ================ 表1数据处理 ================
data_table1 = {
    'I_s (mA)': [1.00, 2.00, 3.00, 4.00, 5.00, 6.00, 7.00, 8.00, 9.00],
    'U1 (mV)': [14.1, 28.2, 42.3, 56.4, 70.6, 84.4, 98.7, 112.7, 126.7],
    'U2 (mV)': [-14.0, -27.9, -41.8, -55.7, -69.6, -83.5, -97.3, -111.1, -124.8],
    'U3 (mV)': [14.0, 27.9, 41.8, 55.7, 69.6, 83.5, 97.3, 111.1, 124.8],
    'U4 (mV)': [-14.1, -28.2, -42.3, -56.4, -70.6, -84.4, -98.7, -112.7, -126.7]
}
df_table1 = pd.DataFrame(data_table1)
df_table1['U_H (mV)'] = (np.abs(df_table1['U1 (mV)']) + np.abs(df_table1['U2 (mV)'])
                        + np.abs(df_table1['U3 (mV)']) + np.abs(df_table1['U4 (mV)'])) / 4

# ================ 计算灵敏度K_H ================
slope, intercept, r_value, _, _ = linregress(df_table1['I_s (mA)'], df_table1['U_H (mV)'])
K1 = slope  # 单位: mV/mA
B = C * 300  # I_M=300mA时磁感应强度 (mT)
K_H = K1 / (B * 1e-3)  # 单位: V/(A·T)
n = 1 / (e * d*1e-3 * K_H)  # 载流子浓度

# ================ 表2数据处理 ================
data_table2 = {
    'I_M (mA)': [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000],
    'U_H (mV)': [14.1, 28.0, 42.0, 55.9, 70.0, 84.0, 97.9, 111.75, 125.5, 138.9]
}
df_table2 = pd.DataFrame(data_table2)
df_table2['B (mT)'] = (df_table2['U_H (mV)'] * 1e-3) / (K_H * 3e-3) * 1e3  # B = U_H/(K_H*I_s)

# ================ 表3数据处理 ================
data_table3 = {
    'x (mm)': [0, 2, 4, 6, 8, 10, 12, 15, 20, 25, 30, 35, 40, 45, 48, 50],
    'U_H (mV)': [78.45, 101.9, 123.8, 134.75, 138.15, 138.95, 139.15, 139.3, 139.35, 139.4, 139.4, 139.2, 136.9, 100.2, 67.5, 53.95]
}
df_table3 = pd.DataFrame(data_table3)
df_table3['B (mT)'] = (df_table3['U_H (mV)'] * 1e-3) / (K_H * 5e-3) * 1e3

# ================ 绘图 ================
plt.figure(figsize=(15, 5))

# 1. U_H - I_s 曲线
plt.subplot(1, 3, 1)
plt.scatter(df_table1['I_s (mA)'], df_table1['U_H (mV)'], color='blue', label='实验数据')
plt.plot(df_table1['I_s (mA)'], slope*df_table1['I_s (mA)'] + intercept, 'r--',
         label=rf'拟合直线: $K_1$={slope:.3f} mV/mA\n$R^2$={r_value**2:.4f}')
plt.xlabel('工作电流 $I_s$ (mA)')
plt.ylabel('霍尔电压 $U_H$ (mV)')
plt.title('霍尔电压与工作电流关系')
plt.legend()
plt.grid(True)

# 2. B - I_M 曲线（修正转义字符）
plt.subplot(1, 3, 2)
plt.scatter(df_table2['I_M (mA)'], df_table2['B (mT)'], color='green')
plt.plot(df_table2['I_M (mA)'], C * df_table2['I_M (mA)'], 'r--',
         label=rf'理论值: $B = C \cdot I_M$\n$C$={C} mT/mA')  # 使用原始字符串
plt.xlabel('励磁电流 $I_M$ (mA)')
plt.ylabel('磁感应强度 $B$ (mT)')
plt.title('磁场与励磁电流关系')
plt.legend()
plt.grid(True)

# 3. B - x 分布曲线
plt.subplot(1, 3, 3)
plt.plot(df_table3['x (mm)'], df_table3['B (mT)'], 'o-', color='purple')
plt.xlabel('水平位置 $x$ (mm)')
plt.ylabel('磁感应强度 $B$ (mT)')
plt.title('电磁铁气隙磁场分布')
plt.grid(True)

plt.tight_layout()
plt.show()

# ================ 输出结果 ================
print(f'[计算结果]')
print(f'1. 斜率 K1 = {K1:.3f} mV/mA')
print(f'2. 灵敏度 K_H = {K_H:.4e} V/(A·T)')
print(f'3. 载流子浓度 n = {n:.2e} m^-3')

# 表格输出功能
# ========================================================

def print_formatted_table(df, title):
    """格式化输出表格"""
    print(f"\n{title}")
    print("-" * 80)
    print(df.to_string(index=False, float_format="%.2f"))
    print("-" * 80)

# 表1输出：添加理论霍尔电压计算
df_table1['U_H理论 (mV)'] = K1 * df_table1['I_s (mA)']
print_formatted_table(df_table1, "表1 霍尔电压与工作电流关系 (I_M=300mA)")

# 表2输出：添加理论磁场计算
df_table2['B理论 (mT)'] = C * df_table2['I_M (mA)']
print_formatted_table(df_table2, "表2 磁场与励磁电流关系 (I_s=3.00mA)")

# 表3输出：添加相对误差计算
center_B = df_table3[df_table3['x (mm)'] == 0]['B (mT)'].values[0]
df_table3['B/B0 (%)'] = 100 * df_table3['B (mT)'] / center_B
print_formatted_table(df_table3, "表3 电磁铁气隙磁场分布 (I_M=600mA, I_s=5.00mA)")

# 输出统计信息
print("\n[统计摘要]")
print(f"1. 霍尔电压范围: {df_table1['U_H (mV)'].min():.2f} ~ {df_table1['U_H (mV)'].max():.2f} mV")
print(f"2. 磁场强度范围: {df_table2['B (mT)'].min():.2f} ~ {df_table2['B (mT)'].max():.2f} mT")
print(f"3. 磁场均匀性: 中心磁场 {center_B:.2f} mT, 边缘衰减至 {df_table3['B (mT)'].iloc[-1]:.2f} mT")