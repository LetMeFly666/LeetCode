'''
Author: LetMeFly
Date: 2026-07-24 22:05:18
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-25 22:39:38
Description: 在支持OSC8协议的终端输出自定义显示文字的超链接
Description: https://gist.github.com/LetMeFly666/a15181a9edfcd25b2d60b3decb9f2dfd
'''
def osc8(link: str, text: str) -> str:
    return f"\033]8;;{link}\033\\{text}\033]8;;\033\\"

print(osc8('https://letmefly.xyz?from=terminalOSC8_20260726', '宝藏小网站'))
print("see", osc8('https://github.com/LetMeFly666/LeetCode/blob/2392b92a4320ed9101a7cd816079513c78fd70f6/Solutions/Other-Accumulation-SomeTips.md?plain=1#L1932-L1955', 'Github@LeetCode'), "for more")
