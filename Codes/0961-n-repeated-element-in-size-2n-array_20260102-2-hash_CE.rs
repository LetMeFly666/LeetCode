/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 18:01:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 18:05:37
 */
// THIS IS CE
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let mut visited = HashSet::new();
        for t in nums.iter() {
            if visited.contains(&t) {
                return t;
            }
            visited.insert(t);
        }
        -1  // FAKE RETURN
    }
}