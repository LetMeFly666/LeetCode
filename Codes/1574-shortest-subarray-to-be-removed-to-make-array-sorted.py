'''
Author: LetMeFly
Date: 2023-03-25 09:22:32
LastEditors: LetMeFly
LastEditTime: 2023-03-25 09:52:10
'''
from typing import List

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        right = len(arr) - 1
        while right - 1 >= 0 and arr[right - 1] <= arr[right]:
            right -= 1
        if not right:
            return 0
        ans = right
        for left in range(len(arr)):  # left和right肯定不会相遇
            while right < len(arr) and arr[right] < arr[left]:
                right += 1
            ans = min(ans, right - left - 1)
            if left + 1 < len(arr) and arr[left + 1] < arr[left]:
                break
        return ans