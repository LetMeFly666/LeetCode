/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:25:57
 */
impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        for i in (0..nums.len()-2).rev() {
            if nums[i] + nums[i + 1] > nums[i + 2] {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        0
    }
}