'''
Author: LetMeFly
Date: 2023-08-22 09:13:50
LastEditors: LetMeFly
LastEditTime: 2023-08-22 09:43:52
'''
'''FirstTry RE
class Solution:
    def canChange(self, a: str, b: str) -> bool:
        n = len(a)
        ia, ib = -1, -1
        while ia + 1 < n and ib + 1 < n:
            while ia + 1 < n and a[ia + 1] == '_':
                ia += 1
            ia += 1
            while ib + 1 < n and b[ib + 1] == '_':
                ib += 1
            ib += 1
            if a[ia] != b[ib]:
                return False
            if a[ia] == 'L':  # L
                if ia < ib:
                    return False
            else:  # R
                if ia > ib:
                    return False
        while ia + 1 < n:
            if a[ia + 1] != '_':
                return False
            ia += 1
        while ib + 1 < n:
            if b[ib + 1] != '_':
                return False
            ib += 1
        return True
'''

class Solution:
    def canChange(self, a: str, b: str) -> bool:
        n = len(a)
        ia, ib = 0, 0
        while ia < n and ib < n:
            while ia < n and a[ia] == '_':
                ia += 1
            while ib < n and b[ib] == '_':
                ib += 1
            if ia >= n or ib >= n:
                break
            if a[ia] != b[ib]:
                return False
            if a[ia] == 'L':  # L
                if ia < ib:
                    return False
            else:  # R
                if ia > ib:
                    return False
            ia, ib = ia + 1, ib + 1
        while ia < n:
            if a[ia] != '_':
                return False
            ia += 1
        while ib < n:
            if b[ib] != '_':
                return False
            ib += 1
        return True

if __name__ == '__main__':
    while True:
        a = input()
        b = input()
        sol = Solution()
        print(sol.canChange(a, b))