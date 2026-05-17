/*
 * @Author: LetMeFly
 * @Date: 2026-05-17 09:51:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-17 09:53:15
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<bool> visited;

    bool dfs(vector<int>& arr, int start) {
        if (visited[start]) {
            return false;
        }
        visited[start] = true;
        if (start - arr[i] >= 0 && dfs(arr, start - arr[i])) {
            return true;
        }
        if (start + arr[i] < arr.size() && dfs(arr, start + arr[i])) {
            return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size());
        return dfs(start);
    }
};
