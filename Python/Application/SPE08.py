import numpy as np

# ===================================================
# 驻波共振法：最小二乘法计算波长和声速
# ===================================================
def standing_wave_analysis(l_data, f):
    """
    参数：
        l_data: 驻波法记录的12个极大值位置数据（单位：mm）
        f: 谐振频率（单位：kHz）
    返回：
        lambda_sw: 波长（mm）
        v_sw: 声速（m/s）
        u_v_sw: 声速绝对不确定度（m/s）
    """
    # 转换为米
    l_data = np.array(l_data) / 1000  # mm -> m
    f = f * 1e3  # kHz -> Hz

    # 最小二乘法计算斜率k
    x = np.arange(1, len(l_data) + 1)  # 测量次数x=1,2,...,12
    x_mean = np.mean(x)
    y_mean = np.mean(l_data)

    # 计算分子和分母
    numerator = np.mean(x * l_data) - x_mean * y_mean
    denominator = np.mean(x ** 2) - x_mean ** 2
    k = numerator / denominator  # 斜率k = λ/2

    lambda_sw = 2 * k  # 波长（m）
    v_sw = f * lambda_sw  # 声速（m/s）

    # 计算波长的不确定度（B类）
    u_lambda_B = 0.02e-3 / np.sqrt(3)  # 游标卡尺误差Δ=0.02mm
    u_f = 0.001e3 / np.sqrt(3)  # 频率误差Δ=0.001kHz

    # 相对不确定度
    E_v = np.sqrt((u_f / f) ** 2 + (u_lambda_B / lambda_sw) ** 2) * 100
    u_v_sw = v_sw * E_v / 100  # 绝对不确定度

    return lambda_sw * 1000, v_sw, u_v_sw  # 波长转mm，声速单位m/s


# ===================================================
# 相位比较法：逐差法计算波长和声速
# ===================================================
def phase_comparison_analysis(s_data, f):
    """
    参数：
        s_data: 相位比较法记录的12个位置数据（单位：mm）
        f: 频率（单位：kHz）
    返回：
        lambda_pc: 平均波长（mm）
        v_pc: 声速（m/s）
        u_v_pc: 声速绝对不确定度（m/s）
    """
    # 转换为米
    s_data = np.array(s_data) / 1000  # mm -> m
    f = f * 1e3  # kHz -> Hz

    # 逐差法计算波长
    n = len(s_data) // 2
    lambda_list = [(s_data[i + n] - s_data[i]) / n for i in range(n)]
    lambda_pc = np.mean(lambda_list)  # 平均波长（m）

    # 计算A类和B类不确定度
    u_A = np.sqrt(np.sum((lambda_list - lambda_pc) ** 2) / (n * (n - 1)))
    u_B = 0.02e-3 / np.sqrt(3)  # 游标卡尺误差Δ=0.02mm
    u_lambda = np.sqrt(u_A ** 2 + u_B ** 2)

    # 计算声速不确定度
    u_f = 0.001e3 / np.sqrt(3)  # 频率误差Δ=0.001kHz
    E_v = np.sqrt((u_f / f) ** 2 + (u_lambda / lambda_pc) ** 2) * 100  # 相对不确定度（%）
    v_pc = f * lambda_pc  # 声速（m/s）
    u_v_pc = v_pc * E_v / 100  # 绝对不确定度（m/s）

    return lambda_pc * 1000, v_pc, u_v_pc  # 波长转mm，声速单位m/s


# ===================================================
# 理论声速计算（温度修正）
# ===================================================
def theoretical_speed(T):
    v0 = 331.45  # m/s (0°C时的声速)
    v_theory = v0 * np.sqrt(1 + T / 273.15)
    return v_theory


# ===================================================
# 主程序：输入数据并输出结果
# ===================================================
if __name__ == "__main__":
    # 实验数据输入（用户数据）
    l_standing = [89.90, 94.58, 99.20, 103.74, 108.40, 112.96,
                  117.56, 122.16, 126.88, 131.42, 136.08, 140.70]  # 驻波法位置（mm）
    s_phase = [89.82, 99.06, 108.22, 117.40, 126.60, 135.88,
               145.00, 154.18, 163.42, 172.66, 181.84, 191.12]  # 相位法位置（mm）
    f = 37.815  # kHz（谐振频率）
    T = 22.3  # 室温（°C）

    # 数据处理
    lambda_sw, v_sw, u_sw = standing_wave_analysis(l_standing, f)
    lambda_pc, v_pc, u_pc = phase_comparison_analysis(s_phase, f)
    v_theory = theoretical_speed(T)

    # 计算相对误差
    delta_sw = abs((v_sw - v_theory) / v_theory) * 100
    delta_pc = abs((v_pc - v_theory) / v_theory) * 100

    # 打印结果
    print("================ 驻波共振法 ================")
    print(f"波长 λ = {lambda_sw:.2f} mm")
    print(f"声速 v = {v_sw:.1f} ± {u_sw:.1f} m/s")
    print(f"相对误差 δ = {delta_sw:.1f}%")

    print("\n================ 相位比较法 ================")
    print(f"平均波长 λ = {lambda_pc:.2f} mm")
    print(f"声速 v = {v_pc:.1f} ± {u_pc:.1f} m/s")
    print(f"相对误差 δ = {delta_pc:.1f}%")

    print("\n=============== 理论声速 ================")
    print(f"温度 T = {T} °C 时理论声速 = {v_theory:.1f} m/s")