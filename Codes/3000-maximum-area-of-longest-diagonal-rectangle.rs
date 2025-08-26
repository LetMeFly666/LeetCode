/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:40:59
 */
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut ans: i32 = 0;
        let mut m: i32 = 0;
        for d in dimensions.iter() {
            let l2: i32 = d[0] * d[0] + d[1] * d[1];
            if l2 > m {
                m = l2;
                ans = d[0] * d[1];
            } else if l2 == m {
                ans = ans.max(d[0] * d[1]);
            }
        }
        ans
    }
}