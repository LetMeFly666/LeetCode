/*
 * @Author: LetMeFly
 * @Date: 2022-09-26 08:49:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-26 09:06:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/solution/pai-an-jiao-jue-de-liang-chong-jie-fa-zh-66nt/

#ifdef FirstTry  // Error  // 第一个为#的话，第二个为其他
class Solution {
public:
    bool isValidSerialization(string& preorder) {
        int outdegree = 1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == '#') {
                outdegree--;
                if (outdegree < 0) {
                    return false;
                }
                i++;
            }
            else {
                outdegree++;
                while (i < preorder.size() && preorder[i] != ',') {
                    i++;
                }
            }
        }
        return !outdegree;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error
class Solution {
public:
    bool isValidSerialization(string& preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;
        int outdegree = 1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == '#') {
                outdegree--;
                if (outdegree < 0) {
                    return false;
                }
                i++;
            }
            else {
                outdegree++;
                while (i < preorder.size() && preorder[i] != ',') {
                    i++;
                }
            }
        }
        return !outdegree;
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef Python3
class Solution(object):
    def isValidSerialization(self, preorder):
        stack = []
        for node in preorder.split(','):
            stack.append(node)
            while len(stack) >= 3 and stack[-1] == stack[-2] == '#' and stack[-3] != '#':
                stack.pop(), stack.pop(), stack.pop()
                stack.append('#')
        return len(stack) == 1 and stack.pop() == '#'
#endif