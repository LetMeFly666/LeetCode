/*
 * @Author: LetMeFly
 * @Date: 2026-01-06 10:19:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-06 10:50:12
 */
import java.util.Deque;
import java.util.ArrayDeque;

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
// THIS CANNOT BE ACCEPTED
class Solution {
    public int maxLevelSum(TreeNode root) {
        int ans = 0, maximum = -1000000000;
        int layerNum = 0;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            layerNum++;
            int layerSum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode node = q.poll();
                layerNum += node.val;
                if (node.left) {
                    q.offer(node.left);
                }
                if (node.right) {
                    q.offer(node.right);
                }
            }
            if (layerSum > maximum) {
                maximum = layerSum;
                ans = layerNum;
            }
        }
        return ans;
    }
}