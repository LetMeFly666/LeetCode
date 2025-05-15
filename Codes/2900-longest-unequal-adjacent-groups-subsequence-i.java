/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 13:22:29
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < groups.length; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.add(words[i]);
            }
        }
        return ans;
    }
}