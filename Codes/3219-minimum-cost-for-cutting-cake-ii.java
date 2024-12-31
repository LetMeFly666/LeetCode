/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:14:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:22:22
 */
import java.util.Arrays;

class Solution {
    public long minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        // Arrays.sort(horizontalCut, (a, b) -> b - a);  // 不可，Arrays.sort(int[])时不支持自定义排序
        Arrays.sort(horizontalCut);  // 那就从小到大排序然后下面反着遍历吧
        Arrays.sort(verticalCut);
        int hCutTime = m - 2, vCutTime = n - 2;
        long ans = 0;
        while (hCutTime >= 0 || vCutTime >= 0) {
            if (vCutTime < 0 || hCutTime >= 0 && horizontalCut[hCutTime] > verticalCut[vCutTime]) {
                ans += horizontalCut[hCutTime--] * (n - vCutTime - 1);
            } else {
                ans += verticalCut[vCutTime--] * (m - hCutTime - 1);
            }
        }
        return ans;
    }
}