/*
 * @Author: LetMeFly
 * @Date: 2022-09-26 09:13:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-26 09:24:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static bool cmp(vector<string>& a, vector<string>& b) {
        return a[1] < b[1];
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        sort(tickets.begin(), tickets.end(), cmp);
        for (vector<string>& v : tickets) {
            graph[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        vector<string> ans;
        list<string> q;
        for (auto& [airport, thisIn] : indegree) {
            if (!thisIn) {
                q.push_back(airport);
            }
        }
        // sort(q.begin(), q.end());
        q.sort();
        while (q.size()) {
            string thisAirport = q.back();
            q.pop_back();
            ans.insert(ans.begin(), thisAirport);
            for (string& thisTo : graph[thisAirport]) {
                indegree[thisTo]--;
                if (!indegree[thisTo]) {
                    q.push_back(thisTo);
                }
            }
        }
        return ans;
    }
};