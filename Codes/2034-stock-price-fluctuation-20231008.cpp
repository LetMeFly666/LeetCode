#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class StockPrice {
private:
    unordered_map<int, int> ma;
    multiset<int> se;
    int Mtime;
public:
    StockPrice() {
        Mtime = 0;
    }
    
    void update(int timestamp, int price) {
        if (ma.count(timestamp)) {
            se.erase(ma[timestamp]);
        }
        ma[timestamp] = price;
        se.insert(price);
        Mtime = max(Mtime, timestamp);
    }
    
    int current() {
        return ma[Mtime];
    }
    
    int maximum() {
        return ma[*se.end()];
    }
    
    int minimum() {
        return ma[*se.begin()];
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