/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 16:12:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 16:27:42
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < height.length; i++) {
            if (height[i - 1] > threshold) {
                ans.add(i);
            }
        }
        return ans;
    }
}