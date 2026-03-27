/*
 * @Author: LetMeFly
 * @Date: 2026-03-27 08:48:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-27 09:07:38
 */
// THIS CANNOT BE ACCEPTED
impl Solution {
    pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
        let m = mat[0].len();
        for row in mat.iter() {
            for j in 0..row.len() {
                if (row[j] != row[(j + k) % m]) {
                    return false;
                }
            }
        }
        true
    }
}