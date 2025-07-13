/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 17:06:30
 */
import java.util.Arrays;

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int ans = 0;
        for (int p = 0, t = 0; p < players.length && t < trainers.length; t++) {
            if (trainers[t] >= players[p]) {
                ans++;
                p++;
            }
        }
        return ans;
    }
}