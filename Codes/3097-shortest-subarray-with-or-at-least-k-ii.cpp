/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:08:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 12:22:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int calc(int* cnt) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i]) {
                ans |= 1 << i;
            }
        }
        return ans;
    }

    void add(int* cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] += a >> i & 1;
        }
    }

    void del(int* cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] -= a >> i & 1;
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (!k) {
            return 1;
        }
        int ans = 1000000;
        int cnt[30] = {0};
        for (int l = 0, r = 0; l < nums.size(); l++) {
            if (l > 0) {
                del(cnt, nums[l - 1]);
            }
            while (r < nums.size() && calc(cnt) < k) {
                add(cnt, nums[r++]);
            }
            if (calc(cnt) >= k) {
                ans = min(ans, r - l);
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
};

#ifdef _WIN32
/*
[1,2,3]
2

1
*/

/*
[1,2]
0

1
*/
int main() {
    string s;
    int k;
    Solution sol;
    while (cin >> s >> k) {
        vector<int> v = stringToVector(s);
        cout << sol.minimumSubarrayLength(v, k) << endl;
    }
    return 0;
}
#endif