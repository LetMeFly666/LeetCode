/*
 * @Author: LetMeFly
 * @Date: 2024-09-04 12:42:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-04 13:12:10
 */
import java.util.List;
import java.util.Collections;

class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int ans = 1 + (nums.get(0) > 0 ? 1 : 0);
        for (int i = 1; i < nums.size(); i++) {
            ans += i > nums.get(i - 1) && i < nums.get(i) ? 1 : 0;
        }
        return ans;
    }
}