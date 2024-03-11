'''
Author: LetMeFly
Date: 2024-03-11 09:10:22
LastEditors: LetMeFly
LastEditTime: 2024-03-11 09:23:53
'''
class Solution:
    def capitalizeTitle(self, title: str) -> str:
        shouldUpper = len(title) >= 3 and title[1] != ' ' and title[2] != ' '
        ans_list = []
        for i in range(len(title)):
            if title[i] == ' ':
                shouldUpper = i + 3 < len(title) and title[i + 2] != ' ' and title[i + 3] != ' '
                ans_list.append(' ')  # 不同于可变数组的语言，这里记得也要加上空格
                continue
            ans_list.append(title[i].upper() if shouldUpper else title[i].lower())
            shouldUpper = False
        return ''.join(ans_list)

# sol = Solution()
# print(sol.capitalizeTitle('hi hih oj sojfij ij iej si jfijeiojieojfIJIJ h iHIO'))
