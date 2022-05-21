/*
 * @Author: LetMeFly
 * @Date: 2021-10-26 08:08:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-11 09:36:47
 */

#ifdef FirstTime
//[2021-10-26 08:08:58, 2021-10-26 08:35:20]

#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

/*方法一：暴力*/
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for (int &t : nums1) {
//             int start = 0;
//             while (nums2[start] != t) start++;
//             while (start < nums2.size()) {
//                 if (nums2[start] > t) {
//                     ans.push_back(nums2[start]);
//                     goto loop;
//                 }
//                 start++;
//             }
//             ans.push_back(-1);
//             loop:;
//         }
//         return ans;
//     }
// };

/*方法二：单调栈+哈希表*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> ma;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int t = nums2[i];
            while (s.size() && t > s.top()) s.pop();
            ma[t] = s.empty() ? -1 : s.top();
            s.push(t);
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = ma[nums1[i]];
        }
        return ans;
    }
};

#else
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 单调栈 + 哈希表
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> ma;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (st.size() && nums2[i] > st.top()) {
                st.pop();
            }
            if (st.size())
                ma[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int& t : nums1) {
            if (ma.count(t))
                t = ma[t];
            else
                t = -1;
        }
        return nums1;
    }
};
#endif