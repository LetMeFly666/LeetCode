/*
 * @Author: LetMeFly
 * @Date: 2024-12-29 21:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-30 02:16:01
 */
// 好复杂
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        int[][] counts = new int[26][n];
        for (String vote : votes) {
            for (int i = 0; i < n; i++) {
                counts[vote.charAt(i) - 'A'][i]++;
            }
        }
        Character[] charList = new Character[n];
        for (int i = 0; i < n; i++) {
            charList[i] = votes[0].charAt(i);
        }
        Arrays.sort(charList, new Comparator<Character>() {
            @Override
            public int compare(Character a, Character b) {
                int c = Arrays.compare(counts[b - 'A'], counts[a - 'A']);
                return c == 0 ? a - b : c;
            }
        });
        String ans = new String();
        for (Character c : charList) {
            ans += c;
        }
        return ans;
    }
}