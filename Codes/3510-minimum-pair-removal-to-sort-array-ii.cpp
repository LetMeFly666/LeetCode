/*
 * @Author: LetMeFly
 * @Date: 2026-01-23 19:26:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-23 20:12:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif


typedef long long ll;
class Solution {
private:
    vector<int> lFather, rFather;
    vector<bool> isNode;

    int left(int idx) {
        int lIdx = lFather[idx];
        if (lIdx == -1) {
            return -1;
        }
        if (isNode[lIdx]) {
            return lIdx;
        }
        return lFather[idx] = left(lIdx);
    }

    int right(int idx) {
        int rIdx = rFather[idx];
        if (rIdx == -1) {
            return -1;
        }
        if (isNode[rIdx]) {
            return rIdx;
        }
        return rFather[idx] = right(rIdx);
    }

    int getRank(int a, int b, int c, int d) {
        return 0 + (a > b) + (b > c) + (c > d);
    }

    int getRank(int a, int b, int c) {
        return 0 + (a > b) + (b > c);
    }

    // merge nums[idx]和nums[idx]的right，并返回熵减了多少
    int merge(vector<ll>& nums, int idx) {
        int lIdx = left(idx);
        int secondIdx = right(idx);  // assert: idx一定存在right
        int rIdx = right(secondIdx);
        ll lValue = lIdx == -1 ? -1e18 : nums[lIdx], rValue = rIdx == -1 ? 1e18 : nums[rIdx];

        int beforeRank = getRank(lValue, nums[idx], nums[secondIdx], rValue);
        nums[idx] += nums[secondIdx];
        int afterRank = getRank(lValue, nums[idx], rValue);
        
        isNode[secondIdx] = false;
        rFather[idx] = rIdx;
        if (rIdx != -1) {
            lFather[rIdx] = idx;
        }
        
        return beforeRank - afterRank;
    }
public:
    int minimumPairRemoval(vector<int>& numsInt) {
        isNode.resize(numsInt.size(), true);
        lFather.resize(numsInt.size());
        rFather.resize(numsInt.size());
        for (int i = 0; i < numsInt.size(); i++) {
            lFather[i] = i - 1;
            rFather[i] = i + 1;
        }
        rFather[numsInt.size() - 1] = -1;

        int cntRev = 0;
        vector<ll> nums(numsInt.size());
        nums[0] = numsInt[0];
        for (int i = 1; i < numsInt.size(); i++) {
            if (numsInt[i] < numsInt[i - 1]) {
                cntRev++;
            }
            nums[i] = numsInt[i];
        }

        auto cmp = [this, &nums](int i, int j) {
            return nums[i] + nums[right(i)] > nums[j] + nums[(right(j))];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i + 1 < nums.size(); i++) {
            pq.push(i);
        }

        int ans = 0;
        while (cntRev) {
            ans++;
            int idx = pq.top();
            pq.pop();
            
            cntRev -= merge(nums, idx);
        }
        return ans;
    }
};