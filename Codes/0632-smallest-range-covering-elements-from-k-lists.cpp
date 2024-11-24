/*
 * @Author: LetMeFly
 * @Date: 2024-11-24 17:37:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-24 18:31:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // TLE(92 / 94 个通过的测试用例)  // 最后可能全部移动的最后一组的指针，但是前面的元素还要全部再判断并continue一次
/*
4 10 15
0 9 12

0-4
4-9
9-10
10-12
12-15

min: 9-10
*/
class Solution {
private:
    void update(vector<vector<int>>& nums, vector<int>& loc, int& m, int& M) {
        m = 1e6, M = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            m = min(m, nums[i][loc[i]]);
            M = max(M, nums[i][loc[i]]);
        }
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // init
        vector<int> loc(nums.size());
        int m, M;
        update(nums, loc, m, M);
        int minDiff = M - m;
        // begin
        while (true) {
            int moveWhich = -1, minChange = 1e6;
            for (int i = 0; i < nums.size(); i++) {
                if (loc[i] == nums[i].size() - 1) {
                    continue;
                }
                if (nums[i][loc[i] + 1] - M < minChange) {
                    moveWhich = i;
                    minChange = nums[i][loc[i] + 1] - M;
                }
            }
            if (moveWhich == -1) {
                break;
            }
            loc[moveWhich]++;
            int thism, thisM;
            update(nums, loc, thism, thisM);
            if (thisM - thism < minDiff) {
                minDiff = thisM - thism;
                m = thism, M = thisM;
            }
        }
        return {m, M};
    }
};
#else  // FirstTry
#ifdef SecondTry  // TLE  // 时间瓶颈卡在获取m和M上
class Solution {
private:
    void updateMm(vector<vector<int>>& nums, vector<int>& loc, int& m, int& M) {
        m = 1e6, M = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            m = min(m, nums[i][loc[i]]);
            M = max(M, nums[i][loc[i]]);
        }
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> loc(nums.size());
        int m, M;
        updateMm(nums, loc, m, M);
        int minDiff = M - m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums[i].size(); j++) {
                pq.push({nums[i][j], i});
            }
        }
        while (pq.size()) {
            auto&& [val, index] = pq.top();
            loc[index]++;
            pq.pop();
            int thism, thisM;
            updateMm(nums, loc, thism, thisM);
            if (thisM - thism < minDiff) {
                minDiff = thisM - thism;
                m = thism, M = thisM;                
            }
        }
        return {m, M};
    }
};
#else  // SecondTry
#ifdef ThirdTry  // WA - 最终会收敛到[最大数, 最大数]
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> loc(nums.size());
        // lambda [](const int& x, const int& y)->bool cmp = xxx
        auto cmp = [&nums, &loc](const int& x, const int& y) {
            return nums[x][loc[x]] > nums[y][loc[y]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int m = -1e8, M = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(i);
            M = max(M, nums[i][0]);
        }
        int nowm, nowM = M;
        while (pq.size()) {
            int index = pq.top();
            pq.pop();
            nowm = nums[index][loc[index]];
            loc[index]++;
            if (nowM - nowm < M - m) {
                M = nowM;
                m = nowm;
            }
            if (loc[index] < nums[index].size()) {
                nowM = max(nowM, nums[index][loc[index]]);
                pq.push(index);
            }
            // printf("m = %d, M = %d, nowm = %d, nowM = %d\n", m, M, nowm, nowM);  //*************
        }
        return {m, M};
    }
};
#else  // ThirdTry
// FourthTry
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> loc(nums.size());
        auto cmp = [&nums, &loc](const int& x, const int& y) {
            return nums[x][loc[x]] > nums[y][loc[y]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int m = -1e8, M = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(i);
            M = max(M, nums[i][0]);
        }
        int nowm, nowM = M;
        while (pq.size()) {
            int index = pq.top();
            pq.pop();
            nowm = nums[index][loc[index]];
            loc[index]++;
            if (nowM - nowm < M - m) {
                M = nowM;
                m = nowm;
            }
            if (loc[index] == nums[index].size()) {
                break;
            }
            nowM = max(nowM, nums[index][loc[index]]);
            pq.push(index);
        }
        return {m, M};
    }
};
#endif  // ThirdTry
#endif  // SecondTry
#endif  // FirstTry