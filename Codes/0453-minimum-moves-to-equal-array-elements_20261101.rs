/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 10:57:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 11:01:46
 */
impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let mut m = nums[0];
        for &t in nums.iter() {
            m = m.min(t);
        }
        let mut ans = 0;
        for &t in nums.iter() {
            ans += t - m;
        }
        ans
    }
}
