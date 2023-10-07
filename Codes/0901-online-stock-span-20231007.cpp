/*
 * @Author: LetMeFly
 * @Date: 2023-10-07 09:38:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-07 09:40:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;

class StockSpanner {
private:
    stack<pii> st;  // <price, cnt>
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int ans = 1;
        while (st.size() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */