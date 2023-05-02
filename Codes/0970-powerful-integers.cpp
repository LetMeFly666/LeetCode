/*
 * @Author: LetMeFly
 * @Date: 2023-05-02 10:09:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-02 10:17:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> se;
        int i = 0;
        while (true) {
            int first = pow(x, i);
            if (first > bound) {
                break;
            }
            int j = 0;
            while (true) {
                int second = pow(y, j);
                int s = first + second;
                if (s > bound) {
                    break;
                }
                se.insert(s);
                if (y == 1) {
                    break;
                }
                j++;
            }
            if (x == 1) {
                break;
            }
            i++;
        }
        return vector<int>(se.begin(), se.end());
    }
};

#ifdef _WIN32
/*
2 3 10

2,3,4,5,7,9,10
*/
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        Solution sol;
        debug(sol.powerfulIntegers(a, b, c));
    }
    return 0;
}
#endif