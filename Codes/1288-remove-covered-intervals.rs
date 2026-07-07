/*
 * @Author: LetMeFly
 * @Date: 2026-07-07 22:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-07 22:34:51
 */
impl Solution {
    pub fn remove_covered_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| (x[0], -x[1]));
        let mut ans = intervals.len() as i32;
        let mut r = 0;
        for v in intervals.iter() {
            if v[1] <= r {
                ans -= 1;
            } else {
                r = v[1];
            }
        }
        return ans;
    }
}
