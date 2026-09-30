/*
 * @Author: LetMeFly
 * @Date: 2026-09-30 08:24:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-30 08:29:59
 */
impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let mut ans = Vec::with_capacity(seq.len());
        let mut layer = 0;
        for c in seq.bytes() {
            if c == b'(' {
                layer += 1;
                ans.push(layer % 2);
            } else {
                ans.push(layer % 2);
                layer -= 1;
            }
        }
        ans
    }
}
