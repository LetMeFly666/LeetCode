/*
 * @Author: LetMeFly
 * @Date: 2026-01-22 23:30:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-22 23:55:38
 */
impl Solution {
    fn finished(nums: &Vec<i32>) -> bool {
        for i in 1..nums.len() {
            if nums[i] < nums[i - 1] {
                return false;
            }
        }
        true
    }

    fn get_mini_pair_idx(nums: &Vec<i32>) -> usize {
        let mut idx = 0;
        let mut mini = 500001;
        for i in 0..nums.len() - 1 {
            let cnt = nums[i] + nums[i + 1];
            if cnt < mini {
                mini = cnt;
                idx = i;
            }
        }
        idx
    }

    fn merge(nums: &Vec<i32>, idx: usize) -> Vec<i32> {
        let mut ans = Vec::with_capacity(nums.len() - 1);
        for i in 0..idx {
            ans.push(nums[i]);
        }
        ans.push(nums[idx] + nums[idx + 1]);
        for i in idx + 2..nums.len() {
            ans.push(nums[i]);
        }
        ans
    }

    pub fn minimum_pair_removal(mut nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        while !Self::finished(&nums) {
            let idx = Self::get_mini_pair_idx(&nums);
            nums = Self::merge(&nums, idx);
            ans += 1;
        }
        ans
    }
}