/*
 * @Author: LetMeFly
 * @Date: 2024-05-28 22:16:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-28 22:18:39
 */
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < mountain.length - 1; i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.add(i);
                i++;
            }
        }
        return ans;
    }
}