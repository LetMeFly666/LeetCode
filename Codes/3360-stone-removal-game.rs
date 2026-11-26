/*
 * @Author: LetMeFly
 * @Date: 2026-11-26 07:52:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-26 08:05:26
 */
impl Solution {
    pub fn can_alice_win(mut n: i32) -> bool {
        let mut state = false;
        let mut need = 10;
        while n >= need {
            n -= need;
            need -= 1;
            state = !state;
        }
        state
    }
}
