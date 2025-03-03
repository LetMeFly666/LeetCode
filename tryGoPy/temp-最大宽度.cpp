#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct Node {
    int val;
    Node* left, *right;
    int num;
};

Node* gendata() {
    // Node* 
}

int getMax2(Node* root) {
    queue<Node*> thisL;
}

int getMax(Node* root) {
    queue<Node*> thisLayer;
    int ans = 1;
    thisLayer.push(root);
    while (thisLayer.size()) {
        queue<Node*> nextLayer;
        int left = 0, right = 0, cnt = 0;
        while (thisLayer.size()) {
            cnt++;
            Node* thisNode = thisLayer.front();
            thisLayer.pop();
            if (!thisNode) {
                nextLayer.push(nullptr);
                nextLayer.push(nullptr);
            } else {
                if (!left) {
                    left = right = cnt;
                } else {
                    right = cnt;
                }
                nextLayer.push(thisNode->left);
                nextLayer.push(thisNode->right);
            }
            ans = max(ans, right - left + 1);
        }
        if (!left) {
            break;
        }
        swap(thisLayer, nextLayer);
    }
    return ans;
}

int main() {
    Node* root = gendata();
    cout << getMax(root) << endl;
    return 0;
}