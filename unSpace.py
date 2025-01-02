'''
Author: LetMeFly
Date: 2025-01-02 15:48:53
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-02 15:49:08
'''
def remove_indentation_and_blank_lines(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as infile, open(output_file, 'w', encoding='utf-8') as outfile:
        for line in infile:
            # 删除行首空格
            stripped_line = line.lstrip()
            # 如果行不为空，则写入输出文件
            if stripped_line:
                outfile.write(stripped_line)

# 示例调用
input_file = 'C:/Users/LetMeFly/Desktop/d-3.html'  # 输入文件路径
output_file = 'C:/Users/LetMeFly/Desktop/d-4.html'  # 输出文件路径
remove_indentation_and_blank_lines(input_file, output_file)