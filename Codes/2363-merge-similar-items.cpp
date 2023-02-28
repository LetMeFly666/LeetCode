/*
 * @Author: LetMeFly
 * @Date: 2023-02-28 10:13:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-28 10:40:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一：哈希表
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
#else  // FirstTry
// SecondTry  // 方法二：排序 + 双指针
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        vector<vector<int>> ans;
        int l1 = 0, l2 = 0;
        while (l1 < items1.size() && l2 < items2.size()) {
            if (items1[l1][0] == items2[l2][0]) {
                ans.push_back({items1[l1][0], items1[l1][1] + items2[l2][1]});
                l1++, l2++;
            }
            else if (items1[l1][0] < items2[l2][0]) {
                ans.push_back(items1[l1]);
                l1++;
            }
            else {
                ans.push_back(items2[l2]);
                l2++;
            }
        }
        while (l1 < items1.size()) {
            ans.push_back(items1[l1++]);
        }
        while (l2 < items2.size()) {
            ans.push_back(items2[l2++]);
        }
        return ans;
    }
};
#endif  // FirstTry

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