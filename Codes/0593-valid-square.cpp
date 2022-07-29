/*
 * @Author: LetMeFly
 * @Date: 2022-07-29 10:54:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-29 11:37:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

ostream& operator<< (ostream& out, vector<int>& v) {
    out << '[';
    for (int i = 0; i < v.size(); i++) {
        if (i)
            out << ", ";
        out << v[i];
    }
    out << ']';
    return out;
}

#ifdef FirstTry  // 枚举对角  // Wa，因为正方形的边不一定与坐标轴平行
class Solution {
private:
    vector<int> points[4];

    bool okDuiJiao(int a, int b) {
        vector<int> other2;
        for (int i = 0; i < 4; i++) {
            if (i != a && i != b) {
                other2.push_back(i);
            }
        }
        if (points[a][0] == points[b][0] || points[a][1] == points[b][1]) {
            return false;
        }
        vector<int> anotherA = {points[a][0], points[b][1]};
        vector<int> anotherB = {points[a][1], points[b][0]};
        if (anotherA == points[other2[0]] && anotherB == points[other2[1]]) {
            return true;
        }
        if (anotherA == points[other2[1]] && anotherB == points[other2[0]]) {
            return true;
        }
        return false;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
        points[3] = p4;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (okDuiJiao(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
#else  // FirstTry
class Solution {
private:
    /* 计算两个点之间的距离 */
    inline int distance2(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }

    bool ifOkThisOrder(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = distance2(p1, p2);
        int d23 = distance2(p2, p3);
        int d34 = distance2(p3, p4);
        int d41 = distance2(p4, p1);
        // 四条边等长
        if (d12 != d23 || d23 != d34 || d34 != d41)
            return false;
        // 有直角
        return d12 + d23 == distance2(p1, p3);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v[4] = {p1, p2, p3, p4};
        // 点不重合
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (v[i] == v[j])
                    return false;
            }
        }
        vector<int> order = {0, 1, 2, 3};
        do {
            if (ifOkThisOrder(v[order[0]], v[order[1]], v[order[2]], v[order[3]])) {
                cout << "Ok: [" << v[order[0]] << ", " << v[order[1]] << ", " << v[order[2]] << ", " << v[order[3]] << endl;
                return true;
            }
        } while (next_permutation(order.begin(), order.end()));
        return false;
    }
};
#endif  // FirstTry

/*
[0,1]
[1,1]
[1,1]
[1,0]

*/

#ifdef _WIN32
int main() {
    string s[4];
    while (cin >> s[0] >> s[1] >> s[2] >> s[3]) {
        vector<int> v[4];
        for (int i = 0; i < 4; i++) {
            v[i] = stringToVector(s[i]);
        }
        Solution sol;
        cout << sol.validSquare(v[0], v[1], v[2], v[3]) << endl;
    }
    return 0;
}
#endif