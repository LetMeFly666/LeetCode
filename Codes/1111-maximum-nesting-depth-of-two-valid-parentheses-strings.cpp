/*
 * @Author: LetMeFly
 * @Date: 2026-09-30 08:16:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-30 08:18:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxDepthAfterSplit(const string& seq) {
        int n = seq.size();
        vector<int> ans(n);
        for (int i = 0, layer = 0; i < n; i++) {
            layer += seq[i] == '(' ? 1 : -1;
            ans[i] = layer % 2;
        }
        return ans;
    }
};
