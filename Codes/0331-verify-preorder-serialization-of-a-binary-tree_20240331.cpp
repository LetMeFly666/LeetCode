/*
 * @Author: LetMeFly
 * @Date: 2024-03-31 09:13:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-31 09:26:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Half，都9:30了室友们都还在睡。。打字不爽。
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> st;
        int loc = 0;
        while (loc < preorder.size()) {
            if (preorder[loc] == '#') {
                loc += 2;
                
            }
            else {
                while (loc < preorder.size() && isdigit(preorder[loc])) {
                    loc++;
                }
                loc++;
            }
        }
    }
};
#endif  // FirstTry