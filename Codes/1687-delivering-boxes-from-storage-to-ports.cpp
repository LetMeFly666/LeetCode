/*
 * @Author: LetMeFly
 * @Date: 2022-12-05 21:33:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-05 21:38:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // 思路
/*
我在想能不能：

既然和距离无关，卸货一次或者装货一次就算一次行程，那么不如一次装货尽可能多。

什么时候在车未装满的时候也不继续装货了呢？

就是假如“下一个货物和下一车的第一个货物目的地一样”的话，这个货本来能这车装上但是不装了。

注意考虑下一个货和下下一个货物下下下个货物目的地是否都相同。

*/
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int ans = 0;
        int nowBoxes = 0, nowWeight = 0;
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // Copy from https://leetcode.cn/problems/delivering-boxes-from-storage-to-ports/solutions/2005717/cong-cang-ku-dao-ma-tou-yun-shu-xiang-zi-4uya/
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> p(n + 1), w(n + 1), neg(n + 1);
        vector<long long> W(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if (i > 1) {
                neg[i] = neg[i - 1] + (p[i - 1] != p[i]);
            }
            W[i] = W[i - 1] + w[i];
        }
        
        deque<int> opt = {0};
        vector<int> f(n + 1), g(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            while (i - opt.front() > maxBoxes || W[i] - W[opt.front()] > maxWeight) {
                opt.pop_front();
            }
            
            f[i] = g[opt.front()] + neg[i] + 2;
            
            if (i != n) {
                g[i] = f[i] - neg[i + 1];
                while (!opt.empty() && g[i] <= g[opt.back()]) {
                    opt.pop_back();
                }
                opt.push_back(i);
            }
        }
        
        return f[n];
    }
};
#endif  // FirstTry