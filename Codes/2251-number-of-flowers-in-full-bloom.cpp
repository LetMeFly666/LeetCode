/*
 * @Author: LetMeFly
 * @Date: 2023-09-28 10:46:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-28 10:58:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start(flowers.size()), end(flowers.size()), ans(people.size());
        for (int i = 0; i < flowers.size(); i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int i = 0; i < people.size(); i++) {
            // 到这一天为止的开花总数 - 到这一天的前一天为止的闭花总数
            int hanagasaku = upper_bound(start.begin(), start.end(), people[i]) - start.begin();  // 花が咲く(はながさく)
            int hanagatiru = upper_bound(end.begin(), end.end(), people[i] - 1) - end.begin();//  花が散る(はながちる)
            ans[i] = hanagasaku - hanagatiru;
        }
        return ans;
    }
};