/*
 * @Author: LetMeFly
 * @Date: 2022-03-14 11:46:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-14 12:07:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// 没看懂
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        vector<string> ans;
        int l1 = 0, l2 = 0;
        while (l1 < list1.size() && l2 < list2.size()) {
            if (list1[l1] == list2[l2]) {
                ans.push_back(list1[l1]);
                l1++, l2++;
            }
            else if (list1[l1] < list2[l2]) {
                l1++;
            }
            else {
                l2++;
            }
        }
        return ans;
    }
};
#else
// 官方
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); i++) {
            index[list1[i]] = i;
        }

        vector<string> ret;
        int indexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (index.count(list2[i]) > 0) {
                int j = index[list2[i]];
                if (i + j < indexSum) {
                    ret.clear();
                    ret.push_back(list2[i]);
                    indexSum = i + j;
                } else if (i + j == indexSum) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};
#endif