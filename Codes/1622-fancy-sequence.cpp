/*
 * @Author: LetMeFly
 * @Date: 2026-03-15 10:21:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-15 11:19:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;


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
    Num(): val(0) {}  // 记得初始化val
    Num(ll n) : val(n % MOD) {}
    Num(int n) : val(n % MOD) {}
    Num operator+(const ll& b) const { return Num((val + b) % MOD); }
    Num operator-(const ll& b) const { return Num((val - b + MOD) % MOD); }
    Num operator*(const ll& b) const { return Num(val * b % MOD); }
    Num operator/(const ll& b) const { return Num(val * power(b, MOD - 2) % MOD); }
    Num operator+(const Num& b) const { return Num((val + b.val) % MOD); }
    Num operator-(const Num& b) const { return Num((val - b.val + MOD) % MOD); }
    Num operator*(const Num& b) const { return Num(val * b.val % MOD); }
    Num operator/(const Num& b) const { return Num(val * power(b.val, MOD - 2) % MOD); }
    Num& operator+=(const ll& b) { return *this = *this + b; }
    Num& operator-=(const ll& b) { return *this = *this - b; }
    Num& operator*=(const ll& b) { return *this = *this * b; }
    Num& operator/=(const ll& b) { return *this = *this / b; }
    operator int() const { return static_cast<int>(val); }
};

class Fancy {
private:
    vector<Num> vals;
    Num add;
    Num mul;
public:
    Fancy() {
        mul = Num(1);
    }
    
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
        return idx >= vals.size() ? -1 : (int)(vals[idx] * mul + add);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
#ifdef _DEBUG
/*
["Fancy","append","addAll","append","multAll","getIndex","addAll","append","multAll","getIndex","getIndex","getIndex"]
[[],[2],[3],[7],[2],[0],[3],[10],[2],[0],[1],[2]]

*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<string> va = stringToVectorString(a);
        vector<vector<int>> vb = stringToVectorVector(b);
        if (va.size() != vb.size()) {
            cout << "ERROR length" << endl;
            continue;
        }
        Fancy fancy;
        for (int i = 0; i < va.size(); i++) {
            string s = va[i];
            if (!s.empty() && s[0] == '"') {
                s.erase(s.begin());
            }
            if (!s.empty() && s.back() == '"') {
                s.erase(prev(s.end()));
            }
            int val = vb[i].empty() ? 0 : vb[i][0];
            if (s == "Fancy") {
                fancy = Fancy();
            } else if (s == "append") {
                fancy.append(val);
            } else if (s == "addAll") {
                fancy.addAll(val);
            } else if (s == "multAll") {
                fancy.multAll(val);
            } else if (s == "getIndex") {
                cout << fancy.getIndex(val) << endl;
            } else {
                cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}
#endif
