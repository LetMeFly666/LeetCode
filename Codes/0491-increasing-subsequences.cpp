/*
 * @Author: LetMeFly
 * @Date: 2022-11-02 10:07:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-02 11:25:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，是求子序列，不是求子串
class Solution {
private:
    vector<vector<int>> ans;

    void add2ans(vector<int>& nums, int l, int r) {
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ans.push_back(vector<int>(nums.begin() + i, nums.begin() + j + 1));
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int lastL = 0;
        for (int r = 1; r <= nums.size(); r++) {
            if (r == nums.size() || nums[r] < nums[r - 1]) {
                if (r - 1 > lastL) {
                    add2ans(nums, lastL, r - 1);
                }
                lastL = r;
            }
        }
        return ans;
    }
};
#else  // FirstTry
# ifdef SecondTry  // set而不是unordered_set
// struct VectorHash {
//     template<class T>
//     size_t operator() (const vector<T>& v) {
//         size_t hash = 0;
//         for (T& t : v) {
//             hash = hash * 201 + (t + 100);  // t + 100 -> [0, 200]
//         }
//         return hash;
//     }
// };
// struct VectorEqual {
//     template<class T>
//     bool operator() (const vector<T>& a, const vector<T>& b) {
//         return a == b;
//     }
// };
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash, VectorEqual> se;
        set<vector<int>> se;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int last = -100;
            vector<int> thisV;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (nums[j] < last)
                        goto loop;
                    thisV.push_back(nums[j]);
                    last = nums[j];
                }
            }
            if (thisV.size() > 1)
                se.insert(thisV);
            loop:;
        }
        vector<vector<int>> ans;
        for (auto& v : se)
            ans.push_back(v);
        return ans;
    }
};
#else  // SecondTry
#ifdef ThirdTry  // unordered_set
class Solution {
private:
    unordered_map<unsigned, vector<int>> ma;

    unsigned hash(vector<int>& v) {
        unsigned ans = 0;  // 32位无符号整数自然溢出
        for (int& t : v) {
            ans = ans * 201 + (t + 101);  // t + 101 -> [1, 201]  // +100不可以！！！会冲突  // 如果+100的话，[-100, 5]和[5]都会是105
        }
        ma[ans] = v;
        return ans;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash, VectorEqual> se;
        unordered_set<int> se;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int last = -100;
            vector<int> thisV;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (nums[j] < last)
                        goto loop;
                    thisV.push_back(nums[j]);
                    last = nums[j];
                }
            }
            if (thisV.size() > 1)
                se.insert(hash(thisV));
            loop:;
        }
        vector<vector<int>> ans;
        for (auto& t : se)
            ans.push_back(ma[t]);
        return ans;
    }
};
#else  // ThirdTry
// FourthTry  // DFS
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& nums, int loc, int lastVal) {
        if (loc == nums.size()) {
            if (now.size() > 1)
                ans.push_back(now);
            return;
        }
        if (nums[loc] >= lastVal) {
            now.push_back(nums[loc]);
            dfs(nums, loc + 1, nums[loc]);
            now.pop_back();
        }
        if (nums[loc] != lastVal) {  // important
            dfs(nums, loc + 1, lastVal);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, -101);
        return ans;
    }
};
#endif  // ThirdTry
#endif  // SecondTry
#endif  // FirstTry

/*
[[-100, -99], [-100, -99, -98], [-100, -99, -98, -97], [-100, -99, -98, -97, -96], [-100, -99, -98, -97, -96, -96], [-100, -99, -98, -96], [-100, -99, -98, -96, -96], [-100, -99, -97], [-100, -99, -97, -96], [-100, -99, -97, -96, -96], [-100, -99, -96], [-100, -99, -96, -96], [-100, -98], [-100, -98, -97], [-100, -98, -97, -96], [-100, -98, -97, -96, -96], [-100, -98, -96], [-100, -98, -96, -96], [-100, -97], [-100, -97, -96], [-100, -97, -96, -96], [-100, -96], [-100, -96, -96]]

[[-100, -99], [-100, -99, -98], [-100, -99, -98, -97], [-100, -99, -98, -97, -96], [-100, -99, -98, -97, -96, -96], [-100, -99, -98, -96], [-100, -99, -98, -96, -96], [-100, -99, -97], [-100, -99, -97, -96], [-100, -99, -97, -96, -96], [-100, -99, -96], [-100, -99, -96, -96], [-100, -98], [-100, -98, -97], [-100, -98, -97, -96], [-100, -98, -97, -96, -96], [-100, -98, -96], [-100, -98, -96, -96], [-100, -97], [-100, -97, -96], [-100, -97, -96, -96], [-100, -96], [-100, -96, -96], [-99, -98], [-99, -98, -97], [-99, -98, -97, -96], [-99, -98, -97, -96, -96], [-99, -98, -96], [-99, -98, -96, -96], [-99, -97], [-99, -97, -96], [-99, -97, -96, -96], [-99, -96], [-99, -96, -96], [-98, -97], [-98, -97, -96], [-98, -97, -96, -96], [-98, -96], [-98, -96, -96], [-97, -96], [-97, -96, -96], [-96, -96]]

*/