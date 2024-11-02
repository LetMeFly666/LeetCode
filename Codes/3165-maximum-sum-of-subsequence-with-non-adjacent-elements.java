/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 12:55:45
 */
class Solution {
    private long[][] tree;  // 诶，如果不是long的话会有两组数据无法通过
    private final int mod = 1000000007;

    private void maintain(int index) {
        long[] leftNode = tree[2 * index + 1];
        long[] rightNode = tree[2 * index + 2];
        tree[index][0] = Math.max(leftNode[0] + rightNode[2], leftNode[1] + rightNode[0]);
        tree[index][1] = Math.max(leftNode[0] + rightNode[3], leftNode[1] + rightNode[1]);
        tree[index][2] = Math.max(leftNode[2] + rightNode[2], leftNode[3] + rightNode[0]);
        tree[index][3] = Math.max(leftNode[2] + rightNode[3], leftNode[3] + rightNode[1]);
    }

    private void build(int[] nums, int index, int left, int right) {
        if (left == right) {
            tree[index][3] = Math.max(0, nums[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(nums, 2 * index + 1, left, mid);
        build(nums, 2 * index + 2, mid + 1, right);
        maintain(index);
    }

    private void update(int index, int left, int right, int modifiedI, int val) {
        if (left == right) {
            tree[index][3] = Math.max(0, val);
            return;
        }
        int mid = (left + right) / 2;
        if (modifiedI <= mid) {
            update(2 * index + 1, left, mid, modifiedI, val);
        } else {
            update(2 * index + 2, mid + 1, right, modifiedI, val);
        }
        maintain(index);
    }

    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        tree = new long[4 * nums.length][4];  // 00, 01, 10, 11
        build(nums, 0, 0, nums.length - 1);
        long ans = 0;
        for (int[] query : queries) {
            update(0, 0, nums.length - 1, query[0], query[1]);
            ans = (ans + tree[0][3]) % mod;
        }
        return (int)ans;
    }
}