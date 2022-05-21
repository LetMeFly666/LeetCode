/*
 * @Author: LetMeFly
 * @Date: 2021-07-07 08:22:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-07 08:50:38
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)

//------Begin------
class Solution
{
    typedef long long ll;

private:
    // ll pows[38]; //1~37
    ll pows[22]; // 1!21
    ll mod;
    map<int, int> ma;

public:
    int countPairs(vector<int> &deliciousness)
    {
        ll ans = 0;
        for (vector<int>::iterator it = deliciousness.begin(); it != deliciousness.end(); it++)
        {
            ma[*it]++;
        }
        for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
        {
            int thisNum = it->first;
            for (int i = 0; i <= 21; i++)
            {
                int need = pows[i] - thisNum;
                if (need == thisNum)
                {
                    ans += 1LL * it->second * (it->second - 1) / 2;
                }
                else if (need > thisNum)
                {
                    if (ma.count(need)) // 存在再计数，不然到不了end()
                    {
                        ans += it->second * ma[need];
                    }
                }
                ans %= mod;
            }
        }
        return ans;
    }
    Solution()
    {
        mod = 1000000007;
        pows[0] = 1;
        for (int i = 1; i <= 21; i++)
        {
            pows[i] = pows[i - 1] * 2;
        }
    }
};
//------End--------
int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> v;
    fi(i, 0, n)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << sol.countPairs(v) << endl;
    system("pause");
    return 0;
}
/*
5
1 3 5 7 9

4
*/

/*
7
1 1 1 3 3 3 7

15
*/