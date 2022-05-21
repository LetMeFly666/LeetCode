/*
 * @Author: LetMeFly
 * @Date: 2022-03-18 09:33:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-18 10:46:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

class Bank {
private:
    #ifdef FirstTry_TryToUseLesserMemory
    vector<ll> *p;
    vector<ll> &v = *p;
    #else
    vector<ll> v;
    #endif
public:
    Bank(vector<long long>& balance) {
        #ifdef FirstTry_TryToUseLesserMemory
        p = &balance;
        v = *p;
        #else
        v = balance;
        #endif
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > v.size() || account2 > v.size() || v[account1 - 1] < money)
            return false;
        v[account1 - 1] -= money;
        v[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > v.size())
            return false;
        v[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > v.size() || v[account - 1] < money)
            return false;
        v[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

#ifdef _WIN32
int main() {
    vector<int> a = {1, 2};
    vector<int> &b = a;
    b[0] = 0;
    cout << a[0] << endl;
    system("pause");
    return 0;
}
#endif