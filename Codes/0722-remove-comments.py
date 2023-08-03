'''
Author: LetMeFly
Date: 2023-08-03 07:54:54
LastEditors: LetMeFly
LastEditTime: 2023-08-03 08:14:33
'''
from typing import List

class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans = []
        findingEnd = False
        thisLine = ''
        for s in source:
            i = 0
            while i < len(s):
                if findingEnd:
                    if s[i] == '*' and i + 1 < len(s) and s[i + 1] == '/':
                        findingEnd = False
                        i += 1
                else:
                    if s[i] == '/' and i + 1 < len(s) and s[i + 1] == '*':
                        findingEnd = True
                        i += 1
                    elif s[i] == '/' and i + 1 < len(s) and s[i + 1] == '/':
                        break
                    else:
                        thisLine += s[i]
                i += 1
            if not findingEnd and len(thisLine):
                ans.append(thisLine)
                thisLine = ''
        return ans



# """
# i begin: 0
# i end: 3  
# i begin: 1
# i end: 4  
# i begin: 2
# i end: 5  
# i begin: 3
# i end: 6  
# i begin: 4
# i end: 7
# """
# for i in range(5):
#     print(f'i begin: {i}')
#     i += 3
#     print(f'i end: {i}')
