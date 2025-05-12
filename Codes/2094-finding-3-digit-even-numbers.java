/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 10:20:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:32:22
 */
import java.util.Array;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] times = new int[10];
        for (int d : digits) {
            times[d]++;
        }
        Array<Integer> ans = new Array<>();
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
        Arrays.sort(ans);
        return new int[]{ans};
    }
}