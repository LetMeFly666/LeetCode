/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 18:08:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 18:10:36
 */
// THIS IS CE
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let mut ans: i32 = -1;
        let mut hp: i32 = 0;
        for i in 1..nums.length() {
            if nums[i] == nums[0] {
                return nums[0]
            }
            if hp == 0 {
                ans = nums[i];
                hp = 1;
            } else if ans == nums[i] {
                hp += 1;
            } else {
                hp -= 1;
            }
        }
        ans
    }
}