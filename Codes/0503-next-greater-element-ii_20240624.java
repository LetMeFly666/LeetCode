/*
 * @Author: LetMeFly
 * @Date: 2024-06-24 12:52:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-24 12:59:26
 */
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] ans = new int[nums.length];
        Arrays.fill(ans, -1);
        Deque<Integer> st = new LinkedList<Integer>();
        for (int i = 0; i < nums.length * 2; i++) {
            int th = i % nums.length;
            while (st.size() > 0 && nums[st.peek()] < nums[th]) {
                ans[st.pop()] = nums[th];
            }
            st.push(th);
        }
        return ans;
    }
}