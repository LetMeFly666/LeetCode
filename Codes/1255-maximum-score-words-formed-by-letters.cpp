/*
 * @Author: LetMeFly
 * @Date: 2023-02-26 20:40:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-26 20:46:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        vector<int> letter(26);
        for (char l : letters){
            letter[l - 'a']++;
        }

        int n = words.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> letterLefted = letter;
            int thisScore = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (char thisChar : words[i]) {
                        thisScore += score[thisChar - 'a'];
                        if (!letterLefted[thisChar - 'a']) {
                            goto loop;
                        }
                        letterLefted[thisChar - 'a']--;
                    }
                }
            }
            ans = max(ans, thisScore);
            loop:;
        }
        return ans;
    }
};