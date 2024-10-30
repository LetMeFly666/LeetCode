/*
 * @Author: LetMeFly
 * @Date: 2024-10-28 21:55:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-30 10:01:21
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 构造
    bitset<4> b1;  // 0000
    cout << b1 << endl;
    bitset<4> b2 = 3;  // 0011
    cout << b2 << endl;
    // 不可以：bitset<4> b3 = string("101");
    bitset<4> b3(string("101"));  // 0101
    cout << b3 << endl;
    bitset<4> b4("11");  // 0011
    cout << b4 << endl;

    // 访问
    cout << b1[0] << endl;
    std::bitset<4U>::reference c = b1[0];
    cout << c << endl;
    int d = c;
    cout << d << endl;
    bool e = c;
    cout << e << endl;
    bool f = b2.test(0);  // 低1位:1
    cout << f << endl << endl;
    cout << b1.none() << endl;
    cout << b2.count() << endl;  // 统计多少个1
    cout << b3.all() << endl;
    cout << b4.any() << endl;

    // 操作
    b1.set(1);  // 低2位置1:0000->0010
    cout << b1 << endl;
    b2.reset(0);  // 最低位置0:0011->0010
    cout << b2 << endl;
    b3.flip();  // 翻转每一位:0101->1010
    cout << b3 << endl << endl;

    // 类型转换
    unsigned long ul = b1.to_ulong();
    string s = b2.to_string();

    // 位运算
    cout << (b1 & b2) << endl;
    cout << (b1 | b2) << endl;
    cout << (~b1) << endl;  // 每一位翻转
    cout << (b1 ^ b2) << endl;
    cout << (b1 << 1) << endl;  // 右侧补0左侧丢弃
    cout << (b1 >> 1) << endl;  // 左侧补0右侧丢弃
    b1 &= b2;
    b1 |= b2;
    b1 ^= b2;
    b1 <<= 1;
    b1 >>= 1;
    cout << b1 << endl;
    cout << (b1 == b2) << endl;
    return 0;
}