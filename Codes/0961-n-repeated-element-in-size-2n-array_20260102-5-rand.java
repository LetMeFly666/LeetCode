/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:53:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:54:45
 */
import java.util.Random;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Random random = new Random();
        int n = nums.length;
        while (true) {
            int l1 = random.nextInt(n);
            int l2 = random.nextInt(n);
            if (l1 != l2 && nums[l1] == nums[l2]) {
                return nums[l1];
            }
        }
    }
}