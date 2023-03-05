/*
 * @Author: LetMeFly
 * @Date: 2023-03-05 13:24:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-05 13:32:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，没有判断遍历完customers但是仍有人排队的情况
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxCnt = 0;
        int ans = 0;
        int nowCnt = 0;
        int remainCustomers = 0;
        int totalRunTime = 0;
        for (int customer : customers) {
            totalRunTime++;
            customer += remainCustomers;
            int thisCustomer = min(4, customer);
            remainCustomers = customer - thisCustomer;
            nowCnt += boardingCost * thisCustomer - runningCost;
            if (nowCnt > maxCnt) {
                maxCnt = nowCnt;
                ans = totalRunTime;
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = 0;
        int maxEarn = 0;
        int nowEarn = 0;
        int customerInLine = 0;
        int times = 0;
        while (true) {
            if (times < customers.size()) {
                customerInLine += customers[times];
            }
            times++;
            int thisCustomer = min(4, customerInLine);
            nowEarn += thisCustomer * boardingCost - runningCost;
            if (nowEarn > maxEarn) {
                maxEarn = nowEarn;
                ans = times;
            }
            customerInLine -= thisCustomer;
            if (!customerInLine && times >= customers.size()) {
                break;
            }
        }
        return ans ? ans : -1;
    }
};
#endif  // FirstTry