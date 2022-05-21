/*
 * @Author: LetMeFly
 * @Date: 2022-02-25 09:55:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-25 10:01:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef LeetCode
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};
#else
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int real1, imag1, real2, imag2;
        sscanf(num1.c_str(), "%d+%di", &real1, &imag1);
        sscanf(num2.c_str(), "%d+%di", &real2, &imag2);
        return to_string(real1 *  real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + real2 * imag1) + "i";
    }
};
#endif