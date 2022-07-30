/*
 * @Author: LetMeFly
 * @Date: 2022-07-30 09:54:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-30 10:16:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        // 分解因数到hasThisFactor中
        vector<vector<int>> hasThisFactor(100010);
        vector<vector<int>> num4Factor(100010);
        for (int t : nums) {
            int k = sqrt(t);
            for (int i = 2; i <= k; i++) {
                if (t % i == 0) {
                    hasThisFactor[i].push_back(t);
                    num4Factor[t].push_back(i);
                    if (t / i != i) {
                        hasThisFactor[t / i].push_back(t);
                        num4Factor[t].push_back(t / i);
                    }
                }
            }
            // 自己是自己的因数
            hasThisFactor[t].push_back(t);
            num4Factor[t].push_back(t);
        }
        int ans = 0;
        vector<bool> visitedFactor(100010, false);
        vector<bool> visitedNum(100010, false);
        for (int i = 2; i <= 100000; i++) {
            if (hasThisFactor[i].size() && !visitedFactor[i]) {
                visitedFactor[i] = true;
                int thisAns = 0;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int thisFactor = q.front();
                    q.pop();
                    for (int thisNum : hasThisFactor[thisFactor]) {
                        if (!visitedNum[thisNum]) {
                            visitedNum[thisNum] = true;
                            thisAns++;
                            for (int thisNewFactor : num4Factor[thisNum]) {
                                if (!visitedFactor[thisNewFactor]) {
                                    visitedFactor[thisNewFactor] = true;
                                    q.push(thisNewFactor);
                                }
                            }
                        }
                    }
                }
                ans = max(ans, thisAns);
            }
        }
        return ans;
    }
};

// [4,6,15,35]
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.largestComponentSize(v) << endl;
    }
    return 0;
}
#endif