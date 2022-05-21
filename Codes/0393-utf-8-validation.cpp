/*
 * @Author: LetMeFly
 * @Date: 2022-03-13 10:44:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-13 11:00:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int getQian1(int n) {  // 返回第1个0前有几个1
    // 0 | 10 | 110 | 1110 | 11110
    if (n == 255)
        return 8;
    string ans;
    int num1 = 0;
    while (n & (1 << (7 - num1))) 
        num1++;
    return num1;
}

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; i++) {
            int num1 = getQian1(data[i]);
            if (num1 == 1 || num1 > 4)
                return false;
            if (i + num1 - 1 >= n)
                return false;
            for (int j = 0; j < num1 - 1; j++) {
                i++;
                if (getQian1(data[i]) != 1)
                    return false;
            }
        }
        return true;
    }
};

#ifdef _WIN32
void testForGetQian1() {
    puts("Testing for getQian1");
    int n;
    while (cin >> n) {
        cout << getQian1(n) << endl;
    }
}

int main() {
    testForGetQian1();
    return 0;
}
#endif