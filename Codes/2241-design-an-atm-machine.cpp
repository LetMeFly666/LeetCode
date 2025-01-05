/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 19:01:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 19:07:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class ATM {
private:
    int money[5] = {0, 0, 0, 0, 0};
    const int per[5] = {20, 50, 100, 200, 500};
public:
    ATM() {}
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            money[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        for (int i = 4; i >= 0 && amount; i--) {
            ans[i] = min(money[i], amount / per[i]);
            amount -= ans[i] * per[i];
        }
        if (amount) {
            return {-1};
        }
        for (int i = 0; i < 5; i++) {
            money[i] -= ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */