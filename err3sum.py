'''
Author: LetMeFly
Date: 2026-01-28 23:45:44
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-28 23:45:44
'''
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        print(nums)
        left = 0
        right = len(nums) - 1
        mid = (left+right) // 2
        result = set()
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] > -(nums[left]+nums[right]):
                for i in range(left,mid):
                    if nums[left]+nums[right]+nums[i] == 0  and left<right and left<i and right>i:
                        if tuple(sorted([nums[left], nums[right], nums[i]])) not in result:
                            result.add(tuple(sorted([nums[left], nums[right], nums[i]])))
                right -= 1
                    
            elif nums[mid] < -(nums[left]+nums[right]):
                for i in range(mid+1,right):
                    if nums[left]+nums[right]+nums[i] == 0 and left<right and left<i and right>i:
                        if tuple(sorted([nums[left], nums[right], nums[i]])) not in result:
                            result.add(tuple(sorted([nums[left], nums[right], nums[i]])))
                left+=1
            else:
                if left<right and left<mid and right>mid:
                    if tuple(sorted([nums[left], nums[right], nums[mid]])) not in result:
                        result.add(tuple(sorted([nums[left], nums[right], nums[mid]])))
                left+=1
            
        return [list(t) for t in result]

print(Solution.threeSum(None, [-2, 0, 1, 1, 2]))