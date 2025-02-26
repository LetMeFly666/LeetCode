/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:16:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:37:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class BrowserHistory {
private:
    vector<string> history;
    int now, right;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        now = right = 0;
    }
    
    void visit(string url) {
        if (++now == history.size()) {
            history.push_back(url);

        } else {
            history[now] = url;
        }
        right = now;
    }
    
    string back(int steps) {
        now = max(0, now - steps);
        return history[now];
    }
    
    string forward(int steps) {
        now = min(right, now + steps);
        return history[now];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */