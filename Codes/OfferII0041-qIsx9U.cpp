/*
 * @Author: LetMeFly
 * @Date: 2022-07-16 13:21:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-16 13:47:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const double ONE = 1;

class MovingAverage {
private:
    int size;
    int sum;
    int num;
    int *a;  // Array
    int loc;  // 该移除哪个了
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), sum(0), num(0), a(new int[size]), loc(0) {

    }

    ~MovingAverage() {
        delete[] a;
    }
    
    double next(int val) {
        if (num < size) {  // 刚开始，还没填满窗口
            sum += val;
            a[num++] = val;
            return ONE * sum / num;
        }
        else {
            sum -= a[loc];
            sum += val;
            a[loc++] = val;
            loc %= size;
            return ONE * sum / num;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */