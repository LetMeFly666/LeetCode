'''
Author: LetMeFly
Date: 2022-01-06 15:54:06
LastEditors: LetMeFly
LastEditTime: 2022-01-06 15:59:15
'''
class Solution:
    def simplifyPath(self, path: str) -> str:
        locations = []
        # while "//" in path:
        #     path = path.replace("//", "/")
        dirs = path.split("/")
        for thisDir in dirs:
            if not thisDir or thisDir == ".":
                continue
            if thisDir == "..":  # 往上
                if len(locations):
                    locations.pop()
            else:
                locations.append(thisDir)
        if len(locations) == 0:
            return "/"
        ans = ""
        for thisDir in locations:
            ans += "/" + thisDir
        return ans