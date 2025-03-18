/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 22:13:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 22:13:13
 */
/*
谢谢面试官！面试官再见

输入：  k n  然后n个数

例如：
3 8
1 2 3 4 5 6 7 8
代表k=3，一共8个数

实现过程：
统计自上次翻转开始，未翻转链表的长度。
若长度为k或者到达链表的最后一个节点，就进行翻转

翻转过程中记录翻转前的节点From、翻转部分的下一个节点To
例如From->1->2->3->to 代表翻转1到3
遍历的同时更改1到3每个节点的next，最后更新From的next为3，更新1节点的next为to
最终就变成了From->3->2->1->to

时间复杂度：O(n)
空间复杂度：O(1)

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
    // Node* second = from->next;
    // Node* p = from->next;
    // Node* last = from;
    // while (p != to) {
    //     Node* now = p;
    //     Node* next = p->next;
    //     p->next = last;
    //     p = next;
    //     last = now;
    // }
    Node* v0 = from->next;
    Node* p = from->next;
    Node* last = from;
    while (p != to) {
        Node* next = p->next;
        p->next = last;
        last = p;
        p = next;
    }
    from->next = last;
    v0->next = to;
}

// void realRev0(Node* from, Node* to) {
//     vector<Node*> v;
//     Node* p = from->next;
//     while (p != to) {
//         v.push_back(p);
//         p = p->next;
//     }
//     from->next = v.back();
//     p = v.back();
//     for (int i = v.size() - 1; i > 0; i--) {
//         v[i]->next = v[i - 1];
//     }
//     v[0]->next = to;
// }


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
            realRev(from, to);
            // p = 
            from = originalFirst;
            cnt = 0;
            // debug(head);
            p = to;
            // printf("from = %d, p = %d\n", from->val, p->val);

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
            Node* last = p;
            if (!p->next) {
                realRev(from, nullptr);
                break;
            }
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