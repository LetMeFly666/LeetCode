'''
Author: LetMeFly
Date: 2023-01-20 09:18:55
LastEditors: LetMeFly
LastEditTime: 2023-01-20 09:35:35
'''

if False:  # FirstTry  AC
    from typing import List

    class Solution:
        def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
            ma = {}
            for log in logs:
                if ma.get(log[0]):
                    ma[log[0]].add(log[1])
                else:
                    ma[log[0]] = {log[1]}
            ans = [0 for _ in range(k)]
            for who, what in ma.items():
                ans[len(what) - 1] += 1
            return ans

# SecondTry  优化
"""
1. 使用collections的defaultdict，这样就不需要先特判字典的键值是否已经存在，而是可以直接进行操作
2. 使用ma.values()替换ma.items()，因为统计答案的时候字典的键值是不需要的
"""
from typing import List
from collections import defaultdict


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ma = defaultdict(set)
        for log in logs:
            ma[log[0]].add(log[1])
        ans = [0 for _ in range(k)]  # 或者写成 ans = [0] * k 也可
        for times in ma.values():
            ans[times - 1] += 1
        return ans