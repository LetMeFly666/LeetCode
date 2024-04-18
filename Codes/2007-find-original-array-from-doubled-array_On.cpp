/*
 * @Author: LetMeFly
 * @Date: 2024-04-18 12:59:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-18 13:17:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error [2,4,2,1]则会全部continue到1
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> a(200001);
        for (int t : changed) {
            a[t]++;
        }
        int remain = changed.size();
        vector<int> ans;
        if (a[0] % 2) {
            return {};
        }
        remain -= a[0];
        ans.resize(a[0] / 2);
        a[0] = 0;
        for (int t : changed) {
            if (t % 2 == 0 && a[t / 2]) {
                continue;
            }
            if (!a[t]) {
                continue;
            }
            a[t]--;
            if (!a[t * 2]) {
                return {};
            }
            a[t * 2]--;
            remain -= 2;
            ans.push_back(t);
        }
        return remain ? vector<int>() : ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error [4,8,2,16,1,8] 处理完1后a[2]=0不会继续往上处理了
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> a(200001);
        for (int t : changed) {
            a[t]++;
        }
        int remain = changed.size();
        vector<int> ans;
        if (a[0] % 2) {
            return {};
        }
        remain -= a[0];
        ans.resize(a[0] / 2);
        a[0] = 0;
        for (int t : changed) {
            if (t % 2 == 0 && a[t / 2]) {
                continue;
            }
            while (a[t]) {
                int thisCnt = a[t];
                a[t] = 0;
                remain -= thisCnt;
                if (a[t * 2] < thisCnt) {
                    return {};
                }
                a[t * 2] -= thisCnt;
                remain -= thisCnt;
                ans.insert(ans.end(), thisCnt, t);
                t *= 2;
            }
        }
        return remain ? vector<int>() : ans;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> a(400001);
        for (int t : changed) {
            a[t]++;
        }
        int remain = changed.size();
        vector<int> ans;
        if (a[0] % 2) {
            return {};
        }
        remain -= a[0];
        ans.resize(a[0] / 2);
        a[0] = 0;
        for (int t : changed) {
            if (t % 2 == 0 && a[t / 2]) {
                continue;
            }
            while (a[t]) {
                int thisCnt = a[t];
                a[t] = 0;
                remain -= thisCnt;
                if (a[t * 2] < thisCnt) {
                    return {};
                }
                a[t * 2] -= thisCnt;
                remain -= thisCnt;
                ans.insert(ans.end(), thisCnt, t);
                if (a[t * 2]) {
                    t *= 2;
                }
                else {
                    t *= 4;
                }
            }
        }
        return remain ? vector<int>() : ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry