/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 07:59:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:12:34
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
                maxr = r;
            }
        }
        ans
    }
}
