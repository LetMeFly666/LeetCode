/*
 * @Author: LetMeFly
 * @Date: 2024-06-05 13:24:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-05 13:56:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyTree {
private:
    vector<int> a;

public:
    MyTree(int n) : a(n + 1) {}

    void add(int n) {
        while (n < a.size()) {
            a[n]++;
            n += n & -n;
        }
    }

    int get(int n) {
        int ans = 0;
        while (n > 0) {
            ans += a[n];
            n -= n & -n;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        // 离散化
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int length = unique(sorted.begin(), sorted.end()) - sorted.begin();
        unordered_map<int, int> ma;
        for (int i = 0; i < length; i++) {
            ma[sorted[i]] = i + 1;
        }
        // begin
        MyTree treeA(length), treeB(length);
        treeA.add(ma[nums[0]]), treeB.add(ma[nums[1]]);
        vector<int> a = {nums[0]}, b = {nums[1]};
        for (int i = 2; i < nums.size(); i++) {
            int na = a.size() - treeA.get(ma[nums[i]]), nb = b.size() - treeB.get(ma[nums[i]]);
            if (na > nb) {
                a.push_back(nums[i]);
                treeA.add(ma[nums[i]]);
            }
            else if (na < nb) {
                b.push_back(nums[i]);
                treeB.add(ma[nums[i]]);
            }
            else if (a.size() > b.size()) {
                b.push_back(nums[i]);
                treeB.add(ma[nums[i]]);
            }
            else {
                a.push_back(nums[i]);
                treeA.add(ma[nums[i]]);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};