/*
 * @Author: LetMeFly
 * @Date: 2022-01-10 07:56:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-10 08:09:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

/*
1023
*/
class Solution {
private:
    bool isOk(int firstLoc, int secondLoc, string& num) {
        if (firstLoc != 0 && num[0] == '0') {
            return false;
        }
        if (secondLoc - firstLoc != 1 && num[firstLoc + 1] == '0') {
            return false;
        }
        ll firstNum = stoll(num.substr(0, firstLoc + 1));
        ll secondNum = stoll(num.substr(firstLoc + 1, secondLoc - firstLoc));
        int loc = secondLoc + 1;
        while (true) {
            ll thirdNum = firstNum + secondNum;
            string thirdString = to_string(thirdNum);
            if (loc + thirdString.size() > num.size()) {
                return false;
            }
            if (num.substr(loc, thirdString.size()) != thirdString) {
                return false;
            }
            loc += thirdString.size();
            if (loc == num.size()) {
                return true;
            }
            firstNum = secondNum;
            secondNum = thirdNum;
        }
    }
public:
    bool isAdditiveNumber(string num) {
        for (int firstLoc = 0; firstLoc < num.size(); firstLoc++) {
            for (int secondLoc = firstLoc + 1; secondLoc < num.size(); secondLoc++) {
                if (isOk(firstLoc, secondLoc, num)) {
                    return true;
                }
            }
        }
        return false;
    }
};