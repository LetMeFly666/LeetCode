/*
 * @Author: LetMeFly
 * @Date: 2026-05-08 20:06:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-08 20:23:18
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

const int M = 1000001;
vector<int> primes[M];

int init = []{
    for (int i = 2; i < M; i++) {
        if (primes[i].empty()) {  // i是质数
            for (int j = i; j < M; j += i) {
                primes[j].push_back(i);  // i是j的因数
            }
        }
    }
    return 0;
}();

class Solution {
private:
    inline void toQueue(queue<int>& q, vector<bool>& visited, int n) {
        if (visited[n]) {
            return;
        }
        q.push(n);
        visited[n] = true;
    }
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> jumps;
        for (int i = 0; i < nums.size(); i++) {
            for (int p : primes[nums[i]]) {
                jumps[p].push_back(i);
            }
        }
        
        vector<bool> visited(nums.size());
        queue<int> q;
        toQueue(q, visited, 0);
        for (int ans = 0; ; ans++) {
            queue<int> nextQueue;
            while (q.size()) {
                int now = q.front();
                q.pop();
                if (now == nums.size() - 1) {
                    return ans;
                }
                toQueue(nextQueue, visited, now + 1);
                if (now) {
                    toQueue(nextQueue, visited, now - 1);
                }
                for (int next : jumps[nums[now]]) {
                    toQueue(nextQueue, visited, next);
                }
                jumps[nums[now]].clear();  // 防止重复遍历
            }
            swap(q, nextQueue);
        }
    }
};
