/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 20:53:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 20:53:36
 */
class Solution {
private:
    void debug(vector<int>& a) {
        for (int t : a) {
            cout << t << ' ';
        }
        puts("");
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A int整型vector 
     * @param T int整型 
     * @return int整型
     */
    int minSumOfLengths(vector<int>& a, int T) {
        // write code here
        vector<int> minPrefix(a.size());
        int l = 0, cnt = 0, ans = 100000000;
        for (int r = 0; r < a.size(); r++) {
            cnt += a[r];
            while (l < r && cnt > T) {
                cnt -= a[l++];
            }
            if (cnt == T) {
                ans = min(ans, r - l + 1);
            }
            minPrefix[r] = ans;
        }
        // debug(minPrefix);

        vector<int> minSuffix(a.size());
        int r = a.size() - 1;
        cnt = 0, ans = 10000000;
        for (int l = a.size() - 1; l >= 0; l--) {
            cnt += a[l];
            while (l < r && cnt > T) {
                cnt -= a[r--];
            }
            if (cnt == T) {
                ans = min(ans, r - l + 1);
            }
            minSuffix[l] = ans;
        }

        ans = 10000000;
        for (int i = 0; i + 1 < a.size(); i++) {
            ans = min(ans, minPrefix[i] + minSuffix[i + 1]);
        }
        return ans > a.size() ? -1 : ans;
    }
};