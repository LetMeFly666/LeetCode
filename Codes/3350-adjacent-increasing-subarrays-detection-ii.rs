/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:32:24
 */
impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {
        let mut ans: i32 = 0;
        let mut last_cnt: i32 = 0;
        let mut now_cnt: i32 = 0;
        for i in 0..nums.len() {
            now_cnt += 1;
            if i == nums.len() - 1 || nums[i] >= nums[i + 1] {
                ans = ans.max(last_cnt.min(now_cnt)).max(now_cnt / 2);
                // (last_cnt, now_cnt) = (now_cnt, 0);
                last_cnt = now_cnt;
                now_cnt = 0;
            }
        }
        ans
    }
}