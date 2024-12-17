/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 22:40:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-16 22:48:53
 */
import java.util.Arrays;

public class ArrayExample {
    public static void main(String[] args) {
        int[] intList = {1, 4, 2};
        Integer[] integerList = {3, -6, 4};
        // 排序
        Arrays.sort(intList);
        Arrays.sort(integerList, (a, b) -> Math.abs(a) - Math.abs(b));  // int[]不支持sort的自定义Comparator
        // 填充
        Arrays.fill(intList, 1);  // 填充为[1, 2, 3]
        // 相等
        Arrays.equals(intList, new int[1]);
    }
}
