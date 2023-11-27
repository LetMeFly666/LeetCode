'''
Author: LetMeFly
Date: 2023-11-27 18:37:52
LastEditors: LetMeFly
LastEditTime: 2023-11-27 18:39:32
'''
from typing import List

MOD = 1000000007
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        st = [-1]
        arr.append(-1)
        ans = 0
        for i in range(len(arr)):
            while len(st) > 1 and arr[i] < arr[st[-1]]:
                last = st.pop()
                ans = (ans + arr[last] * (last - st[-1]) * (i - last)) % MOD
            st.append(i)
        return ans