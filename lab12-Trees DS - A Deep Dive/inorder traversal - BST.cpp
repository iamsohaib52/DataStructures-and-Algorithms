#include <iostream>
using namespace std;

struct node {
    int element;
    struct node* left;
    struct node* right;
};

/* To create a new node */
struct node* createNode(int val) {
    struct node* Node = new struct node;
    Node->element = val;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

/* Function to traverse the nodes of a binary tree in Inorder */
void traverseInorder(struct node* root) {
    if (root == NULL)
        return;
    traverseInorder(root->left);
    cout << " " << root->element << " ";
    traverseInorder(root->right);
}

int main() {
    // Creating a binary tree with the specified structure
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "\n The Inorder traversal of the given binary tree is -\n";
    traverseInorder(root);

    return 0;
}

