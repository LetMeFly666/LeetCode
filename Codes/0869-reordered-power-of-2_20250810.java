/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 20:51:10
 */
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

class Solution {
    private static final Set<String> can = new HashSet<>();

    static {
        for (int i = 0; i < 31; i++) {
            can.add(itoa(1 << i));
        }
    }

    private static String itoa(int n) {
        char[] s = String.valueOf(n).toCharArray();
        Arrays.sort(s);
        return new String(s);
    }

    public boolean reorderedPowerOf2(int n) {
        return can.contains(itoa(n));
    }
}