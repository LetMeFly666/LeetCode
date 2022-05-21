/*
 * @Author: LetMeFly
 * @Date: 2022-04-10 08:37:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-10 08:40:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const string passwords[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> se;
        for (string& word : words) {
            string thisPassword;
            for (char& c : word) {
                thisPassword += passwords[c - 'a'];
            }
            se.insert(thisPassword);
        }
        return se.size();
    }
};