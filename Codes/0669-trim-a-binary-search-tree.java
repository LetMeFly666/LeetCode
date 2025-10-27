/*
 * @Author: laughWinter
 * @Date: 2025-10-26 23:16:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-27 09:42:30
 */
// import javax.swing.tree.TreeNode;

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

class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        //寻找新的根节点
        while ((root != null) && ((root.val < low) || (root.val > high))) {
            if (root.val < low) {
                root = root.right;
            } else if (root.val > high) {
                root = root.left;
            }
        }
        if (root == null) {
            return null;
        }
        //修建root的左右子树
        TreeNode tmp = root;
        while (tmp.left != null) {
            if (tmp.left.val < low) {
                tmp.left = tmp.left.right;
            } else {
                tmp = tmp.left;
            }
        }
        tmp = root;
        while (tmp.right != null) {
            if (tmp.right.val > high) {
                tmp.right = tmp.right.left;
            } else {
                tmp = tmp.right;
            }
        }

        return root;
    }
}