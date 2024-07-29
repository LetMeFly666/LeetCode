/*
 * @Author: LetMeFly
 * @Date: 2024-07-29 22:45:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-29 22:49:52
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int calPoints(String[] operations) {
        List<Integer> score = new ArrayList<>();
        for (String op : operations) {
            switch (op.charAt(0)) {
                case '+':
                    score.add(score.get(score.size() - 1) + score.get(score.size() - 2));
                    break;
                case 'D':
                    score.add(score.get(score.size() - 1) * 2);
                    break;
                case 'C':
                    score.remove(score.size() - 1);
                    break;
                default:
                    score.add(Integer.parseInt(op));
                    break;
            }
        }
        int ans = 0;
        for (int t : score) {
            ans += t;
        }
        return ans;
    }
}