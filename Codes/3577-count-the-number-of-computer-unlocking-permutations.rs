/*
 * @Author: LetMeFly
 * @Date: 2025-12-10 22:34:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-10 23:04:47
 */
impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let mut ans: i64 = 1;
        let MOD: i64 = 1000000007;
        for i in 1..complexity.len() {
            if complexity[i] <= complexity[0] {
                return 0;
            }
            ans = ans * i % MOD;
        }
        ans as i32
    }
}