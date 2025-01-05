/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 19:28:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 19:33:23
 */
class ATM {
    private long[] cnt, val;

    public ATM() {
        cnt = new long[5];
        val = new long[]{20, 50, 100, 200, 500};
    }
    
    public void deposit(int[] banknotesCount) {
        for (int i = 0; i < 5; i++) {
            cnt[i] += banknotesCount[i];
        }
    }
    
    public int[] withdraw(int amount) {
        int[] ans = new int[5];
        for (int i = 4; i >= 0; i--) {
            ans[i] = (int)Math.min(cnt[i], amount / val[i]);
            amount -= ans[i] * val[i];
        }
        if (amount > 0) {
            return new int[]{-1};
        }
        for (int i = 0; i < 5; i++) {
            cnt[i] -= ans[i];
        }
        return ans;
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * ATM obj = new ATM();
 * obj.deposit(banknotesCount);
 * int[] param_2 = obj.withdraw(amount);
 */