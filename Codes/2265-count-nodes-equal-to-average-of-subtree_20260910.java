/*
 * @Author: LetMeFly
 * @Date: 2026-09-10 14:38:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-10 14:47:52
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
record Result (int val, int n) {}

class Solution {
    private int ans;

    private Result dfs(TreeNode root) {
        if (root == null) {
            return new Record(0, 0);
        }
        Result left = dfs(root.left);
        Result right = dfs(root.right);
        int val = root.val + left.val() + right.val();
        int n = 1 + left.n() + right.n();
        if (val / n == root.val) {
            ans++;
        }
        return new Record(val, n);
    }

    public int averageOfSubtree(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }
}
