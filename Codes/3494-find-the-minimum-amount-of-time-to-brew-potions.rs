/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:52:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 23:18:22
 */
impl Solution {
    pub fn min_time(skill: Vec<i32>, mana: Vec<i32>) -> i64 {
        let n: usize = skill.len();
        let mut times: Vec<i64> = vec![0; n];
        for m in mana {
            let mut last_time: i64 = times[0] + (skill[0] * m) as i64;
            for i in 1..n {
                last_time = last_time.max(times[i]) + (skill[i] * m) as i64;
            }
            times[n-1] = last_time;
            for i in (0..n-1).rev() {
                times[i] = times[i + 1] - (skill[i + 1] * m) as i64;
            }
        }
        times[n-1]
    }
}