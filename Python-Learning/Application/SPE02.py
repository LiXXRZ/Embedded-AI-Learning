import numpy as np

def dms_to_minutes(theta_dms):
    """将度分格式转换为总分数（如114.25 → 114°25' → 114*60 +25 = 6865'）"""
    degrees = np.floor(theta_dms)
    minutes = (theta_dms - degrees) * 100
    return degrees * 60 + minutes

def minutes_to_dms(total_minutes, precision=0):
    """
    将总分数转换为度分格式
    :param total_minutes: 总分数（如6865.5'）
    :param precision: 分的小数位数
    :return: 格式化字符串（如114°25.5'）
    """
    degrees = int(total_minutes // 60)
    minutes = total_minutes % 60

    # 处理进位逻辑
    if minutes >= 60:
        degrees += 1
        minutes -= 60
    elif minutes < 0:
        degrees -= 1
        minutes += 60

    if precision == 0:
        return f"{int(degrees)}°{int(round(minutes))}'"
    else:
        return f"{int(degrees)}°{minutes:.{precision}f}'"

def calculate_alpha_in_minutes(theta1_min, theta2_min, theta1_p_min, theta2_p_min, method='autocollimation'):
    """
    以分为单位计算顶角
    :param theta1_min: 游标1初始读数（分）
    :param theta2_min: 游标2初始读数（分）
    :param theta1_p_min: 游标1另一位置读数（分）
    :param theta2_p_min: 游标2另一位置读数（分）
    :param method: 'autocollimation' 或 'reflection'
    :return: 顶角α（分）
    """
    def correct_delta(theta, theta_p):
        delta = np.abs(theta_p - theta)
        return np.where(delta > 180*60, 360*60 - delta, delta)  # 分单位下的180°=10800'

    delta_theta1 = correct_delta(theta1_min, theta1_p_min)
    delta_theta2 = correct_delta(theta2_min, theta2_p_min)

    if method == 'autocollimation':
        alpha_min = 180*60 - 0.5 * (delta_theta1 + delta_theta2)
    elif method == 'reflection':
        alpha_min = 0.25 * (delta_theta1 + delta_theta2)
    else:
        raise ValueError("方法需为 'autocollimation' 或 'reflection'")
    return alpha_min

# ===== 输入数据（直接以度分格式转换为分） =====
theta1_min = np.array([dms_to_minutes(t) for t in [114.25, 135.44, 112.54, 91.22, 75.33, 58.46]])
theta2_min = np.array([dms_to_minutes(t) for t in [294.24, 315.43, 292.53, 271.21, 255.33, 238.47]])
theta1_p_min = np.array([dms_to_minutes(t) for t in [234.23, 255.43, 232.52, 211.18, 195.32, 178.46]])
theta2_p_min = np.array([dms_to_minutes(t) for t in [54.22, 75.42, 52.53, 31.19, 15.33, 358.47]])

# ===== 计算顶角（分单位） =====
alpha_values_min = calculate_alpha_in_minutes(theta1_min, theta2_min, theta1_p_min, theta2_p_min, method='autocollimation')
alpha_mean_min = np.mean(alpha_values_min)

# ===== 不确定度计算（分单位） =====
n = len(alpha_values_min)
uA_min = np.std(alpha_values_min, ddof=1) / np.sqrt(n)  # A类不确定度（分）
delta_m_min = 1  # 仪器误差1'（直接以分为单位）
uB_min = delta_m_min / np.sqrt(3)  # B类不确定度（分）
u_alpha_min = np.sqrt(uA_min**2 + uB_min**2)  # 合成不确定度（分）
E_alpha = (u_alpha_min / alpha_mean_min) * 100  # 相对不确定度（百分比）

# ===== 结果输出（转换回度分格式） =====
print("============= 分光计实验数据处理（分单位计算） =============")
print("1. 顶角测量值（6次，保留两位小数分）:")
for i, alpha_min in enumerate(alpha_values_min):
    print(f"   第{i+1}次: {minutes_to_dms(alpha_min, precision=2)}")

print("\n2. 顶角平均值:")
print(f"   α_mean = {minutes_to_dms(alpha_mean_min, precision=2)}")

print("\n3. 不确定度计算（保留两位小数分）:")
print(f"   uA = {minutes_to_dms(uA_min, precision=2)}")
print(f"   uB = {minutes_to_dms(uB_min, precision=2)}")
print(f"   u(α) = {minutes_to_dms(u_alpha_min, precision=2)}")

print("\n4. 相对不确定度:")
print(f"   E(α) = {E_alpha:.2f}%")

print("\n5. 最终结果表达式:")
print(f"   α = ({minutes_to_dms(alpha_mean_min, precision=2)} ± {minutes_to_dms(u_alpha_min, precision=2)})")