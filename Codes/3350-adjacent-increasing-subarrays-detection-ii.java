/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:28:53
 */
class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int ans = 0;
        for (int i = 0, lastCnt = 0, nowCnt = 0; i < nums.size(); i++) {
            nowCnt++;
            if (i == nums.size() - 1 || nums.get(i) >= nums.get(i + 1)) {  // 昨天踩过的bug今天不会再踩一次
                ans = Math.max(ans, Math.max(Math.min(lastCnt, nowCnt), nowCnt / 2));
                lastCnt = nowCnt;
                nowCnt = 0;
            }
        }
        return ans;
    }
}