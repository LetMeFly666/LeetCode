/*
 * @Author: LetMeFly
 * @Date: 2024-06-02 09:41:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-02 09:44:00
 */
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> se = new HashSet<>();
        for (int t : candyType) {
            se.add(t);
        }
        return Math.min(se.size(), candyType.length / 2);
    }
}