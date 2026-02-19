'''
Author: LetMeFly
Date: 2026-02-19 17:44:50
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-19 18:18:32
'''
"""
你要做的是：
针对C++源码的头部：
/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:22:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
仅仅保留：
/*
 * @LastEditTime: 2026-02-19 11:22:35
 */
针对Python源码的头部：
'''
Author: LetMeFly
Date: 2026-02-19 11:16:44
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-19 11:33:22
'''
仅仅保留：

'''
LastEditTime: 2026-02-19 11:33:22
'''
Java头部、rust头部、golang头部
/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:30:02
 */
仅仅保留：
/*
 * @LastEditTime: 2026-02-19 11:30:02
 */

请保持最小改动原则，不要修改多余代码，完成代码文件头部的filter

def removePrefix(data: str, fileType: str) -> str:
    def main(data: str, fileType: str) -> str:
        在这里实现
fileType是 ('cpp', 'java', 'rs', 'go', 'py')
"""
import re

def removePrefix(data: str, fileType: str) -> str:
    def main(data: str, fileType: str) -> str:  # (#1399)
        if fileType == 'cpp':
            # 1. 处理 /* ... */ 头部注释
            m = re.match(r'(/\*[\s\S]*?\*/)([\s\S]*)', data)
            if not m:
                return data

            comment, rest = m.groups()

            # 只保留 LastEditTime 行
            lines = comment.splitlines()
            kept = []
            for line in lines:
                if 'LastEditTime' in line:
                    kept.append(line)
                elif line.strip().startswith('/*') or line.strip().startswith('*/'):
                    kept.append(line)

            new_comment = '\n'.join(kept)

            # 2. 删除紧跟的单行 #if defined(...) #include "_[1,2]toVector.h" #endif
            rest = re.sub(
                r'^\s*#if\s+defined\([^\)]*\)(?:\s*\|\|\s*defined\([^\)]*\))*\s*\n\s*#include\s+"_\[1,2\]toVector\.h"\s*\n\s*#endif\s*\n?',
                '',
                rest,
                count=1
            )

            return new_comment + '\n' + rest.lstrip('\n')

        elif fileType == 'py':
            m = re.match(r"('''[\s\S]*?''')([\s\S]*)", data)
            if not m:
                return data

            comment, rest = m.groups()

            lines = comment.splitlines()
            kept = []
            for line in lines:
                if 'LastEditTime' in line:
                    kept.append(line)
                elif line.strip() == "'''":
                    kept.append(line)

            new_comment = '\n'.join(kept)
            return new_comment + '\n' + rest.lstrip('\n')

        elif fileType in ('java', 'rs', 'go'):
            m = re.match(r'(/\*[\s\S]*?\*/)([\s\S]*)', data)
            if not m:
                return data

            comment, rest = m.groups()

            lines = comment.splitlines()
            kept = []
            for line in lines:
                if 'LastEditTime' in line:
                    kept.append(line)
                elif line.strip().startswith('/*') or line.strip().startswith('*/'):
                    kept.append(line)

            new_comment = '\n'.join(kept)
            return new_comment + '\n' + rest.lstrip('\n')

        return data

    return main(data, fileType)



# def read(fileName: str) -> str:
#     return open(fileName, 'r', encoding='utf-8').read()

# print(removePrefix(read('Codes/1523-count-odd-numbers-in-an-interval-range_20260219.cpp'), 'cpp'))


cpp = """/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:38:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 17:39:31
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2) {
            low--;
        }
        if (high % 2) {
            high++;
        }
        return (high - low) >> 1;
    }
};
/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:38:02
 * @LastEditors: LetMeFly.xyz.should.keep
 * @LastEditTime: 2026-02-19 17:39:31
 */
#if defined JUST_TEST.h
#else
#endif
"""

py = """'''
Author: LetMeFly
Date: 2026-02-19 17:59:08
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-19 18:00:11
'''
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low % 2:
            low -= 1
        if high % 2:
            high += 1
        return (high - low) // 2"""
print(removePrefix(cpp, 'cpp'))
# print(removePrefix(py, 'py'))