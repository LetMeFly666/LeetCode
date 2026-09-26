/*
 * @Author: LetMeFly
 * @Date: 2026-09-05 08:24:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-05 08:55:35
 */
impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut mini = vec![0; n];
        mini[n-1] = nums[n-1];
        for i in (0..n-1).rev() {
            mini[i] = nums[i].min(mini[i+1]);
        }
        let mut M = 0;
        for i in 0..n {
            M = M.max(nums[i]);
            if M - mini[i] <= k {
                return i as i32;
            }
        }
        -1
    }
}
