/*
 * @Author: LetMeFly
 * @Date: 2024-04-06 12:29:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-06 12:39:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class TreeAncestor {
private:
    const static int Log = 16;  // 2 ^ 16 = 65536
    vector<vector<int>> ancestors;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>>(n, vector<int>(Log, -1));
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {  // don't forget
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < Log && node != -1; j++) {
            if ((k >> j) & 1) {
                node = ancestors[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */