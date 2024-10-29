/*
 * @Author: LetMeFly
 * @Date: 2024-10-29 23:29:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-29 23:39:09
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> validStrings(int n) {
        List<String> ans = new ArrayList<>();
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int x = i ^ mask;
            if ((x & (x >> 1)) == 0) {
                ans.add(Integer.toBinaryString((1 << n) | i).substring(1));  // 往n位“带有前导0的二进制”的前面加个1，再去掉
            }
        }
        return ans;
    }
}