'''
Author: LetMeFly
Date: 2026-02-02 18:50:08
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-02 21:54:33
'''
f1 = 1049.11 - 4.2
f2 = 1050.94 - 4.2
# x * 2 <= f1 + f2
# x <= (f1 + f2) / 2
print((f1 + f2) / 2)  # 1045.825
# 只要小于等于1045.825购入2g就不亏
# 但1045.825购入相当于均价不变
print(f1 + f2)  # 2091.65
# 购买金额2091.65


f3 = 1054.14 - 4.22
total = f1 + f2 + f3
print(total)  # 3141.57
print(total / 3)  # 1047.19


f4 = 1055.64 - 4.22
total = f1 + f2 + f3 + f4
print(total)  # 4192.99
print(total / 4)  # 1048.2475
# buy = total / 4 - 5
buy = 1043
print(buy * 4)

