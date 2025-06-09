'''
Author: LetMeFly
Date: 2025-06-02 16:24:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-02 16:32:09
'''
def generate_strings_from_sequence(seq):
    # 统计0,1,2的数量
    N0 = seq.count('0')
    N1 = seq.count('1')
    N2 = seq.count('2')
    
    # 计算文本长度
    m = N0 + N2  # text1 长度
    n = N0 + N1  # text2 长度
    L = N0       # LCS 长度
    
    # 初始化字符列表：公共字符用于匹配，唯一字符用于不匹配
    common_chars = [chr(65 + i) for i in range(L)]  # 'A', 'B', ... (最多L个)
    # 唯一字符生成器函数
    def unique_char_x(i):
        return f'X{i}'  # 例如 'X0', 'X1'
    def unique_char_y(j):
        return f'Y{j}'  # 例如 'Y0', 'Y1'
    
    # 初始化 text1 和 text2 为 None 列表
    text1 = [None] * m
    text2 = [None] * n
    
    # 初始化位置和公共字符索引
    i = m
    j = n
    lcs_index = 0  # 公共字符指针
    
    # 遍历序列
    for move in seq:
        if move == '0':  # 左上
            if text1[i-1] is None:
                text1[i-1] = common_chars[lcs_index]
            if text2[j-1] is None:
                text2[j-1] = common_chars[lcs_index]
            lcs_index += 1
            i -= 1
            j -= 1
        elif move == '1':  # 左
            if text2[j-1] is None:
                text2[j-1] = unique_char_y(j-1)
            if text1[i-1] is None:
                text1[i-1] = unique_char_x(i-1)
            j -= 1
        elif move == '2':  # 上
            if text1[i-1] is None:
                text1[i-1] = unique_char_x(i-1)
            if text2[j-1] is None:
                text2[j-1] = unique_char_y(j-1)
            i -= 1
    
    # 检查是否到达 (0,0)
    if i != 0 or j != 0:
        raise ValueError("Invalid sequence: path does not end at (0,0)")
    
    # 转换为字符串
    text1_str = ''.join(text1)
    text2_str = ''.join(text2)
    return text1_str, text2_str

# 示例使用
sequence = "0012"
sequence = "21201"
try:
    text1, text2 = generate_strings_from_sequence(sequence)
    print(f"Generated text1: {text1}")
    print(f"Generated text2: {text2}")
except ValueError as e:
    print(e)