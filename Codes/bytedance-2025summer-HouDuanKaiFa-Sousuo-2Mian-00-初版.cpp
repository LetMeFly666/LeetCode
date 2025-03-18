/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 21:00:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 21:05:19
 */
#include <iostream>
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
    while (from != to) {
        cout << from->val << ',';
        from = from->next;
    }
    if (to) {
        cout << to->val << endl;
    }
}

void realRev(Node* last, Node* to) {
    debug(last, to);
    // return;
    int cnt = 0;


    Node* p = last->next;
    // last->next = nullptr;
    while (p != to) {
        cnt++;
        cout << p->val << endl;
        if (cnt > 15) {
            break;
        }
        Node* next = p->next;
        p->next = last;
        last = p;
        p = next;
    }
    to->next = last;
}

void rev(Node* p, int k) {
    Node* last = p;
    int cnt = 0;
    while (p) {
        p = p->next;
        if (p) {
            cnt++;
        }
        if (cnt == k) {
            // reverse
            Node* next = p->next;
            realRev(last, p);
            last->next = next;
            last = p;
            cnt = 0;
            p = next;
        }
    }
}


/*
3 8
1 2 3 4 5 6 7 8

*/
int main() {
    // char str[3];
    // std::cin>>str;
    // std::cout << "hello world" << std::endl;
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