/*
 * @Author: LetMeFly
 * @Date: 2022-10-11 12:17:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-11 13:15:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // unordered_multimap<int, int> ma：无法erase掉键值对
class RandomizedCollection {
private:
    unordered_multimap<int, int> ma;  // <val, indexOfTheVal>
    vector<int> a;
public:
    RandomizedCollection() {

    }
    
    bool insert(int val) {  // 插入并返回插入前是否无此数
        ma.insert({val, a.size()});
        a.push_back(val);
        return ma.count(val) == 1;
    }
    
    bool remove(int val) {
        if (!ma.count(val))
            return false;
        unordered_multimap<int, int>::iterator it = ma.find(val);
        int index = it->second;
        ma.erase(it);
        if (a.size() == 1) {
            a.clear();
        }
        else {
            int index2swap = a.size() - 1;
            ma.erase({a[index2swap, index2swap]});  // Error，没有任何效果
            ma.insert({a[index2swap], index});
            a[index] = a[index2swap];
            a.pop_back();
        }
        return true;
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};
#else  // FirstTry
// SecondTry
class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> ma;  // <val, [locOfThisVal]>
    vector<int> a;
public:
    RandomizedCollection() {

    }
    
    bool insert(int val) {  // 插入并返回插入前是否无此数
        ma[val].insert(a.size());
        a.push_back(val);
        return ma[val].size() == 1;
    }
    
    bool remove(int val) {
        if (!ma.count(val))
            return false;
        unordered_set<int>::iterator it = ma[val].begin();
        int index = *it;
        ma[val].erase(it);
        if (ma[val].empty())
            ma.erase(val);
        if (index < a.size() - 1) {
            int index2swap = a.size() - 1;
            a[index] = a[index2swap];
            ma[a[index2swap]].erase(index2swap);
            ma[a[index2swap]].insert(index);
        }
        a.pop_back();
        return true;
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};
#endif  // FirstTry

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */