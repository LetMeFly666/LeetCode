/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-21 14:38:38
 */
// M: !9->9
// m: first==1 ? !01->0 : first->1
class Solution {
    private int not9(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '9') {
                return i;
            }
        }
        return -1;
    }

    private int not01(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) > '1') {
                return i;
            }
        }
        return -1;
    }

    private int replace(String s, char a, char b) {
        return Integer.parseInt(s.replace(a, b));
    }
    public int maxDiff(int num) {
        int M, m;
        String s = String.valueOf(num);
        int index = not9(s);
        M = index == -1 ? num : replace(s, s.charAt(index), '9');
        if (s.charAt(0) == '1') {
            index = not01(s);
            m = index == -1 ? num : replace(s, s.charAt(index), '0');
        } else {
            m = replace(s, s.charAt(0), '1');
        }
        return M - m;
    }
}