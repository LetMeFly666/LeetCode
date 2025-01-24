/*
 * @Author: LetMeFly
 * @Date: 2025-01-24 13:02:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-24 14:05:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<int> buy(prices.size()), notBuy(prices.size());
        buy[0] = notBuy[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // buy[i] = notBuy[i - 1] + prices[i];
            // if (notBuy[i - 1] > buy[i - 1]) {
            //     cout << ">" << endl;
            // }
            buy[i] = min(notBuy[i - 1], buy[i - 1]) + prices[i];  // 不买3的话必须买2，因此buy[2]不一定大于notBuy[2]
            notBuy[i] = 1000000000;
            for (int j = i / 2; j < i; j++) {
                notBuy[i] = min(notBuy[i], buy[j]);
            }
        }
        return min(buy.back(), notBuy.back());
    }
};

#ifdef _WIN32
/*
[29,18,2,6,47,32,27,12,38,17]

49
*/
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        cout << sol.minimumCoins(v) << endl;
    }
    return 0;
}
#endif