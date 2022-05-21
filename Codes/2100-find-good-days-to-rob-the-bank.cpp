/*
 * @Author: LetMeFly
 * @Date: 2022-03-06 10:19:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-06 14:15:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}
#endif

class Solution_Time96Memory98 {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if (!time) {  // 0天的diff
            vector<int> ans(security.size());
            for (int i = 0; i < security.size(); i++) {
                ans[i] = i;
            }
            return ans;
        }
        vector<int> ans;
        int lianXuXiaDays = 0;  // 连续↓或→的天数
        int couldAsUp4Begin = -1;  // 最早可以认为是开始连续上升的那一天
        for (int i = 1; i < security.size(); i++) {
            if (security[i] < security[i - 1]) {  // ↓
                lianXuXiaDays++;
                if (lianXuXiaDays >= time) {
                    couldAsUp4Begin = i;
                }
                else {
                    couldAsUp4Begin = -1;
                }
            }
            else if (security[i] == security[i - 1]) {
                lianXuXiaDays++;
                if (couldAsUp4Begin != -1) {
                    if (i - couldAsUp4Begin >= time) {
                        ans.push_back(couldAsUp4Begin);
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {
                            couldAsUp4Begin++;
                        }
                        else {
                            couldAsUp4Begin = -1;
                        }
                    }
                }
                else {  // couldAsUp4Begin = -1
                    if (lianXuXiaDays >= time) {
                        couldAsUp4Begin = i;
                    }
                }
            }
            else {  // 今 > 昨
                lianXuXiaDays = 0;
                if (couldAsUp4Begin != -1) {
                    if (i - couldAsUp4Begin >= time) {
                        ans.push_back(couldAsUp4Begin);
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {
                            couldAsUp4Begin++;
                        }
                        else {
                            couldAsUp4Begin = -1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

class Solution_EasyButOnOn {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> xia(security.size());
        vector<int> shang(security.size());
        xia[0] = 0, shang[shang.size() - 1] = 0;
        // for (int i = 1; i < security.size(); i++) {
        //     if (security[i] > security[i - 1]) {
        //         xia[i] = 0;
        //         shang[i] = shang[i - 1] + 1;
        //     }
        //     else if (security[i] == security[i - 1]) {
        //         xia[i] = xia[i - 1] + 1;
        //         shang[i] = shang[i - 1] + 1;
        //     }
        //     else {  // <
        //         xia[i] = xia[i - 1] + 1;
        //         shang[i] = 0;
        //     }
        // }
        for (int i = 1; i < security.size(); i++) {
            xia[i] = security[i] > security[i - 1] ? 0 : xia[i - 1] + 1;
        }
        for (int i = security.size() - 2; i >= 0; i--) {
            shang[i] = security[i] > security[i + 1] ? 0 : shang[i + 1] + 1;
        }
        // debug(xia);
        // debug(shang);
        vector<int> ans;
        for (int i = 0; i < security.size(); i++) {
            if (xia[i] >= time && shang[i] >= time)
                ans.push_back(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if (!time) {  // time = 0，每天都是“打劫日”
            vector<int> ans(security.size());  // 答案共有security.size()天
            for (int i = 0; i < security.size(); i++) {
                ans[i] = i;  // 第i个答案是第i天
            }
            return ans;
        }
        vector<int> ans;
        int lianXuXiaDays = 0;  // 连续↓或→的天数
        int couldAsUp4Begin = -1;  // 最早可以认为是开始连续上升的那一天 | 如果couldAsUp4Begin=a≠-1，说明第a天之前至少有time天的非递增
        for (int i = 1; i < security.size(); i++) {  // 从第二天开始遍历
            if (security[i] < security[i - 1]) {  // ↓
                lianXuXiaDays++;  // 连续非递增天数++
                if (lianXuXiaDays >= time) {  // 如果连续非递增天数≥time，那么今天之前就有≥time的非递减
                    couldAsUp4Begin = i;  // 从今天开始可以非递减了
                }
                else {  // 还没有连续非递增time天
                    couldAsUp4Begin = -1;
                }
            }
            else if (security[i] == security[i - 1]) {  // 今天和昨天相等，也就是说既符合非递增又符合非递减
                lianXuXiaDays++;  // 符合非递增，连续非递增天数++
                if (couldAsUp4Begin != -1) {  // 前面有≥time的非递减，并且从那天起没有递增的一天 | Lable1
                    if (i - couldAsUp4Begin >= time) {  // 如果今天距离那天≥time，那天就是抢劫日
                        ans.push_back(couldAsUp4Begin);  // 先把抢劫日添加到答案中去
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {  // 如果抢劫日的下一天仍然是非递增，那么下一天之前肯定有至少time天的非递增
                            couldAsUp4Begin++;  // 下一天也可以作为开始非递减的一天
                        }
                        else {  // 否则
                            couldAsUp4Begin = -1;  // 下一天＞这个抢劫日，说明下一天必不满足“前面有至少time天的非递增”
                        }
                    }
                }
                else {  // couldAsUp4Begin = -1
                    if (lianXuXiaDays >= time) {  // 连续非递增天数≥time
                        couldAsUp4Begin = i;  // 从今天起可以开始非递减了
                    }
                }
            }
            else {  // 今 > 昨
                lianXuXiaDays = 0;  // 连续非递减天数中断
                if (couldAsUp4Begin != -1) {  // 这个同理于上面的“Lable1”处
                    if (i - couldAsUp4Begin >= time) {
                        ans.push_back(couldAsUp4Begin);
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {
                            couldAsUp4Begin++;
                        }
                        else {
                            couldAsUp4Begin = -1;
                        }
                    }
                }
            }
        }
        return ans;  // 返回答案即可
    }
};