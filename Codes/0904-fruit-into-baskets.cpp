/*
 * @Author: LetMeFly
 * @Date: 2022-10-17 08:58:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-17 09:38:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 先存为[<5个3>, <6个2>, ...]
typedef pair<int, int> pii;  // <number, times> 比如<5, 3>：5出现了3次
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<pii> append;
        int lastNum = fruits[0], cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i == n || fruits[i] != fruits[i - 1]) {
                append.push_back({fruits[i - 1], cnt});
                cnt = 0;
            }
            cnt++;
        }
        if (append.size() == 1)
            return append[0].second;
        int firstTypeLoc = 0, secondTypeLoc = 1;
        int cntTimes = append[0].second + append[1].second;
        int ans = cntTimes;
        for (int nowTypeLoc = 2; nowTypeLoc < append.size(); nowTypeLoc++) {
            while (nowTypeLoc < append.size() && (append[nowTypeLoc].first == append[firstTypeLoc].first || append[nowTypeLoc].first == append[secondTypeLoc].first)) {
                cntTimes += append[nowTypeLoc++].second;
            }
            ans = max(ans, cntTimes);
            if (nowTypeLoc == append.size()) {
                break;
            }
            firstTypeLoc = nowTypeLoc - 1;
            secondTypeLoc = nowTypeLoc;
            cntTimes = append[firstTypeLoc].second + append[secondTypeLoc].second;
        }
        ans = max(ans, cntTimes);  // 此行不可去
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                unordered_map<int, int>::iterator it = cnt.find(fruits[left]);
                it->second--;
                left++;
                if (!it->second) {
                    cnt.erase(it);
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
#endif  // FirstTry