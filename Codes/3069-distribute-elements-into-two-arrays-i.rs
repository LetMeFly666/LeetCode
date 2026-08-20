/*
 * @Author: LetMeFly
 * @Date: 2026-08-20 10:12:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-20 10:29:49
 */
impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        let mut v1 = vec![nums[0]];
        let mut v2 = vec![nums[1]];
        for &num in &nums[2..] {
            if v1[v1.len() - 1] > v2[v2.len() - 1] {
                v1.push(num);
            } else {
                v2.push(num);
            }
        }
        v1.extend(v2);
        v1
    }
}
