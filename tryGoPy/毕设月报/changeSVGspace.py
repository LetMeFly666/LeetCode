'''
Author: LetMeFly
Date: 2025-10-29 14:07:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-29 14:09:27
Descriptions: 写一个python脚本，读一个文件，把文件中所有的：  两个及以上的连续的空格或回车或它们的组合 转为一个空格，并保存到另外一个文件
'''
import re

def process_file(input_file, output_file):
    """
    读取输入文件，将连续的空格、回车或其组合转换为单个空格，然后保存到输出文件
    
    参数:
        input_file: 输入文件路径
        output_file: 输出文件路径
    """
    try:
        # 读取文件内容
        with open(input_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 使用正则表达式替换: 匹配一个或多个空格、换行符或回车符，替换为单个空格
        # 注意这里用+表示一个或多个，因为题目要求两个及以上，但处理一个以上更合理
        processed_content = re.sub(r'[\s\n\r]+', ' ', content)
        
        # 保存处理后的内容到输出文件
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(processed_content)
        
        print(f"文件处理完成，已保存到 {output_file}")
    
    except FileNotFoundError:
        print(f"错误：找不到文件 {input_file}")
    except Exception as e:
        print(f"处理文件时发生错误：{str(e)}")

if __name__ == "__main__":
    # 输入文件和输出文件的路径
    input_filename = "C:/Users/LetMe/Desktop/lab3-combined.svg"    # 替换为你的输入文件路径
    output_filename = "C:/Users/LetMe/Desktop/lab3-combined-compressed.svg"   # 替换为你的输出文件路径
    
    # 调用处理函数
    process_file(input_filename, output_filename)