/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 18:12:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 18:16:31
 */
// THIS IS CE
use rand::Rng;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let rng = rand::thread_rng();
        let n: i32 = nums.len();
        while true {
            let l1 = rng.gen_range(0..n);
            let l2 = rng.gen_range(0..n);
            if l1 != l2 && nums[l1] == nums[l2] {
                return nums[l1];
            }
        }
    }
}