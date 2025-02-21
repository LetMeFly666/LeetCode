/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 12:25:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 13:05:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> cache;
    string floor;
    int perLen;

    int dfs(int n, int startIndex) {
        int code = n * 1000 + startIndex;
        if (cache.count(code)) {
            return cache[code];
        }
        // printf("n = %d, n * %d = %d, floor.size() - %d = %d\n", n, perLen, n * perLen, startIndex, floor.size() - startIndex);  //******** */
        if (n * perLen >= floor.size() - startIndex) {
            return cache[code] = 0;
        }
        int ans = dfs(n, startIndex + 1) + (floor[startIndex] == '1');  // 不覆盖
        if (n) {
            ans = min(ans, dfs(n - 1, startIndex + perLen));  // 覆盖
        }
        return cache[code] = ans;
    }
public:
    int minimumWhiteTiles(string& floor, int numCarpets, int carpetLen) {
        this->floor = move(floor);
        this->perLen = carpetLen;
        return dfs(numCarpets, 0);
    }
};

#ifdef _WIN32
/*
10110101
2
2

2
*/
int main() {
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        Solution sol;
        cout << sol.minimumWhiteTiles(s, a, b) << endl;
    }
    return 0;
}
#endif