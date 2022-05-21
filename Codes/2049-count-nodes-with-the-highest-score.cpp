/*
 * @Author: LetMeFly
 * @Date: 2022-03-11 16:54:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-11 18:51:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

class Node {
public:
    int l, r;
} node[100010];

class Solution {
private:
    ll maxScore = 0;
    vector<ll> scores;
    int allNum;

    void built(vector<int>& parents) {
        for (int i = 1; i < allNum; i++) {
            if (node[parents[i]].l == -1)
                node[parents[i]].l = i;
            else
                node[parents[i]].r = i;
        }
    }

    int dfs(int nodeNum) {  // -> childs with(including) this Node
        if (nodeNum == -1)
            return 0;
        int leftNum = dfs(node[nodeNum].l);
        int rightNum = dfs(node[nodeNum].r);
        ll thisScore = 1;
        if (leftNum)
            thisScore *= leftNum;
        if (rightNum)
            thisScore *= rightNum;
        if (allNum - leftNum - rightNum - 1)
            thisScore *= allNum - leftNum - rightNum - 1;
        scores.push_back(thisScore);
        maxScore = max(maxScore, thisScore);
        return leftNum + rightNum + 1;
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        allNum = parents.size();
        for (int i = 0; i < allNum; i++) {
            node[i].l = node[i].r = -1;
        }
        built(parents);
        dfs(0);
        int ans = 0;
        for (ll& t : scores) {
            ans += t == maxScore;
        }
        return ans;
    }
};