/*
 * @Author: LetMeFly
 * @Date: 2026-03-14 22:56:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-14 23:33:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, k;
    string ans;
    char can[3] = {'a', 'b', 'c'};

    // dfs and return if can stop
    bool dfs(string now) {
        if (now.size() == n) {
            k--;
            if (!k) {
                ans = now;
                return true;
            }
            return false;
        }

        char last = now.empty() ? '0' : now.back();
        for (int i = 0; i < 3; i++) {
            if (can[i] == last) {
                continue;
            }
            if (dfs(now + can[i])) {
                return true;
            }
        }
        return false;   
    }
public:
    string getHappyString(int n, int k) {
        this->n = n, this->k = k;
        dfs("");
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
1 3

c
*/
int main() {
    int a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.getHappyString(a, b) << endl;
    }
    return 0;
}
#endif