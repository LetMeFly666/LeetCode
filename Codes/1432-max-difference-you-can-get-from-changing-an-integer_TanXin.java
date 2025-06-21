/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-21 14:33:02
 */
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
        char[] ca = s.toCharArray();
        for (int i = 0; i < s.lengtj(); i++) {
            if (ca[i] == a) {
                ca[i] = b;
            }
        }
        return 
    }
    public int maxDiff(int num) {
        // M: !9->9
        // m: first==1 ? !01->0 : first->1

    }
}