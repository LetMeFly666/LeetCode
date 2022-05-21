/*
 * @Author: LetMeFly
 * @Date: 2022-01-23 09:04:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-23 09:09:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class StockPrice {
private:
    map<int, int> ma;
    multiset<int> se;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if (ma[timestamp]) {
            se.erase(se.find(ma[timestamp]));
            
        }
        ma[timestamp] = price;
        se.insert(price);
    }
    
    int current() {
        return ma.rbegin()->second;
    }
    
    int maximum() {
        return *se.rbegin();
    }
    
    int minimum() {
        return *se.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */