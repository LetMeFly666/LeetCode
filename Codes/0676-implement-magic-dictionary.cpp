/*
 * @Author: LetMeFly
 * @Date: 2022-07-11 11:18:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-11 11:25:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class MagicDictionary {
private:
    unordered_set<string> se;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (string& s : dictionary) {
            se.insert(s);
        }
    }
    
    bool search(string searchWord) {
        bool found = false;
        for (char& c : searchWord) {
            char originalC = c;
            for (int i = 0; i < 26; i++) {
                c = 'a' + i;
                if (c == originalC)
                    continue;
                if (se.count(searchWord)) {
                    found = true;
                }
            }
            c = originalC;
        }
        return found;
    }
};
#else  // FirstTry
// SecondTry  // 小小优化
class MagicDictionary {
private:
    unordered_set<string> se;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (string& s : dictionary) {
            se.insert(s);
        }
    }
    
    bool search(string searchWord) {
        for (char& c : searchWord) {
            char originalC = c;
            for (int i = 0; i < 26; i++) {
                c = 'a' + i;
                if (c == originalC)
                    continue;
                if (se.count(searchWord))
                    return true;
            }
            c = originalC;
        }
        return false;
    }
};
#endif  // FirstTry

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */