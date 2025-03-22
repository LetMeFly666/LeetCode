/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 20:15:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 20:38:50
 */

#include <bits/stdc++.h>

using namespace std;


struct Range {
    int start, end;

    Range(int a, int b) : start(a), end(b) {};
};

int n, k;
string s;
vector<Range> OkList;
bool a[1000010] = {false};



void print() {
    for (Range& r : OkList) {
        for (int i = r.start; i <= r.end; i += 2) {
            a[i] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        putchar(a[i] ? '1' : '0');
    }
}

vector<Range> genOdd() {
    vector<Range> ans;
    for (Range r : OkList) {
        if (r.start % 2) {
            ans.push_back(r);
        }
    }
    return ans;
}

vector<Range> genEven() {
    vector<Range> ans;
    for (Range r : OkList) {
        if (r.start % 2 == 0) {
            ans.push_back(r);
        }
    }
    return ans;
}

vector<Range> mergeOddOrEven(vector<Range>& odd) {  // 全是奇数或全是偶数
    if (odd.empty()) {
        return {};
    }
    vector<Range> ans;
    int l = odd[0].start, r = odd[0].end;
    for (int i = 1; i <= odd.size(); i++) {
        if (i == odd.size() || odd[i].start > r + 2) {
            ans.push_back(Range(l, r));
            l = odd[i].start, r = odd[i].end;
        } else {
            r = max(r, odd[i].end);
        }
    }
    return ans;
}


void mergeList() {
    vector<Range> odd = genOdd();
    vector<Range> even = genEven();
    OkList = mergeOddOrEven(odd);
    for (Range r : mergeOddOrEven(even)) {
        OkList.push_back(r);
    }
}

void left(vector<Range>& leftOk) {
    for (Range r : OkList) {
        int left = r.start;
        int right = r.end;
        left--;
        right--;
        if (left == 0) {
            leftOk.push_back(Range(1, 1));
            left = 2;
        }
        if (left <= right)  {
            leftOk.push_back(Range(left, right));
        }
    }
}

void right(vector<Range>& leftOk) {
    for (Range& r : OkList) {
        int left = r.start;
        int right = r.end;
        left++;
        right++;
        if (right == n + 1) {
            leftOk.push_back(Range(n, n));
            right = n - 1;
        }
        if (left <= right)  {
            leftOk.push_back(Range(left, right));
        }
    }
}

/*
3 2
RL?

010
*/

/*
5 2
?????

11111
*/

int main() {
    cin >> n >> k;
    cin >> s;
    OkList.push_back(Range(k, k));
    
    for (char c : s) {
        vector<Range> nextOk;
        if (c == 'L' || c == '?') {
            left(nextOk);
        }
        if (c == 'R' || c == '?') {
            right(nextOk);
        }
        OkList = move(nextOk);
        mergeList();
    }

    print();
    return 0;
}