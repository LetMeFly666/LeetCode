/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:59:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 18:00:25
 */
// THIS IS CE
impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mid: i32 = nums.len() / 2;
        if nums[mid] == nums[mid + 1] {
            return nums[mid];
        }
        nums[mid - 1]
    }
}