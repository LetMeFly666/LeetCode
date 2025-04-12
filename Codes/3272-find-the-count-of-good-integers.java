/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 10:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 11:13:08
 */
import java.util.Set;
import java.util.HashSet;
// import java.lang.StringBuilder;  // 默认自动导入 无需手动导入
import java.util.Arrays;

class Solution {
    private int k;
    private int[] factor;
    private Set<String> visited = new HashSet<>();

    private boolean isOk(String s) {
        return Long.parseLong(s) % k == 0;
    }

    private boolean ifVisited(String s) {
        char[] array = s.toCharArray();
        Arrays.sort(array);
        String sorted = new String(array);
        return !visited.add(sorted);
    }

    private long calc(String s) {
        int[] times = new int[10];
        for (char c : s.toCharArray()) {
            times[c - '0']++;
        }
        long ans = (s.length() - times[0]) * factor[s.length() - 1];
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }

    public long countGoodIntegers(int n, int k) {
        this.k = k;
        factor = new int[n + 1];
        factor[0] = 1;
        for (int i = 1; i <= n; i++) {
            factor[i] = factor[i - 1] * i;
        }
        long ans = 0;
        for (int from = (int)Math.pow(10, (n - 1) / 2), to = from * 10; from < to; from++) {
            String prefix = String.valueOf(from);
            String suffix = new StringBuilder(prefix).reverse().substring(n % 2);
            String s = prefix + suffix;
            if (isOk(s) && !ifVisited(s)) {
                ans += calc(s);
            }
        }
        return ans;
    }
}

/*
API:

java 子字符串
反转字符串
整数转字符串
字符串拼接
字符串转整数
*/