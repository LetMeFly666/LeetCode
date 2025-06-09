'''
Author: LetMeFly
Date: 2025-06-02 16:24:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-02 18:21:35
'''
def generate_strings_from_sequence(seq):
    # 要构造文本长度
    N0 = seq.count('0')
    N1 = seq.count('1')
    N2 = seq.count('2')
    m = N0 + N2
    n = N0 + N1
    L = N0
    
    # 相同的字符、不同的字符
    common_chars = [chr(65 + i) for i in range(L)]  # 'A', 'B', ...
    def unique_char_x(i):
        return f'X{i}'  # 'X0', 'X1'
    def unique_char_y(j):
        return f'Y{j}'  # 'Y0', 'Y1'
    
    text1 = [None] * m
    text2 = [None] * n
    i = m
    j = n
    lcs_index = 0

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
    
    # 构造结束
    if i != 0 or j != 0:
        raise ValueError("无法构造")
    text1_str = ''.join(text1)
    text2_str = ''.join(text2)
    return text1_str, text2_str


# sequence = "0012"
sequence = "21201"
try:
    text1, text2 = generate_strings_from_sequence(sequence)
    print(f"text1: {text1}")
    print(f"text2: {text2}")
except ValueError as e:
    print(e)