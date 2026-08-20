/*
 * @Author: LetMeFly
 * @Date: 2026-08-20 10:12:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-20 10:22:02
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> v1 = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        v1.add(nums[0]);
        v2.add(nums[1]);

        for (int i = 2, n = nums.length; i < n; i++) {
            (v1.getLast() > v2.getLast() ? v1 : v2).add(nums[i]);
        }
        v1.addAll(v2);
        return v1.stream().mapToInt(i -> i).toArray();
    }
}
