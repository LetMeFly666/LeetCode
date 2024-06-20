/*
 * @Author: LetMeFly
 * @Date: 2024-06-20 09:21:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-20 09:28:58
 */
import java.math.BigInteger;

class Solution {
    private BigInteger getFirst(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return BigInteger.valueOf(n);
    }

    public int countBeautifulPairs(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (getFirst(nums[i]).gcd(BigInteger.valueOf(nums[j] % 10)).equals(BigInteger.valueOf(1))) {
                    ans++;
                }
            }
        }
        return ans;
    }
}