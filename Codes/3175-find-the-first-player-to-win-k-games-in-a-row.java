/*
 * @Author: LetMeFly
 * @Date: 2024-10-24 12:23:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-24 12:24:38
 */
class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        int maxLoc = 0;
        for (int curLoc = 1, cnt = 0; curLoc < skills.length && cnt < k; curLoc++) {
            if (skills[maxLoc] > skills[curLoc]) {
                cnt++;
            } else {
                maxLoc = curLoc;
                cnt = 1;
            }
        }
        return maxLoc;
    }
}