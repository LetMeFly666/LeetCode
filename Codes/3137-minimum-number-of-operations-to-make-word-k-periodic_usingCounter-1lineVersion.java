/*
 * @Author: LetMeFly
 * @Date: 2024-08-17 16:35:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-17 17:10:07
 */
import java.util.HashMap;

class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        int maxTimes = 1;
        HashMap<String, Integer> ma = new HashMap<String, Integer>();
        for (int i = 0; i < word.length(); i += k) {
            // maxTimes = ma.merge(word.substring(i, i + k), 1, (a, b) -> {a += b; maxTimes = Math.max(maxTimes, a); return a;});
            maxTimes = Math.max(maxTimes, ma.merge(word.substring(i, i + k), 1, Integer::sum));
        }
        return word.length() / k - maxTimes;
    }
}