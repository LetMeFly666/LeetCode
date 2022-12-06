/*
 * @Author: LetMeFly
 * @Date: 2022-12-06 10:46:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-06 11:46:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Half
class Solution {
public:
    int numDifferentIntegers(string& word) {
        unordered_set<string> se;
        string thisString;
        bool lastIsNum = false;
        for (int i = 0; i <= word.size(); i++) {
            if (i == word.size() || isalpha(word[i])) {
                if (lastIsNum) {
                    if (thisString.empty()) {
                        se.insert("0");
                    }
                    else {
                        se.insert(thisString);
                    }
                }
                lastIsNum = false;
                thisString.clear();
            }
            else {
                thisString += word[i];
                lastIsNum = true;
            }
        }
    }
};
#else  // FirstTry
class Solution {
private:
    unordered_set<string> se;

    void insert(string toInsert) {
        int firstLoc = -1;
        for (int i = 0; i < toInsert.size(); i++) {
            if (toInsert[i] != '0') {
                firstLoc = i;
                break;
            }
        }
        if (firstLoc == -1)
            se.insert("0");
        else
            se.insert(toInsert.substr(firstLoc));
    }
public:
    int numDifferentIntegers(string word) {
        bool lastIsNum = false;
        string thisString;
        int n = word.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || isalpha(word[i])) {
                if (lastIsNum) {
                    lastIsNum = false;
                    insert(thisString);
                    thisString.clear();
                }
            }
            else {
                thisString += word[i];
                lastIsNum = true;
            }
        }
        // for (auto s : se) {
        //     cout << s << endl;
        // }
        return se.size();
    }
};
#endif  // FirstTry