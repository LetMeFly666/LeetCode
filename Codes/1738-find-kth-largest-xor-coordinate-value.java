/*
 * @Author: LetMeFly
 * @Date: 2024-05-26 09:29:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-26 09:35:26
 */
import java.util.ArrayList;
import java.util.Comparator;

class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int[][] prefix = new int[matrix.length + 1][matrix[0].length + 1];
        ArrayList<Integer> vals = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j];
                vals.add(prefix[i + 1][j + 1]);
            }
        }
        vals.sort(Comparator.naturalOrder());
        return vals.get(vals.size() - k);
    }
}