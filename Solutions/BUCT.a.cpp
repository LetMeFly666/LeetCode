/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-01 19:36:20
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1e9

/*
5 7 0
0 1 2
1 3 4
0 3 8
0 2 9
4 0 1
4 0 5
4 2 1
*/

int main() {
    // init
    int n, m, start;
    cin >> n >> m >> start;
    int* shortestDistance = new int[n];
    bool* visited = new bool[n];
    int* path = new int[n];
    vector<pii>* graph = new vector<pii>[n];
    for (int i = 0; i < n; i++) {
        shortestDistance[i] = INF;
        visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
    }
    // begin
    shortestDistance[start] = 0;
    path[start] = start;
    for (int i = 0; i < n; i++) {
        int thisMinDistance = INF;
        int thisShortestPoint = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && shortestDistance[j] < thisMinDistance) {
                thisMinDistance = shortestDistance[j];
                thisShortestPoint = j;
            }
        }
        if (thisShortestPoint == -1) {
            break;
        }
        visited[thisShortestPoint] = true;
        for (auto& [toPoint, thisDistance] : graph[thisShortestPoint]) {
            if (shortestDistance[thisShortestPoint] + thisDistance < shortestDistance[toPoint]) {
                shortestDistance[toPoint] = shortestDistance[thisShortestPoint] + thisDistance;
                path[toPoint] = thisShortestPoint;
            }
        }
    }
    // output
    for (int i = 0; i < n; i++) {
        if (shortestDistance[i] == INF) {
            printf("Point %d is unreachable.", i);
        }
        else {
            stack<int> thisPath;
            thisPath.push(i);
            while (thisPath.top() != start) {
                thisPath.push(path[thisPath.top()]);
            }
            printf("Point %d's min distance is %d, and the path is: ", i, shortestDistance[i]);
            bool first = true;
            while (thisPath.size()) {
                if (first)
                    first = false;
                else {
                    printf(" -> ");
                }
                printf("%d", thisPath.top());
                thisPath.pop();
            }
            puts("");
        }
    }
    // after
    delete[] path;
    delete[] shortestDistance;
    delete[] visited;
    delete[] graph;
    return 0;
}