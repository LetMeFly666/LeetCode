'''
Author: LetMeFly
Date: 2025-03-09 12:37:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-09 12:47:10
'''
solutionURLlc = 'https://leetcode.cn/problems/split-with-minimum-sum/solutions/2473429/letmefly-2578zui-xiao-he-fen-ge-tan-xin-pxbyl'
def getProblemUrl():
    tempUrl = solutionURLlc
    if tempUrl[len(tempUrl) - 1] != '/':
        tempUrl += "/"
    splitedUrl = tempUrl.split("/")
    print(splitedUrl)
    del splitedUrl[len(splitedUrl) - 2]  # letmefly-2578zui-xiao-he-fen-ge-tan-xin-pxbyl
    del splitedUrl[len(splitedUrl) - 2]  # 2473429
    del splitedUrl[len(splitedUrl) - 2]  # solutions
    print(splitedUrl)
    return "/".join(splitedUrl)

print(getProblemUrl())
print(solutionURLlc)