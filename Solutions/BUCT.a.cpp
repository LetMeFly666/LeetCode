/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-28 22:00:38
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef pair<int, int> pii;

int [SIZE];
bool visited[SIZE];
vector<int> graph[SIZE];

int main() {
    int n, m;
    cin >> n >> m;
    // init
    int* shortestDistance = new int[n];
    bool* visited = new bool[n];
    vector<int>* graph = new vector<int>[n];
    for (int i = 0; i < n; i++) {
        // TODO:
    }
    delete[] shortestDistance;
    delete[] visited;
    delete[] graph;
    return 0;
}