/*
 * @Author: LetMeFly
 * @Date: 2022-10-17 10:15:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-17 10:36:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// #define FirstTry
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (vector<int>& p : people) {
            #ifdef FirstTry
            if (ans.size() <= p[1])  // 其实是不需要特判的，因为身高高的已经入队了，比p高的人一定够
                ans.push_back(p);
                // ans.insert(ans.begin() + 100000, p);
            else
            #else
            // Empty
            #endif
                ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

*/

/*
[[5,2],[7,0],[6,1]]

*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        debug(sol.reconstructQueue(v));
    }
    return 0;
}
#endif