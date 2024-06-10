/*
 * @Author: LetMeFly
 * @Date: 2024-06-10 15:21:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-10 15:23:36
 */
import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0;
        for (int l = 0, r = people.length - 1; l <= r; ans++, r--) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
        }
        return ans;
    }
}