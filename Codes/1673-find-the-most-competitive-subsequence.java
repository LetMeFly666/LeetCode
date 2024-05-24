/*
 * @Author: LetMeFly
 * @Date: 2024-05-24 21:31:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-24 21:36:40
 */

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> st = new ArrayDeque<Integer>();
        for (int i = 0; i < nums.length; i++) {
            while (!st.isEmpty() && st.peek() > nums[i] && (st.size() - 1) + (nums.length - i) >= k) {
                st.pop();
            }
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }
        // stack -> array
        int[] ans = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }
        return ans;
    }
}