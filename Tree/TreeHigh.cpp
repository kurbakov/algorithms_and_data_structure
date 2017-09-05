// Solution from HackeRank
// Tree: Height of a Binary Tree

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {
    if (root == nullptr) return -1;
    return std::max(height(root->left), height(root->right))+1;
}