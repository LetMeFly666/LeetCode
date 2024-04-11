/*
 * @Author: LetMeFly
 * @Date: 2024-04-11 12:19:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-11 12:30:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static vector<vector<int>> gcds;   // gcds[i]: 和i互质的所有数（题目范围内）
    vector<vector<int>> path;          // path: dfs到当前节点时所有的祖先节点 | path[i]: 值为i的祖先节点们
    vector<int> num2depth;             // num2depth[i]: 节点i的深度
    vector<vector<int>> graph;         // graph[i]: 节点i的所有相邻节点
    vector<int> ans;                   // ans: 最终要返回的答案

    void initGcds() {  // 不论创建多少个Solution类，gcds只需要被计算一次
        if (gcds.size()) {
            return;
        }
        puts("Begin to init...");
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        initGcds();
        return ans;
    }
};

#ifdef _WIN32
/*
[2,3,3,2]
[[0,1],[1,2],[1,3]]

[-1,0,0,1]
*/
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<int> v1 = stringToVector(s1);
        vector<vector<int>> v2 = stringToVectorVector(s2);
        Solution sol;
        debug(sol.getCoprimes(v1, v2));
    }
    return 0;
}
#endif