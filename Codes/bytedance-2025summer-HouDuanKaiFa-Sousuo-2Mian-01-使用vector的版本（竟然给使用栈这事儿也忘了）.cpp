/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 21:07:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 21:42:51
 */
/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 21:00:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 21:05:19
 */
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val, Node* next): val(val), next(next) {};
};

void debug(Node* head) {
    head = head->next;

    while (head) {
        cout << head->val << ',';
        head = head->next;
    }
    puts("");
}

void debug(Node* from, Node* to) {
    printf("debug(Node* from, Node* to)\n");
    while (from != to) {
        cout << from->val << ',';
        from = from->next;
    }
    if (to) {
        cout << to->val << endl;
    }
}

void realRev(Node* from, Node* to) {
    Node* second = from->next;
    Node* p = from->next;
    Node* last = from;
    while (p != to) {
        Node* now = p;
        Node* next = p->next;
        p->next = last;
        p = next;
        last = now;
    }
}

void realRev0(Node* from, Node* to) {
    vector<Node*> v;
    Node* p = from->next;
    while (p != to) {
        v.push_back(p);
        p = p->next;
    }
    from->next = v.back();
    p = v.back();
    for (int i = v.size() - 1; i > 0; i--) {
        v[i]->next = v[i - 1];
    }
    v[0]->next = to;
}


void rev(Node* head, int k) {
    Node* p = head->next;
    Node* from = head;
    int cnt = 0;
    while (p) {
        cnt++;
        if (cnt == k) {
            // rev from->to
            Node* to = p->next;
            Node* originalFirst = from->next;
            realRev0(from, to);
            // p = 
            from = originalFirst;
            cnt = 0;
            debug(head);
            p = to;
            printf("from = %d, p = %d\n", from->val, p->val);

            // Node* originalP = p;
            // Node* second = from->next;
            // debug(from, to);

            // Node* last = from;
            // Node* now = p;
            // while (now != to) {
            //     Node* next = p->next;
            //     p->next = last;
            //     p = next;
            //     last = now;
            //     now = next;
            // }
            // from->next = originalP;
            // p = second;
            // second->next = to;



            // // rev from->..->p
            // Node* to = p->next;
            // Node* last = from;
            // Node* now = p;
            // while (now != p) {
            //     Node* next = now->next;
            //     now->next = last;
            //     last = now;
            //     now = next;
            // }
            // p->next = now;
            // from->next = to;
            // from = p;
            // cnt = 0;
            // debug(head);
        } else {
            p = p->next;
        }
        
    }
}



/*
3 8
1 2 3 4 5 6 7 8

*/
int main() {
    int k, n, t;
    cin >> k >> n;
    Node* head = new Node(0, nullptr);
    Node* p = head;
    for (int i = 0; i < n; i++) {
        cin >> t;
        Node* thisNode = new Node(t, nullptr);
        p->next = thisNode;
        p = p->next;
    }
    rev(head, k);
    debug(head);
    return 0;
}