/*
 * @Author: LetMeFly
 * @Date: 2022-06-19 09:51:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-19 10:31:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// TODO: 写题解

#ifdef SecondTry  // 典型错误，数组的修改导致误认为前面已有两个相同的了
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                continue;
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};
#else  // SecondTry
#ifdef ThirdTry  // 往nums后面又push了一位
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[cnt - 2])  // 注意这里是nums[cnt - 2]
                continue;
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};
#else  // ThirdTry
// FourthTry
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int l = 0, r = 1;  // [l, r)相同
        nums.push_back(1e5);
        for (; r < nums.size(); r++) {
            if (nums[r] != nums[l]) {
                for (int i = 0; i < min(2, r - l); i++) {
                    nums[cnt++] = nums[r - 1];
                }
                l = r;
            }
        }
        return cnt;
    }
};
#endif  // ThirdTry
#endif  // SecondTry

#ifdef _WIN32
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        int n = sol.removeDuplicates(v);
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
#endif