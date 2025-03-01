/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:18:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:27:47
 */
import java.util.List;
import java.util.ArrayList;


class Solution {
    private List<List<String>> ans;
    private List<String> now;
    private String s;
    
    private boolean ok(int l, int r) {  // [l, r]
        for (; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
        }
        return true;
    }

    private void dfs(int l) {
        if (l == s.length()) {
            ans.add(new ArrayList<>(now));
            return;
        }
        for (int r = l; r < s.length(); r++) {
            if (ok(l, r)) {
                now.add(s.substring(l, r + 1));
                dfs(r + 1);
                now.remove(now.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        now = new ArrayList<>();
        this.s = s;
        dfs(0);
        return ans;
    }
}