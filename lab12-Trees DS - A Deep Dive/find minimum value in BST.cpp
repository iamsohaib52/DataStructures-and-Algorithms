#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int Searchmin(Node* root);

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    int min_value = Searchmin(root);
    if (min_value != -1) {
        cout << "Minimum value in the tree: " << min_value << endl;
    }

    return 0;
}

int Searchmin(Node* root) {
    if (root == NULL) {
        cout << "Empty!" << endl;
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }
    
    return root->data;
}

