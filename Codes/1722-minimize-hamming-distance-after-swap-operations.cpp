#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline void put(int node, vector<int>& source, vector<int>& target, vector<bool>& visited, vector<int>& a, unordered_multiset<int>& b, queue<int>& q) {
        q.push(node);
        visited[node] = true;
        a.push_back(source[node]);
        b.insert(target[node]);
    }

    int trace(int from, vector<int>& source, vector<int>& target, vector<vector<int>>& graph, vector<bool>& visited) {
        int ans = 0;
        queue<int> q;
        vector<int> a;
        unordered_multiset<int> b;
        
        put(from, source, target, visited, a, b, q);
        while (q.size()) {
            int from = q.front();
            q.pop();
            for (int to : graph[from]) {
                if (!visited[to]) {
                    put(from, source, target, visited, a, b, q);
                }
            }
        }

        for (int t : a) {
            unordered_multiset<int>::iterator it = b.find(t);
            if (it == b.end()) {
                ans++;
            } else {
                b.erase(it);
            }
        }
        return ans;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph(n);
        for (vector<int>& s : allowedSwaps) {
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans += trace(i, source, target, graph, visited);
            }
        }
        return ans;
    }
};
