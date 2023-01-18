# -*- coding: utf-8 -*-
'''
Author: LetMeFly
Date: 2023-01-15 10:05:46
LastEditors: LetMeFly
LastEditTime: 2023-01-18 10:05:42
'''
datas = """|0009.回文数|简单|<a href="https://leetcode.cn/problems/palindrome-number/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/10/31/LeetCode%200009.%E5%9B%9E%E6%96%87%E6%95%B0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/127609755" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/palindrome-number/solution/letmefly-9hui-wen-shu-by-tisfy-3qoq/" target="_blank">地址点我</a>|
|0049.字母异位词分组|中等|<a href="https://leetcode.cn/problems/group-anagrams/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200049.%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D%E5%88%86%E7%BB%84/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972260" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/group-anagrams/solution/by-tisfy-v56n/" target="_blank">地址点我</a>|
|0050.Pow(x, n)|中等|<a href="https://leetcode.cn/problems/powx-n/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200050.Pow(x,%20n)/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972517" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/powx-n/solution/by-tisfy-8ort/" target="_blank">地址点我</a>|
"""

newData = ""

for line in datas.split("\n"):
    if not line:
        continue
    thisLine = line.split("|")
    newData += "|" + thisLine[1] + "|" + thisLine[2] + "|" + thisLine[3].replace("地址点我", "题目地址") + "|" + thisLine[4].replace("地址点我", "题解地址") + "|" + thisLine[5].replace("地址点我", "CSDN题解") + "|" + thisLine[6].replace("地址点我", "LeetCode题解") + "|\n"


with open("newData.txt", "w", encoding="utf-8") as f:
    f.write(newData)
