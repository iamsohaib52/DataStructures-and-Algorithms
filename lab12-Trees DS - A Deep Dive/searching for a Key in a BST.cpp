#include<iostream>
using namespace std;
struct Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* SearchinBST(Node* root, int key);

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right=new Node(3);
    root->right->right = new Node(6);
    /* 
             4
           /  \
          2    5
         / \    \
       1   3     6
	*/

    if (SearchinBST(root, 5) == NULL) {
        cout << "Key doesn't exist!" << endl;
    }
    else {
        cout << "Key exists!" << endl;
    }

    return 0;
}

Node* SearchinBST(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (root->data > key) {
        return SearchinBST(root->left, key);
    }
    return SearchinBST(root->right, key);
}

