/*
 * @Author: LetMeFly
 * @Date: 2023-06-02 20:27:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-02 20:36:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

inline bool isYuan(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++) {
            prefix[i + 1] = prefix[i] + (isYuan(words[i][0]) && isYuan(words[i].back()));  // 这里&&外必须加括号，不然会先执行prefix[i] + isYuan(words[i][0])，再将结果于isYuan(words[i].back())做与运算
            // printf("prefix[%d] = %d, prefix[%d] = %d\n", i, prefix[i], i + 1, prefix[i + 1]);  //**********
        }
        // for (int t : prefix) {printf("%d ", t);} puts("");  //**********
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }
        return ans;
    }
};