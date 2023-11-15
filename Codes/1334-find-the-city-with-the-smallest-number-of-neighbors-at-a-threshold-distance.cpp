/*
 * @Author: LetMeFly
 * @Date: 2023-11-14 23:01:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-14 23:17:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int find1City(vector<vector<pair<int, int>>> &graph, int start, int Md) {
        vector<bool> visited(graph.size(), false);
        vector<int> minDistance(graph.size(), 1e9);
        minDistance[start] = 0;
        for (int i = 0; i < graph.size(); i++) {
            int thisMinDistance = 1e9;
            int thisShortestPoint = -1;
            for (int j = 0; j < graph.size(); j++) {
                if (!visited[j] && minDistance[j] < thisMinDistance) {
                    thisMinDistance = minDistance[j];
                    thisShortestPoint = j;
                }
            }
            if (thisMinDistance == 1e9) {
                break;
            }
            visited[thisShortestPoint] = true;
            for (auto& [toPoint, thisDistance] : graph[thisShortestPoint]) {
                if (minDistance[thisShortestPoint] + thisDistance < minDistance[toPoint]) {
                    minDistance[toPoint] = minDistance[thisShortestPoint] + thisDistance;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < graph.size(); i++) {
            if (minDistance[i] <= Md) {
                ans++;
            }
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& v : edges) {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        int mCan = n, Mnum = 0;
        for (int i = 0; i < n; i++) {
            int thisCity = find1City(graph, i, distanceThreshold);
            if (thisCity <= mCan) {
                mCan = thisCity;
                Mnum = i;
            }
        }
        return Mnum;
    }
};