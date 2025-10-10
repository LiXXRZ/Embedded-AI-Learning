import numpy as np

"""
a = float(input())
b = float(input())
c = (a**2 - b**2) / (40 * 589.3 * 1e-6)
print(c)
"""

# ===== 输入数据 =====
D15_data = [7.803, 7.807, 7.787, 7.790, 7.809, 7.808]  # 单位：mm
D5_data = [5.023, 5.039, 5.030, 4.945, 5.000, 4.998]   # 单位：mm

lambda_nm = 589.3        # 钠光波长（nm）
m = 15                   # 暗环级数m
n = 5                    # 暗环级数n
delta_m = 0.005          # 仪器误差Δ_m（mm）

# ===== 步骤1：计算D15和D5的平均值 =====
D15_mean = np.mean(D15_data)
D5_mean = np.mean(D5_data)

# ===== 步骤2：计算A类不确定度u_A（仅用D15） =====
def calculate_uA(data):
    n = len(data)
    std_dev = np.std(data, ddof=1)  # 样本标准差
    uA = std_dev / np.sqrt(n)
    return uA

uA = calculate_uA(D15_data)  # 仅基于D15的数据计算u_A

# ===== 步骤3：计算B类不确定度u_B =====
uB = delta_m / np.sqrt(3)

# ===== 步骤4：合成不确定度u(D) =====
uD = np.sqrt(uA**2 + uB**2)

# ===== 步骤5：计算曲率半径R（修正单位转换）=====
lambda_mm = lambda_nm * 1e-6       # 正确转换：1 nm = 1e-6 mm
R_mean = (D15_mean**2 - D5_mean**2) / (4 * (m - n) * lambda_mm)  # 单位：mm

# 将R从毫米转换为米
R_mean = R_mean * 1e-3  # 1 mm = 1e-3 m

# ===== 步骤6：计算相对不确定度E(R)（仅分子开根号）=====
numerator = np.sqrt(D15_mean**2 + D5_mean**2)
denominator = D15_mean**2 - D5_mean**2
E_R = 2 * (numerator / denominator) * uD * 100  # 百分比

# ===== 步骤7：计算R的标准不确定度u(R) =====
uR = R_mean * (E_R / 100)

# ===== 结果输出 =====
print(f"1. D15平均值: {D15_mean:.3f} mm")
print(f"   D5平均值: {D5_mean:.3f} mm")
print(f"2. A类不确定度u_A（仅用D15）: {uA:.4f} mm")
print(f"3. B类不确定度u_B: {uB:.4f} mm")
print(f"4. 合成不确定度u(D): {uD:.4f} mm")
print(f"5. 曲率半径R平均值: {R_mean:.3f} m")
print(f"6. 相对不确定度E(R): {E_R:.2f}%")
print(f"7. R的标准不确定度u(R): ±{uR:.3f} m")
print("\n最终结果:")
print(f"R = ({R_mean:.3f} ± {uR:.3f}) m")