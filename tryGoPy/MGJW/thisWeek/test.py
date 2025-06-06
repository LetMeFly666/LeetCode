'''
Author: LetMeFly
Date: 2025-06-02 17:01:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-02 18:12:18
'''
from main import generate_strings_from_sequence

def verify_sequence_from_texts(text1, text2, original_sequence):
    m = len(text1)
    n = len(text2)
    
    # 构建DP表
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    # 回溯路径并记录移动序列
    i, j = m, n
    reconstructed_sequence = []
    
    while i > 0 and j > 0:
        if text1[i-1] == text2[j-1]:
            reconstructed_sequence.append('0')
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            reconstructed_sequence.append('2')
            i -= 1
        else:
            reconstructed_sequence.append('1')
            j -= 1
    
    # 处理剩余的左移或上移
    while i > 0:
        reconstructed_sequence.append('2')
        i -= 1
    while j > 0:
        reconstructed_sequence.append('1')
        j -= 1
    
    # 反转序列因为我们是从后往前构建的
    reconstructed_sequence = ''.join(reconstructed_sequence[::-1])
    
    # 比较重建的序列和原始序列
    if reconstructed_sequence == original_sequence:
        return True, reconstructed_sequence
    else:
        return False, reconstructed_sequence

# 测试用例
test_sequences = [
    "012",    # 简单序列
    "0012",   # 多个匹配
    # "21201",  # 复杂序列
    # "000",    # 只有匹配
    "111",    # 只有左移
    "222",    # 只有上移
    "010101", # 交替模式
    "001122", # 分组模式
]

for seq in test_sequences:
    try:
        text1, text2 = generate_strings_from_sequence(seq)
        print(f"\nTesting sequence: {seq}")
        print(f"Generated text1: {text1}")
        print(f"Generated text2: {text2}")
        
        is_valid, reconstructed_seq = verify_sequence_from_texts(text1, text2, seq)
        if is_valid:
            print("✅ Verification PASSED - Reconstructed sequence matches original")
        else:
            print(f"❌ Verification FAILED - Reconstructed: {reconstructed_seq}, Original: {seq}")
    except ValueError as e:
        print(f"❌ Invalid sequence: {e}")

# 测试无效序列
invalid_sequences = [
    "011",  # 无法回到(0,0)
    "022",  # 无法回到(0,0)
    "112",  # 无法回到(0,0)
]

print("\nTesting invalid sequences:")
for seq in invalid_sequences:
    try:
        text1, text2 = generate_strings_from_sequence(seq)
        print(f"Unexpected success for invalid sequence {seq}")
    except ValueError as e:
        print(f"Correctly detected invalid sequence {seq}: {e}")