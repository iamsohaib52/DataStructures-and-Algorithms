#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(Node*& root, int key) {
    Node* prev = NULL;
    Node* current = root;

    while (current != NULL) {
        prev = current;
        if (key == current->data) {
            cout << "Cannot insert " << key << ", already in BST" << endl;
            return;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    Node* newNode = createNode(key);

    if (prev == NULL) {
        root = newNode;
    } else if (key < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

int main() {
    Node* root = NULL;
    root = createNode(5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 1);
    insert(root, 4);
    insert(root, 16);
    cout << root->right->right->data << endl;

    return 0;
}
