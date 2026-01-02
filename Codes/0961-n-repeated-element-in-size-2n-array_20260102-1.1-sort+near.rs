/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 12:47:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:58:03
 */
impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        for i in 1..nums.len() {
            if nums[i] == nums[i - 1] {
                return nums[i];
            }
        }
        -1  // FAKE RETURN
    }
}