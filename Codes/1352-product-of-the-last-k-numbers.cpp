/*
 * @Author: LetMeFly
 * @Date: 2026-11-23 18:17:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-23 18:23:55
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class ProductOfNumbers {
private:
    int lastZero = -100000;
    vector<long long> stream;
public:
    ProductOfNumbers() {
        stream.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            lastZero = 1;
            stream.push_back(stream.back());
        } else {
            lastZero++;
            stream.push_back(stream.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k <= lastZero) {
            return 0;
        }
        return stream.back() / stream[stream.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
