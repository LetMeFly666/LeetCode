/*
 * @Author: LetMeFly
 * @Date: 2026-07-08 11:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-08 11:58:39
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| (x[0], -x[1]));
        let mut ans = intervals.len() as i32;
        let mut maxr = 0;
        for v in intervals.iter() {
            if v[1] <= maxr {
                ans -= 1;
            } else {
                maxr = v[1];
            }
        }
        ans
    }
}
