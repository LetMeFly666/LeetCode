/*
 * @Author: LetMeFly
 * @Date: 2026-08-01 18:34:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-01 18:54:52
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int play(deque<int>& q) {
        if (q.empty()) {
            return 0;
        }

        int first = q.front();
        q.pop_front();
        int score1 = first - play(q);
        q.push_front(first);

        int last = q.back();
        q.pop_back();
        int score2 = last - play(q);
        q.push_back(last);

        return max(score1, score2);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        deque<int> q;
        for (int t : nums) {
            q.push_back(t);
        }
        return play(q) >= 0;
    }
};

#ifdef _DEBUG
/*
[1,567,1,1,99,100]

true
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.predictTheWinner(v) << endl;
    }
    return 0;
}
#endif
