/*
 * @Author: LetMeFly
 * @Date: 2024-02-29 08:53:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-29 14:28:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    int cnt;  // 以0为根时答对的数目
    int ans;
    int k;
    vector<vector<int>> graph;
    unordered_set<ll> se;


    void dfs(int thisNode, int lastNode=-1) {
        for (int nextNode : graph[thisNode]) {
            if (nextNode == lastNode) {
                continue;
            }
            if (se.count((ll)thisNode * 1000000 + nextNode)) {
                cnt++;
            }
            dfs(nextNode, thisNode);
        }
    }

    void change(int thisNode, int lastNode, int cnt) {
        int cnt_bak = cnt;
        for (int nextNode : graph[thisNode]) {
            if (nextNode == lastNode) {
                continue;
            }
            if (se.count((ll)thisNode * 1000000 + nextNode)) {
                cnt--;
            }
            if (se.count((ll)nextNode * 1000000 + thisNode)) {
                cnt++;
            }
            ans += cnt >= k;
            change(nextNode, thisNode, cnt);
            cnt = cnt_bak;
        }
    }
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        graph.resize(edges.size() + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (vector<int>& guess : guesses) {
            se.insert((ll)guess[0] * 1000000 + guess[1]);
        }
        cnt = 0;
        this->k = k;
        dfs(0);
        ans = cnt >= k;
        change(0, -1, cnt);
        return ans;
    }
};