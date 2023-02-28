/*
 * @Author: LetMeFly
 * @Date: 2023-02-28 10:13:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-28 10:25:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> ma;
        for (auto& v : items1) {
            ma[v[0]] += v[1];
        }
        for (auto& v : items2) {
            ma[v[0]] += v[1];
        }
        vector<vector<int>> ans;
        for (auto& v : ma) {
            ans.push_back({v.first, v.second});
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[[1,1],[4,5],[3,8]]
[[3,1],[1,5]]

[[1,6],[3,9],[4,5]]
*/
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<vector<int>> v1 = stringToVectorVector(s1), v2 = stringToVectorVector(s2);
        Solution sol;
        debug(sol.mergeSimilarItems(v1, v2));
    }
    return 0;
}
#endif