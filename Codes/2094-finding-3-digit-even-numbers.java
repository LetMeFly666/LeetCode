/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 10:20:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:35:02
 */
import java.util.Arrays;
import java.util.ArrayList;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] times = new int[10];
        for (int d : digits) {
            times[d]++;
        }
        List<Integer> ans = new Array<>();
        for (int i = 100; i < 1000; i += 2) {
            int tmp = i;
            int[] thisTimes = new int[10];
            while (tmp > 0) {
                thisTimes[tmp % 10]++;
                tmp /= 10;
            }
            boolean ok = true;
            for (int j = 0; j < 10; j++) {
                if (thisTimes[j] > times[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(i);
            }
        }
        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }
        return res;
    }
}