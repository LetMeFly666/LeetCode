#ifndef _2179_H_
#define _2179_H_

#include <vector>  // 确保包含 vector，因为 FenwickTree 使用了它

class FenwickTree {
private:
    std::vector<int> v;  // 必须和 2179.cpp 中的定义完全一致
public:
    FenwickTree(int n);  // 构造函数声明
    void add(int i);     // 方法声明
    int get(int i);      // 方法声明
};

#endif