/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 19:10:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 19:31:14
 */
/*

   1
 2   3
0 1

   2
 3   1
0 2



root 1->2
times: 1
2->3: 1
need: 1
1 -> 2: 1
need: 1
3->1: 
need: 3
times: 2
sum: 1+2=3
*/


/*

    1
  2   3
1 2  3 1


    3
  1   2
3 1  2 1

1->3: 2
times: 2
2->1: 4
times: 2
3->2: 4
times: 2
1->3: (5->3) 3
times: 3
2->1: (1->1) 0
3->2: (2->2) 0
1->1: (5->1) 1
times 1
sum: 2 + 2 + 2 + 3 + 1 = 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int original, to;
    Node *left, *right;
    int already;  // 由于father导致的已变更次数
};

// 变化范围是1，2，3，4，5
inline int change(int original, int times) {
    return (original + times - 1 + 5) % 5 + 1;
}

inline int calc(int from, int to) {
    return (to - from + 5) % 5;
}

/*
5
1 2 3 0 1
2 3 1 0 2

*/

int main() {
    int n;
    cin >> n;
    queue<Node*> q;
    Node* head = new Node();
    q.push(head);
    for (int i = 0; i < n; i++) {
        Node* thisNode = q.front();
        q.pop();
        cin >> thisNode->original;
        thisNode->left = new Node();
        thisNode->right = new Node();
        q.push(thisNode->left);
        q.push(thisNode->right);
    }
    q = queue<Node*>();
    q.push(head);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        Node* thisNode = q.front();
        q.pop();
        cin >> thisNode->to;
        q.push(thisNode->left);
        q.push(thisNode->right);
        if (thisNode->original == 0) {
            continue;
        }
        int from = change(thisNode->original, thisNode->already);
        int need = calc(from, thisNode->to);
        ans += need;
        thisNode->left->already = (thisNode->already + need) % 5;
        thisNode->right->already = (thisNode->already + need) % 5;
    }
    cout << ans << endl;
    return 0;
}