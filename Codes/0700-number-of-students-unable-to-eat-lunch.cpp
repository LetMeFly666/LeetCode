/*
 * @Author: LetMeFly
 * @Date: 2022-10-19 09:09:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-19 10:23:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#define SecondTry

#ifdef FirstTry  // 真模拟
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // 构建队列与栈
        queue<int> q;
        for (int& t : students) {
            q.push(t);
        }
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        // 开始模拟
        while (true) {
            int thisSandwich = st.top();
            st.pop();
            bool found = false;
            for (int i = q.size(); i > 0; i--) {
                int thisStudent = q.front();
                q.pop();
                if (thisStudent == thisSandwich) {
                    found = true;
                    break;
                }
                else {
                    q.push(thisStudent);
                }
            }
            if (!found) {
                return q.size();
            }
            else if (q.empty()) {
                return 0;
            }
        }
        return -1;  // Fake Return
    }
};
#else  // FirstTry
#ifdef SecondTry  // 假模拟
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s[2] = {(int)count(students.begin(), students.end(), 0), (int)students.size() - s[0]};
        // cout << s[0] << ' ' << s[1] << endl;
        for (int& t : sandwiches) {
            if (s[t])
                s[t]--;
            else
                return s[0] + s[1];
        }
        return 0;
    }
};
#else  // SecondTry
// ThirdTry  // 奇技淫巧，计时器
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int& t : students) {
            q.push(t);
        }
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        time_t start = clock();
        while (clock() - start < 1000 && q.size()) {
            if (q.front() == st.top())
                q.pop(), st.pop();
            else {
                int thisStudent = q.front();
                q.pop();
                q.push(thisStudent);
            }
        }
        return q.size();
    }
};
#endif  // SecondTry
#endif  // FirstTry