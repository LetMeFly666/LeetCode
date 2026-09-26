#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:    
    int cal(unordered_map<ll, int>& cnt, ll a) {
        int ans = 0;
        while (cnt.contains(a) && cnt[a] >= 2) {
            ans += 2;
            a *= a;
        }
        ans += cnt.contains(a) ? 1 : -1;
        return ans;
    }
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> cnt;
        for (int t : nums) {
            cnt[t]++;
        }

        int ans = cnt[1];  // 特判1防止死循环
        if (ans % 2 == 0) {
            ans--;
        }
        cnt.erase(1);

        for (auto[a, _] : cnt) {
            ans = max(ans, cal(cnt, a));
        }
        return ans;
    }
};
