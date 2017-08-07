//
// Created by ThucHD on 7/5/17.
//

#include "main.cpp"
Node* findMin(Node* root, Node* prev);

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* node = new Node();
    node -> val = val;
    node -> left = node -> right = NULL;

    return node;
}

Node* insertNode(Node* root, int x) {
    if(root == NULL)
        return createNode(x);

    if(root->val > x)
        root->left =  insertNode(root->left, x);
    else if(root->val < x)
        root->right = insertNode(root -> right, x);

    return root;
}

Node* removeNode(Node* root, int x) {
    if(root == NULL)
        return root;
    else if(root->val > x)
        root->left = removeNode(root->left, x);
    else if(root->val < x)
        root->right = removeNode(root->right, x);
    else if(root->val == x) {
        if(root->right == NULL) {
            Node* temp = root->left;
            delete(root);
            return temp;
        } else if(root->left == NULL) {
            Node* temp = root->right;
            delete(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = removeNode(root->right, temp->val);
    }
    return root;
}

Node* findMin(Node* root) {
    Node* current = root;
    while(current->left != NULL)
        current = current->left;

    return current;
}