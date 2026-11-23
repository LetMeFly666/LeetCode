/*
 * @Author: LetMeFly
 * @Date: 2026-11-23 18:17:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-23 18:33:51
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class ProductOfNumbers {
private:
    int lastZero = 100000;
    vector<long long> stream;
public:
    ProductOfNumbers() {
        stream.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            lastZero = 1;
            stream.push_back(stream.back());
        } else {
            lastZero++;
            stream.push_back(stream.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= lastZero) {
            return 0;
        }
        return stream.back() / stream[stream.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

#ifdef _DEBUG
/*
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

[null,null,null,null,null,null,20,40,0,null,32]
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<string> va = stringToVectorStringWithQuots(a);
        vector<vector<int>> vb = stringToVectorVector(b);
        debug(va);
        debug(vb);
        ProductOfNumbers sol;
        for (size_t i = 0, n = va.size(); i < n; i++) {
            if (va[i] == "add") {
                sol.add(vb[i][0]);
            } else if (va[i] == "getProduct") {
                cout << sol.getProduct(vb[i][0]) << endl;
            }
        }
    }
    return 0;
}
#endif
