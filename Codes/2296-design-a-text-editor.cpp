/*
 * @Author: LetMeFly
 * @Date: 2025-02-27 09:48:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-27 10:04:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class TextEditor {
private:
    stack<char> left, right;

    string leftMax10() {
        string ans;
        for (int op = min(10, (int)left.size()); op > 0; op--) {
            ans += left.top();
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        for (char c : ans) {
            left.push(c);
        }
        return ans;
    }
public:
    TextEditor() {}
    
    void addText(string text) {
        for (char c : text) {
            left.push(c);
        }
    }
    
    int deleteText(int k) {  // 假设k≥0
        int ans = 0;
        while (k-- && left.size()) {
            left.pop();
            ans++;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        while (k-- && left.size()) {
            right.push(left.top());
            left.pop();
        }
        return leftMax10();
    }
    
    string cursorRight(int k) {
        while (k-- && right.size()) {
            left.push(right.top());
            right.pop();
        }
        return leftMax10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */