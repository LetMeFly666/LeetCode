'''
Author: LetMeFly
Date: 2025-11-15 20:18:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-11-15 20:21:38
'''
for r100 in range(1, 100):
    r = r100 / 100
    real = r / (1 + r)
    like = r
    print(f"{r100}%/(1+{r100}%)={real:.4f}, like={like:.4f}")