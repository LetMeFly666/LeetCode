/*
 * @Author: LetMeFly
 * @Date: 2021-11-14 14:41:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-14 14:44:20
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class MapSum {
private:
    map<string, int> ma;
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        ma[key] = val;
    }
    
    int sum(string prefix) {
        int l = prefix.size();
        int ans = 0;
        for (pair<string, int> p : ma) {
            if (p.first.substr(0, l) == prefix) {
                ans += p.second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */