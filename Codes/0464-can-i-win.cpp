/*
 * @Author: LetMeFly
 * @Date: 2022-05-22 11:47:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-22 13:30:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // TLE
class Solution {
private:
    bool used[21] = {false};
    int maxChoosableInteger;

    /* 某人走到了这种状态是否会赢 */
    bool willWin(int nowScore, int desiredTotal) {
        if (nowScore >= desiredTotal)
            return true;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (!used[i]) {
                used[i] = true;
                bool ifCanWin = willWin(nowScore + i, desiredTotal);
                used[i] = false;
                if (ifCanWin)
                    return false;
            }
        }
        return true;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0)
            return true;
        this->maxChoosableInteger = maxChoosableInteger;
        return !willWin(0, desiredTotal);
    }
};
#else  // FirstTry
#ifdef SecondTry  // WA
class Solution {
private:
    unordered_set<int> unused;

    /* 某人走到了这种状态是否会赢 */
    bool willWin(int nowScore, int desiredTotal) {
        if (nowScore >= desiredTotal)
            return true;
        
        for (auto t : unused) {
            unordered_set<int> tempSet = unused;
            tempSet.erase(t);
            bool ifCanWin = willWin(nowScore + t, desiredTotal);
            if (ifCanWin)
                return false;
        }
        return true;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0)
            return true;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            unused.insert(i);
        }
        return !willWin(0, desiredTotal);
    }
};
#else  // SecondTry
// Copy
class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }

    bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
        if (!memo.count(usedNumbers)) {
            bool res = false;
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (((usedNumbers >> i) & 1) == 0) {
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
                        res = true;
                        break;
                    }
                }
            }
            memo[usedNumbers] = res;
        }
        return memo[usedNumbers];
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
int main() {
    int a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.canIWin(a, b) << endl;
    }
    return 0;
}
#endif