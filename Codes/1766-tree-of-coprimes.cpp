/*
 * @Author: LetMeFly
 * @Date: 2024-04-11 12:19:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-11 13:07:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> gcds;   // gcds[i]: 和i互质的所有数（题目范围内）
    vector<vector<int>> path;   // path: dfs到当前节点时所有的祖先节点 | path[i]: 值为i的祖先节点们
    vector<int> num2depth;      // num2depth[i]: 节点i的深度（默认值为0）
    vector<vector<int>> graph;  // graph[i]: 节点i的所有相邻节点
    vector<int> ans;            // ans: 最终要返回的答案

    void initGcds() {
        gcds.resize(51);
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (__gcd(i, j) == 1) {
                    gcds[i].push_back(j);
                    gcds[j].push_back(i);
                }
            }
        }
    }

    void initPath() {
        path.resize(51);
    }

    void initNum2depth(vector<int>& nums) {
        num2depth.resize(nums.size());
    }

    void initGraph(vector<int>& nums, vector<vector<int>>& edges) {
        graph.resize(nums.size());
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    void initAns(vector<int>& nums) {
        ans = vector<int>(nums.size(), -1);
    }

    void dfs(vector<int>& nums, int num, int depth) {
        num2depth[num] = depth;
        for (int coprime : gcds[nums[num]]) {
            if (path[coprime].size()) {
                int lastNum = path[coprime].back();
                if (ans[num] == -1 || num2depth[lastNum] > num2depth[ans[num]]) {
                    ans[num] = lastNum;
                }
            }
        }
        path[nums[num]].push_back(num);
        for (int nextNum : graph[num]) {
            if (!num2depth[nextNum]) {
                dfs(nums, nextNum, depth + 1);
            }
        }
        path[nums[num]].pop_back();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        initGcds();
        initPath();
        initNum2depth(nums);
        initGraph(nums, edges);
        initAns(nums);
        dfs(nums, 0, 1);  // 根节点视为1层，和默认值不同
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