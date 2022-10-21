/*
 * @Author: LetMeFly
 * @Date: 2022-10-21 18:19:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-21 20:09:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
[100, 80, 60, 70, 60, 75, 85]

[ (100, 1)
[ (100, 1), (80, 1)
[ (100, 1), (80, 1), (60, 1)
[ (100, 1), (80, 1), (70, 2)
[ (100, 1), (80, 1), (70, 2), (60, 1)
[ (100, 1), (80, 1), (75, 4)
[ (100, 1), (85, 6)


*/

typedef pair<int, int> pii;  // <price, 连续>
class StockSpanner {
private:
    stack<pii> st;
public:
    StockSpanner() {
        st.push({INT_MAX, 666});
    }
    
    int next(int price) {
        int cnt = 1;
        while (price >= st.top().first) {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */