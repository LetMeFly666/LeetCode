/*
 * @Author: LetMeFly
 * @Date: 2024-05-05 13:48:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-05 14:02:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n;
    
    inline int next(int i) {
        return (i + 1) % n;
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        n = code.size();
        vector<int> ans(n);
        if (!k) {
            return ans;
        }
        int l, r, s = 0;  // left, right, sum
        if (k > 0) {  // [1, k]
            l = 1;
            for (r = l; r <= k; r++) {
                s += code[r];
            }
            r--;
        }
        else {  // [n - (-k), n - 1]
            r = n - 1;
            for (l = r; l >= n + k; l--) {
                s += code[l];
            }
            l++;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = s;
            s -= code[l];
            l = next(l);
            r = next(r);
            s += code[r];
            // printf("l = %d, r = %d, s = %d\n", l, r, s);  //***********
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[5,7,1,4]
3

[12,10,16,13]
*/
int main() {
    string s;
    int k;
    while (cin >> s >> k) {
        vector<int> v = stringToVector(s);
        Solution sol;
        debug(sol.decrypt(v, k));
    }
    return 0;
}
#endif