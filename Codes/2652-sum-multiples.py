'''
Author: LetMeFly
Date: 2023-10-17 09:27:31
LastEditors: LetMeFly
LastEditTime: 2023-10-17 09:28:35
'''
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(k: int) -> int:
            return (k + n // k * k) * (n // k) // 2
        return f(3) + f(5) + f(7) - f(15) - f(21) - f(35) + f(105)