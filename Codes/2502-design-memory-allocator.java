/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:19:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:38:15
 */
class Allocator {
    private int[] v;
    private int n;

    public Allocator(int n) {
        v = new int[n];
        this.n = n;
    }
    
    public int allocate(int size, int mID) {
        for (int l = -1, r = 0, cnt = 0; r < n; r++) {
            if (v[r] != 0) {
                cnt = 0;
                l = r;
                continue;
            }
            cnt++;
            if (cnt == size) {
                while (++l <= r) {
                    v[l] = mID;
                }
                return r - size + 1;
            }
        }
        return -1;
    }
    
    public int freeMemory(int mID) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == mID) {
                ans++;
                v[i] = 0;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */