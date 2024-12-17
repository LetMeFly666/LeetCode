/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 22:28:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-16 22:36:57
 */
import java.util.TreeSet;

public class TreeSetExample {
    public static void main(String[] args) {
        // 创建
        TreeSet<Integer> se = new TreeSet<>();
        // 添加元素
        se.add(20);
        se.add(10);
        se.add(10);  // 重复元素不会被添加
        // 打印
        System.out.println(se);  // [10, 20]
        // 查找
        se.contains(10);  // true
        se.floor(10);  // ≤10的最大元素 （若无则返回null）  // 10
        se.ceiling(10);  // ≥10的最大元素 （若无则返回null）  // 10
        se.higher(10);  // >10的最小元素 （若无则返回null）  // 20
        se.lower(10);  // <10的最大元素 （若无则返回null）  // null
    }
}