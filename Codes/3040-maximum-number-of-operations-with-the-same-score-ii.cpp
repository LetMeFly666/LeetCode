/*
 * @Author: LetMeFly
 * @Date: 2024-06-08 12:06:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-08 13:42:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int** visited;
    int size;
    reference_wrapper<std::vector<int>> a;

    int dfs(int l, int r, int val) {  // [l, r)
        if (l + 1 >= r) {
            return 0;
        }
        if (visited[l][r - 1]) {
            return visited[l][r - 1];
        }
        int ans = 0;
        if (a.get()[l] + a.get()[l + 1] == val) {
            ans = max(ans, 1 + dfs(l + 2, r, val));
        }
        if (a.get()[r - 1] + a.get()[r - 2] == val) {
            ans = max(ans, 1 + dfs(l, r - 2, val));
        }
        if (a.get()[l] + a.get()[r - 1] == val) {
            ans = max(ans, 1 + dfs(l + 1, r - 1, val));
        }
        return visited[l][r - 1] = ans;
    }

    int get(int val) {
        // memset(visited, 0, sizeof(visited));  // 报错
        // memset(visited, 0, sizeof(int) * size * size);  // 报错
        for (int i = 0; i < size; i++) {
            memset(visited[i], 0, size * sizeof(int));
        }
        return dfs(0, size, val);
    }
public:
    Solution() : a(*(new std::vector<int>)) {}

    ~Solution() {
        for (int i = 0; i < size; i++) {
            delete[] visited[i];
        }
        delete[] visited;
    }

    int maxOperations(vector<int>& nums) {
        a = nums;
        size = nums.size();
        visited = new int*[size];
        for (int i = 0; i < size; i++) {
            visited[i] = new int[size];
        }
        return max(get(nums[0] + nums[1]), max(get(nums[size - 1] + nums[size - 2]), get(nums[0] + nums[size - 1])));
    }
};