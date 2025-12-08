/*
 * @Author: LetMeFly
 * @Date: 2025-12-08 21:36:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-08 21:53:08
 */
impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut ans: i32 = 0;
        for a in 1..n+1 {
            for b in 1..n+1 {
                let k = a * a + b * b;
                let c = k.sqrt();
                if c as i32 <= n && c * c == k {
                    ans += 1;
                }
            }
        }
        ans
    }
}