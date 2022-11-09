/*
 * @Author: LetMeFly
 * @Date: 2022-10-06 21:34:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-06 22:35:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Half
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt1 = 0;
        for (int& t : arr){
            cnt1 += t;
        }
        if (cnt1 % 3)
            return {-1, -1};
        if (!cnt1) {  // 全是0
            return {0, 1};
        }
        int per = cnt1 / 3;
        int endZero;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i]) {
                endZero = i;
                break;
            }
        }
        int firstNumEnd;
        int nowCnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            nowCnt += arr[i];
            if (nowCnt == per) {
                int nowCntZero = 0;
                while (++i < arr.size()) {
                    if (arr[i])
                        return {-1, -1};
                    if (nowCntZero == endZero) {
                        firstNumEnd = i;
                        break;
                    }
                }
                break;
            }
        }
        int firstNumFirst1Loc = 0;
        while (!arr[firstNumFirst1Loc])
            firstNumFirst1Loc++;
        int secondNumFirst1Loc = 0;

    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    /*
        寻找以begin开始，拥有numof1个1，结尾有end0个0  的二进制串的最后一位的下标
        若找不到，则返回-1
    */
    int findTheEndOfOneNum(int begin, int numof1, int end0, vector<int>& arr) {
        int cnt1 = 0;
        for (; begin < arr.size(); begin++) {
            if (arr[begin])
                cnt1++;
            if (cnt1 == numof1)
                break;
        }
        // 一定能找到足够数量的1，因为1是计算过后平分的
        if (!end0)
            return begin;
        int cnt0 = 0;
        while (++begin < arr.size()) {
            if (arr[begin]) {
                return -1;
            }
            cnt0++;
            if (cnt0 == end0)
                return begin;
        }
        return -1;  // FakeReturn
    }

    /* 判断1总量相同、后缀0相同 的前提下， 两串数字是否等价 */
    bool same(int firstNumBegin, int firstNumEnd, int secondNumBegin, int secondNumEnd, vector<int>& arr) {
        function<int(int)> findFirst1 = [&](int beginLoc) {
            while (!arr[beginLoc])
                beginLoc++;
            return beginLoc;
        };
        int firstNumFirst1 = findFirst1(firstNumBegin);
        int secondNumFirst1 = findFirst1(secondNumBegin);
        if (secondNumEnd - secondNumFirst1 != firstNumEnd - firstNumFirst1) {
            return false;
        }
        while (firstNumFirst1 <= firstNumEnd) {
            if (arr[firstNumFirst1] != arr[secondNumFirst1])
                return false;
            firstNumFirst1++;
            secondNumFirst1++;
        }
        return true;
    }
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt1 = 0;
        for (int& t : arr) {
            cnt1 += t;
        }
        if (cnt1 % 3)
            return {-1, -1};
        if (!cnt1)  // 全0
            return {0, 2};
        int per1 = cnt1 / 3;  // 每个二进制下有多少个1
        int end0 = 0;  // 每个二进制下最后有几个0取决于第三个数
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i])
                break;
            else
                end0++;
        }
        int firstNumEnd = findTheEndOfOneNum(0, per1, end0, arr);
        if (firstNumEnd == -1)
            return {-1, -1};
        int secondNumEnd = findTheEndOfOneNum(firstNumEnd + 1, per1, end0, arr);
        if (secondNumEnd == -1)
            return {-1, -1};
        if (same(0, firstNumEnd, firstNumEnd + 1, secondNumEnd, arr) && same(0, firstNumEnd, secondNumEnd + 1, arr.size() - 1, arr))
            return {firstNumEnd, secondNumEnd + 1};
        else
            return {-1, -1};
    }
};
#endif  // FirstTry

/*
    [1,0,1,0,1]
*/
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> a = stringToVector(s);
        debug(sol.threeEqualParts(a));
    }
    return 0;
}
#endif