/*
 * @Author: LetMeFly
 * @Date: 2026-04-24 20:58:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 23:07:48
 */
impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut diff = 0;
        let mut flex = 0;
        for c in moves.chars() {
            match c {
                'L' => diff -= 1,
                'R' => diff += 1,
                _ => flex += 1,
            }
        }
        if diff > 0 {
            diff + flex
        } else {
            flex - diff
        }
    }
}
