/*
 * @Author: LetMeFly
 * @Date: 2026-04-24 20:58:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 21:07:01
 */
// java14+
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int flex = 0, diff = 0;
        for (int i = 0; i < moves.length(); i++) {
            switch (moves.charAt(i)) {
                case 'L' -> diff--;
                case 'R' -> diff++;
                default -> flex++;
            }
        }
        return diff > 0 ? flex + diff : flex - diff;
    }
}
