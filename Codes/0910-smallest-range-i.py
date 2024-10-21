'''
Author: LetMeFly
Date: 2024-10-21 23:02:04
LastEditors: LetMeFly
LastEditTime: 2024-10-21 23:14:15
'''
from typing import List

class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(len(nums) - 1):
            ans = min(ans, max(nums[i] + k, nums[-1] - k) - min(nums[i + 1] - k, nums[0] + k))
        return ans


"""
Cannot version:

```
class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[-1] - nums[0], min(max(nums[i] + k, nums[-1] - k) - min(nums[i + 1] - k, nums[0] + k) for i in range(len(nums) - 1)))
```

ValueError: min() arg is an empty sequence
                                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    return min(nums[-1] - nums[0], min(max(nums[i] + k, nums[-1] - k) - min(nums[i + 1] - k, nums[0] + k) for i in range(len(nums) - 1)))
Line 12 in smallestRangeII (Solution.py)
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    ret = Solution().smallestRangeII(param_1, param_2)
Line 43 in _driver (Solution.py)
    _driver()
Line 58 in <module> (Solution.py)
"""