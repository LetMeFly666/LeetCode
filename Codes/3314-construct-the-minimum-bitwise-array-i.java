/*
 * @Author: LetMeFly
 * @Date: 2026-01-20 22:50:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-20 23:04:56
 */
import java.util.List;

class Solution {
    private int get(int n) {
        for (int i = 0; i < n; i++) {
            if ((i | (i + 1)) == n) {
                return i;
            }
        }
        return -1;
    }

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] ans = new int[nums.size()];  // 是size不是length
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums.get(i));
        }
        return ans;
    }
}