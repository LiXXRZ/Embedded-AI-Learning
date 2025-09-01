import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import linregress

# ========================================================
# 实验参数设置
# ========================================================
C = 0.5  # 电磁铁线圈常数 (mT/mA)
d = 0.2  # 霍尔元件厚度 (mm) → 需转换为米: 0.2e-3 m
e = 1.6e-19  # 电子电荷量 (C)

# ========================================================
# 表1数据输入: U_H与I_s的关系 (I_M=300mA)
# ========================================================
data_table1 = {
    'I_s (mA)': [1.00, 2.00, 3.00, 4.00, 5.00, 6.00, 7.00, 8.00, 9.00],
    'U1 (mV)': [0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00, 2.25],
    'U2 (mV)': [-0.24, -0.49, -0.74, -0.99, -1.24, -1.49, -1.74, -1.99, -2.24],
    'U3 (mV)': [0.26, 0.51, 0.76, 1.01, 1.26, 1.51, 1.76, 2.01, 2.26],
    'U4 (mV)': [-0.23, -0.48, -0.73, -0.98, -1.23, -1.48, -1.73, -1.98, -2.23]
}

df_table1 = pd.DataFrame(data_table1)
df_table1['U_H (mV)'] = (np.abs(df_table1['U1 (mV)']) + np.abs(df_table1['U2 (mV)'])
                        + np.abs(df_table1['U3 (mV)']) + np.abs(df_table1['U4 (mV)'])) / 4

# ========================================================
# 计算灵敏度 K_H
# ========================================================
# 线性拟合 U_H = K1 * I_s
slope, intercept, r_value, _, _ = linregress(df_table1['I_s (mA)'], df_table1['U_H (mV)'])
K1 = slope  # 单位: mV/mA = V/A

# 计算磁感应强度 B = C * I_M (I_M=300mA)
B = C * 300  # 单位: mT → 转换为特斯拉(T): B * 1e-6
K_H = (K1 * 1e-3) / (B * 1e-3)  # 单位: V/(A·T) → K1(mV/mA)=1e-3 V / 1e-3 A = 1 V/A

# 计算载流子浓度 n = 1/(e*d*K_H)
n = 1 / (e * d*1e-3 * K_H)  # 单位: m^-3

# ========================================================
# 表2数据输入: B与I_M的关系 (I_s=3.00mA)
# ========================================================
data_table2 = {
    'I_M (mA)': [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000],
    'U_H (mV)': [0.15, 0.30, 0.45, 0.60, 0.75, 0.90, 1.05, 1.20, 1.35, 1.50]
}
df_table2 = pd.DataFrame(data_table2)
df_table2['B (mT)'] = (df_table2['U_H (mV)'] * 1e-3) / (K_H * 3e-3)  # B = U_H/(K_H*I_s)

# ========================================================
# 表3数据输入: B的分布 (I_M=600mA, I_s=5.00mA)
# ========================================================
data_table3 = {
    'x (mm)': [0, 2, 4, 6, 8, 10, 12, 15, 20, 25, 30, 35, 40, 45, 50],
    'U_H (mV)': [0.80, 0.78, 0.75, 0.72, 0.70, 0.68, 0.65, 0.60, 0.55, 0.50, 0.45, 0.40, 0.35, 0.30, 0.25]
}
df_table3 = pd.DataFrame(data_table3)
df_table3['B (mT)'] = (df_table3['U_H (mV)'] * 1e-3) / (K_H * 5e-3)  # B = U_H/(K_H*I_s)

# ========================================================
# 可视化
# ========================================================
plt.figure(figsize=(15, 5))

# 1. U_H - I_s 曲线
plt.subplot(1, 3, 1)
plt.scatter(df_table1['I_s (mA)'], df_table1['U_H (mV)'], color='blue', label='实验数据')
plt.plot(df_table1['I_s (mA)'], slope*df_table1['I_s (mA)'] + intercept, 'r--',
         label=f'拟合直线: $K_1$={slope:.3f} mV/mA\n$R^2$={r_value**2:.4f}')
plt.xlabel('工作电流 $I_s$ (mA)')
plt.ylabel('霍尔电压 $U_H$ (mV)')
plt.title('霍尔电压与工作电流关系')
plt.legend()
plt.grid(True)

# 2. B - I_M 曲线
plt.subplot(1, 3, 2)
plt.scatter(df_table2['I_M (mA)'], df_table2['B (mT)'], color='green')
plt.plot(df_table2['I_M (mA)'], C * df_table2['I_M (mA)'], 'r--',
         label=f'理论值: $B = C \cdot I_M$\n$C$={C} mT/mA')
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

# ========================================================
# 输出关键结果
# ========================================================
print(f'[计算结果]')
print(f'1. 斜率 K1 = {K1:.3f} mV/mA')
print(f'2. 灵敏度 K_H = {K_H:.4e} V/(A·T)')
print(f'3. 载流子浓度 n = {n:.2e} m^-3')