/*
 * @Author: LetMeFly
 * @Date: 2026-03-15 10:21:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-15 10:59:43
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*


*/

typedef long long ll;
const ll MOD = 1e9 + 7;

class Fancy {
private:
    vector<Num> vals;
    Num add;
    Num mul;
public:
    Fancy() {}
    
    void append(int val) {
        vals.push_back((Num(val) - add) / mul);
    }
    
    void addAll(int inc) {
        add += inc;
    }
    
    void multAll(int m) {
        add *= m;
        mul *= m;
    }
    
    int getIndex(int idx) {
        return idx >= vals.size() ? -1 : (int)vals[idx];
    }
};

class Num {
private:
    ll val;

    ll power(ll a, ll n) const {
        ll ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
        }
        return ans;
    }
public:
    Num() {}
    Num(ll n) : val(n % MOD) {}
    Num(int n) : val(n % MOD) {}
    Num operator+(const ll& b) const { return Num((val + b) % MOD); }
    Num operator-(const ll& b) const { return Num((val - b + MOD) % MOD); }
    Num operator*(const ll& b) const { return Num(val * b % MOD); }
    Num operator/(const ll& b) const { return Num(val * power(b, MOD - 2) % MOD); }
    Num operator-(const Num& b) const { return Num((val - b.val + MOD) % MOD); }
    Num operator/(const Num& b) const { return Num(val * power(b.val, MOD - 2) % MOD); }
    Num& operator+=(const ll& b) { return *this = *this + b; }
    Num& operator-=(const ll& b) { return *this = *this - b; }
    Num& operator*=(const ll& b) { return *this = *this * b; }
    Num& operator/=(const ll& b) { return *this = *this / b; }
    operator int() const { return static_cast<int>(val); }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */