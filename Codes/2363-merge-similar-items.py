'''
Author: LetMeFly
Date: 2023-02-28 10:13:23
LastEditors: LetMeFly
LastEditTime: 2023-02-28 10:46:10
'''
if False:  # FirstTry  # 方法一：哈希表
    from collections import defaultdict
    from typing import List


    class Solution:
        def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
            ma = defaultdict(int)
            for a, b in items1:
                ma[a] += b
            for a, b in items2:
                ma[a] += b
            return sorted([[a, b] for a, b in ma.items()])


# SecondTry  # 方法二：排序 + 双指针
from typing import List


class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        items1.sort()
        items2.sort()
        ans = []
        l1, l2 = 0, 0
        while l1 < len(items1) and l2 < len(items2):
            if items1[l1][0] == items2[l2][0]:
                ans.append([items1[l1][0], items1[l1][1] + items2[l2][1]])
                l1 += 1
                l2 += 1
            elif items1[l1][0] < items2[l2][0]:
                ans.append(items1[l1])
                l1 += 1
            else:
                ans.append(items2[l2])
                l2 += 1
        while l1 < len(items1):
            ans.append(items1[l1])
            l1 += 1
        while l2 < len(items2):
            ans.append(items2[l2])
            l2 += 1
        return ans