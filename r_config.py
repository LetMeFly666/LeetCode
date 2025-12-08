'''
Author: LetMeFly
Date: 2025-12-02 18:42:19
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-02 18:45:46
'''
import configparser
import os
import sys

def load_config():
    """从config.ini加载配置"""
    config = configparser.ConfigParser()

    # 优先从可执行文件所在目录查找config.ini（支持打包后的exe）
    config_path = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 'r_config.ini')

    if not os.path.exists(config_path):
        # 如果exe目录没有，尝试从当前工作目录查找
        config_path = os.path.join(os.getcwd(), 'r_config.ini')

    if not os.path.exists(config_path):
        # 如果config.ini不存在，创建模板
        print(f'未找到配置文件，正在创建模板: {config_path}')
        # create_config_template(config_path)
        print('\n请编辑 config.ini 文件填写你的配置信息后重新运行程序')
        input('按回车键退出...')
        sys.exit(0)

    try:
        config.read(config_path, encoding='utf-8')
        print(f'成功加载配置文件: {config_path}')
        return config
    except Exception as e:
        print(f'读取配置文件失败: {e}')
        input('按回车键退出...')
        sys.exit(1)


config = load_config()
# 打印config中的内容
for section in config.sections():
    print(f'[{section}]')
    for key, value in config.items(section):
        print(f'***{key}***{value}***')
    print()

"""
[Settings]
***headless***false***
***course_url***https://在此填写你的课程URL***
***cookie***在此填写你的sessionid***
***implicitly_wait***10***
"""