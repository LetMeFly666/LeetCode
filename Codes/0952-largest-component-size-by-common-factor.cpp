/*
 * @Author: LetMeFly
 * @Date: 2022-07-30 09:54:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-30 10:57:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一：建图
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        // 分解因数到hasThisFactor中
        vector<vector<int>> hasThisFactor(100010);
        vector<vector<int>> num4Factor(100010);
        for (int t : nums) {
            int k = sqrt(t);
            for (int i = 2; i <= k; i++) {
                if (t % i == 0) {
                    hasThisFactor[i].push_back(t);
                    num4Factor[t].push_back(i);
                    if (t / i != i) {
                        hasThisFactor[t / i].push_back(t);
                        num4Factor[t].push_back(t / i);
                    }
                }
            }
            // 自己是自己的因数
            hasThisFactor[t].push_back(t);
            num4Factor[t].push_back(t);
        }
        int ans = 0;
        vector<bool> visitedFactor(100010, false);
        vector<bool> visitedNum(100010, false);
        for (int i = 2; i <= 100000; i++) {
            if (hasThisFactor[i].size() && !visitedFactor[i]) {
                visitedFactor[i] = true;
                int thisAns = 0;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int thisFactor = q.front();
                    q.pop();
                    for (int thisNum : hasThisFactor[thisFactor]) {
                        if (!visitedNum[thisNum]) {
                            visitedNum[thisNum] = true;
                            thisAns++;
                            for (int thisNewFactor : num4Factor[thisNum]) {
                                if (!visitedFactor[thisNewFactor]) {
                                    visitedFactor[thisNewFactor] = true;
                                    q.push(thisNewFactor);
                                }
                            }
                        }
                    }
                }
                ans = max(ans, thisAns);
            }
        }
        return ans;
    }
};
#else  // FirstTry
class UnionFind {
private:
    int* father;
    int* rank;
public:
    UnionFind(int n) {
        father = new int[n];
        rank = new int[n];
        memset(rank, 0, sizeof(rank));
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    
    ~UnionFind() {
        delete[] father;
        delete[] rank;
    }

    int find(int x) {
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                father[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                father[rootX] = rootY;
            }
            else {
                father[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        // 并查集构建
        UnionFind unionFind(nums.size() + 1);
        for (int t : nums) {
            int k = sqrt(t);
            for (int i = 2; i <= k; i++) {
                if (t % i == 0) {
                    unionFind.Union(i, t);
                    unionFind.Union(i, t / i);
                }
            }
        }
        // 统计有几个集合、每个集合中有多少个元素
        unordered_map<int, int> times;
        for (int t : nums) {
            times[unionFind.find(t)]++;
        }
        // 统计最大值
        int ans = 0;
        for (auto[root, appendTime] : times) {
            ans = max(ans, appendTime);
        }
        return ans;
    }
};
#endif  // FirstTry

// [4,6,15,35]
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.largestComponentSize(v) << endl;
    }
    return 0;
}
#endif