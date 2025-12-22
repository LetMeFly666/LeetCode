/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 23:04:04
 */
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs[0].len();
        let mut ans = vec![0; m];
        for cur in 0..m {
            for prev in 0..cur {
                if ans[prev] > ans[cur] && strs.iter().all(|s| s.as_bytes()[prev] <= s.as_bytes()[cur]) {
                    ans[cur] = ans[prev];
                }
            }
            ans[cur]++;
        }
        m as i32 - *dp.iter().max().unwarp()
    }
}