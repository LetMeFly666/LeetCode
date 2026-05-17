/*
 * @Author: LetMeFly
 * @Date: 2026-05-17 09:51:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-17 09:54:49
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
        if (start - arr[start] >= 0 && dfs(arr, start - arr[start])) {
            return true;
        }
        if (start + arr[start] < arr.size() && dfs(arr, start + arr[start])) {
            return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size());
        return dfs(arr, start);
    }
};
