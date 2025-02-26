/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:41:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:45:07
 */
import java.util.List;
import java.util.ArrayList;

class BrowserHistory {
    private List<String> history;
    private int now, right;

    public BrowserHistory(String homepage) {
        history = new ArrayList<>();
        now = right = 0;
        history.add(homepage);
    }
    
    public void visit(String url) {
        if (++now == history.size()) {
            history.add(url);
        } else {
            history.set(now, url);
        }
        right = now;
    }
    
    public String back(int steps) {
        now = Math.max(0, now - steps);
        return history.get(now);
    }
    
    public String forward(int steps) {
        now = Math.min(right, now + steps);
        return history.get(now);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */