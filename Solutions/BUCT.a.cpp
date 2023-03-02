/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-02 21:13:26
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct Node {
    char c;
    bool isLeaf;
    Node *leftChild, *rightChild;
    double weight;
};

struct cmp {
    bool operator() (Node* a, Node* b) {
        return a->weight > b->weight;  // 权重小的在前
    }
};

void output(Node* root, string nowString, unordered_map<char, string>& output2where) {
    if (root->isLeaf) {
        output2where[root->c] = nowString;
        return;
    }
    // not leaf
    if (root->leftChild) {
        output(root->leftChild, nowString + '0', output2where);
    }
    if (root->rightChild) {
        output(root->rightChild, nowString + '1', output2where);
    }
}

void destroyTree(Node* root) {
    if (root->isLeaf) {
        delete root;
        return;
    }
    if (root->leftChild) {
        destroyTree(root->leftChild);
    }
    if (root->rightChild) {
        destroyTree(root->rightChild);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<Node*, vector<Node*>, cmp> pq;
        vector<char> charOrder;
        unordered_map<char, string> ans;
        // input
        for (int i = 0; i < n; i++) {
            char c;
            double weight;
            cin >> c >> weight;
            charOrder.push_back(c);
            Node* thisNode = new Node;
            thisNode->c = c;
            thisNode->isLeaf = true;
            thisNode->weight = weight;
            pq.push(thisNode);
        }
        // build
        while (pq.size() > 1) {
            Node* leftNode = pq.top();
            pq.pop();
            Node* rightNode = pq.top();
            pq.pop();
            Node* newNode = new Node;
            newNode->isLeaf = false;
            newNode->weight = leftNode->weight + rightNode->weight;
            newNode->leftChild = leftNode, newNode->rightChild = rightNode;
            pq.push(newNode);
            // printf("[%lf + %lf]\n", leftNode->weight, rightNode->weight);
        }
        Node* root;
        if (pq.top()->isLeaf) {
            root = new Node;
            root->leftChild = pq.top();
            root->rightChild = nullptr;
            root->isLeaf = false;
            root->weight = pq.top()->weight;
        }
        else {
            root = pq.top();
        }
        // output
        output(root, "", ans);
        for (char c : charOrder) {
            cout << c << ": " << ans[c] << ' ';
        }
        puts("");
        // end
        destroyTree(root);
    }
    return 0;
}

/*
1
6 
a 0.05 
b 0.32 
c 0.18 
d 0.07 
e 0.25 
f 0.13

a: 1000 b: 11 c: 00 d: 1001 e: 01 f: 101
*/

/*
6
19
b 0.28
c 0.57
d 0.05
e 0.02
f 0.04
g 0.02
h 0.01
i 0.01
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
p 0.00
q 0.00
r 0.00
s 0.00
t 0.00
16
b 0.33
c 0.07
d 0.44
e 0.14
f 0.02
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
p 0.00
q 0.00
14
b 0.39
c 0.55
d 0.02
e 0.04
f 0.00
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
14
b 0.10
c 0.69
d 0.10
e 0.11
f 0.00
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
7
b 0.85
c 0.08
d 0.03
e 0.01
f 0.03
g 0.00
h 0.00
12
b 0.15
c 0.06
d 0.60
e 0.05
f 0.13
g 0.01
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00

b: 01 c: 1 d: 0011 e: 00100 f: 0001 g: 00101 h: 000011 i: 00000 j: 0000101010 k: 0000101011 l: 0000101100 m: 0000101101 n: 0000101110 o: 0000101111 p: 000010000 q: 000010001 r: 000010010 s: 000010011 t: 000010100
b: 11 c: 1001 d: 0 e: 101 f: 10001 g: 100001010 h: 100001011 i: 100001100 j: 100001101 k: 100001110 l: 100001111 m: 10000000 n: 10000001 o: 10000010 p: 10000011 q: 10000100
b: 01 c: 1 d: 0001 e: 001 f: 00001100 g: 00001101 h: 00001110 i: 00001111 j: 0000000 k: 0000001 l: 0000010 m: 0000011 n: 0000100 o: 0000101
b: 0111 c: 1 d: 010 e: 00 f: 01101100 g: 01101101 h: 01101110 i: 01101111 j: 0110000 k: 0110001 l: 0110010 m: 0110011 n: 0110100 o: 0110101
b: 1 c: 01 d: 0011 e: 00101 f: 000 g: 001000 h: 001001
b: 00 c: 0100 d: 1 e: 01011 f: 011 g: 010101 h: 010100100 i: 010100101 j: 010100110 k: 010100111 l: 01010000 m: 01010001
*/