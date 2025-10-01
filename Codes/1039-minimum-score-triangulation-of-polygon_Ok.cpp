/*
 * @Author: LetMeFly
 * @Date: 2025-09-29 18:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-01 20:38:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> cache;
    vector<int> values;
    int n;

    int dfs(int i, int j) {
        if (j - i < 2) {
            return 0;
        }
        int key = i * n + j;
        if (cache.count(key)) {
            return cache[key];
        }
        if (j - i == 2) {
            return cache[key] = values[i] * values[i + 1] * values[i + 2];
        }
        int ans = 1000000000;
        /*
        0 1 2 3 -> 0 1 2 + 0 2 3

        0   1

        3   2


        0 1 2 3 4


            3
                 
        4        2

         0      1

        
        (i,j,k) + dfs(i,k)+dfs(k,j)
        */
        for (int k = i + 1; k < j; k++) {
            ans = min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        }
        return cache[key] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        this->values = move(values);
        n = this->values.size();
        return dfs(0, n - 1);
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[3,7,4,5]

144
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.minScoreTriangulation(v) << endl;
    }
    return 0;
}
#endif