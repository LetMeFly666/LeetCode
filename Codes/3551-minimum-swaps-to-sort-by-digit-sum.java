/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 20:22:23
 */
import java.util.Arrays;

class Union {
    private final int[] parent;
    private final int[] sz;
    int count;

    Union(int n) {
        parent = new int[n];
        sz = new int[n];
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        }
        count--;
        if (sz[px] > sz[py]) {
            int tmp = px;
            px = py;
            py = px;
        }
        sz[py] += sz[px];
        parent[px] = py;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
}

class Solution {
    private int getSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; i++) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (a, b) -> {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] - nums[b] : sa - sb;
        });

        Union union = new Union(n);
        for (int i = 0; i < n; i++) {
            union.merge(i, idxs[i]);
        }
        return n - union.count;
    }
}
