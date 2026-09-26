/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 18:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 18:23:59
 */
impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let mut ans = vec![0; n as usize];
        for i in 0..(n as usize) {
            let j = ((nums[i] + i as i32) % n + n) % n;  // 如果一路usize会无法得到负数
            ans[i] = nums[j as usize];
        }
        ans
    }
}