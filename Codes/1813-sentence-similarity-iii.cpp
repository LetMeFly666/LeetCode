/*
 * @Author: LetMeFly
 * @Date: 2023-01-16 22:39:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-16 23:03:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<string> sentence2words(string& s) {
        vector<string> ans;
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                ans.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        return ans;
    }
public:
    bool areSentencesSimilar(string& sentence1, string& sentence2) {
        vector<string> words1 = sentence2words(sentence1), words2 = sentence2words(sentence2);
        int front1 = -1, front2 = -1, back1 = words1.size(), back2 = words2.size();
        while (front1 + 1 < words1.size() && front2 + 1 < words2.size() && words1[front1 + 1] == words2[front2 + 1]) {
            front1++, front2++;
        }
        while (back1 - 1 > front1 && back2 - 1 > front2 && words1[back1 - 1] == words2[back2 - 1]) {
            back1--, back2--;
        }
        return front1 + 1  == back1|| front2 + 1 == back2;
    }
};

#ifdef _WIN32
/*
My name is Haley
My Haley

*/
int main() {
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        Solution sol;
        cout << sol.areSentencesSimilar(s1, s2) << endl;
    }
    return 0;
}
#endif