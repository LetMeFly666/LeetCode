/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:38:47
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            if (words[i].indexOf(x) >= 0) {
                ans.add(i);
            }
        }
        return ans;
    }
}