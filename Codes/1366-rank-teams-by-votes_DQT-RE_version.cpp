/*
 * @Author: LetMeFly
 * @Date: 2024-12-29 14:29:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-29 14:38:19
 * @Description: DQP(#12-#33): 如果#27是注释状态则不是WA而是RE
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string rankTeams(vector<string> votes) {
        int n=votes[0].size();
        vector<vector<int>>cnt(26,vector<int>(n,0));
        for(auto &s:votes){
            for(int i=0;i<n;i++)
                cnt[s[i]-'A'][i]++;
        }
        string res=votes[0];
        sort(res.begin(),res.end(),[&](const char &x,const char &y){
            vector<int>&a=cnt[x-'A'],&b=cnt[y-'A'];
            int n=a.size();
            for(int i=0;i<n;i++){
                if(a[i]>b[i]) return true;
                // else if(a[i]<b[i]) return false;
            }             
            return x<y;
        });
        return res;
    }
};

#ifdef _WIN32
/*
["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
*/
int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        vector<string> v = stringToVectorStringWithQuots(s);
        cout << sol.rankTeams(v) <<endl;
    }
    return 0;
}
#endif