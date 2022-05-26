/*
 * @Author: LetMeFly
 * @Date: 2022-05-26 08:41:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-26 13:23:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct Line {  // [l, r]的高度为height
    int l, r;
    int height;
    Line() {}
    Line(int l, int r, int h) : l(l), r(r), height(h) {}
};

#ifdef FirstTry  // n^2
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Line> lines;
        vector<int> ans;
        int Max = 0;
        for (auto& thisSquare : positions) {
            int l = thisSquare[0], r = thisSquare[0] + thisSquare[1] - 1;
            int thisAns = thisSquare[1];
            for (Line& thisLine : lines) {
                if (!(thisLine.r < l || thisLine.l > r)) {
                    thisAns = max(thisAns, thisLine.height + thisSquare[1]);
                }
            }
            lines.push_back(Line(l, r, thisAns));
            Max = max(Max, thisAns);
            ans.push_back(Max);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry：n log n
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<int, int> heightMap;
        heightMap[0] = 0;  // 初始时所有点的高度都是0
        vector<int> ans;
        int Max = 0;
        for (auto& thisSquare : positions) {
            int l = thisSquare[0], r = thisSquare[0] + thisSquare[1] - 1;
            int thisMaxHeight = thisSquare[1];
            map<int, int>::iterator lp = heightMap.upper_bound(l), rp = heightMap.upper_bound(r);
            printf("lp.first = %d, rp.first = %d\n", lp->first, rp->first);  //******
            int rHeight = prev(rp)->second; // 记录 right + 1 对应的堆叠高度（如果 right + 1 不在 heightMap 中）
            // 获取这个方块的最大高度
            for (map<int, int>::iterator it = prev(lp); it != rp; it++) {
                thisMaxHeight = max(thisMaxHeight, it->second + thisSquare[1]);
            }
            // 清除(l, R]中原本的值
            heightMap.erase(lp, rp);
            
            heightMap[l] = thisMaxHeight; // 更新 l 的变化
            if (rp == heightMap.end() || rp->first != r + 1) { // 如果 r + 1 不在 heightMap 中，更新 r + 1 的变化
                heightMap[r + 1] = rHeight;
            }
            Max = max(Max, thisMaxHeight);
            ans.push_back(Max);
        }
        ans.clear();
        return ans;
    }
};
#endif

#ifdef LeetCode_Solution
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<int, int> heightMap;
        heightMap[0] = 0;  // 初始时所有点的高度都是0
        vector<int> ans;
        int Max = 0;
        for (auto& thisSquare : positions) {
            int l = thisSquare[0], r = thisSquare[0] + thisSquare[1] - 1;
            int thisMaxHeight = thisSquare[1];
            map<int, int>::iterator lp = heightMap.upper_bound(l), rp = heightMap.upper_bound(r);
            int rHeight = prev(rp)->second; // 记录 right + 1 对应的堆叠高度（如果 right + 1 不在 heightMap 中）
            // 获取这个方块的最大高度
            for (map<int, int>::iterator it = prev(lp); it != rp; it++) {
                thisMaxHeight = max(thisMaxHeight, it->second + thisSquare[1]);
            }
            // 清除(l, R]中原本的值
            heightMap.erase(lp, rp);

            heightMap[l] = thisMaxHeight; // 更新 l 的变化
            if (rp == heightMap.end() || rp->first != r + 1) { // 如果 r + 1 不在 heightMap 中，更新 r + 1 的变化
                heightMap[r + 1] = rHeight;
            }
            Max = max(Max, thisMaxHeight);
            ans.push_back(Max);
        }
        return ans;
    }
};
#endif

#ifdef _WIN32
int main() {
    map<int, int> ma;
    ma[0] = 5;
    ma[1] = 8;
    ma[2] = 3;
    map<int, int>::iterator it = ma.find(1);
    dbg(it->first);
    dbg(it->second);
    dbg(prev(it)->first);
    dbg(prev(it)->second);
    system("pause");
    return 0;
}
#endif