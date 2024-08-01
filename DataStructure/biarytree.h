#pragma once

#include <iostream>

using namespace std;

// 二叉树节点结构
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // 辅助插入函数
    TreeNode* insert(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // 辅助查找函数
    bool search(TreeNode* node, int data) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        } else if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

    // 前序遍历
    void preOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序遍历
    void inOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // 后序遍历
    void postOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int data) {
        root = insert(root, data);
    }

    // 查找节点
    bool search(int data) {
        return search(root, data);
    }

    // 前序遍历
    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    // 中序遍历
    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    // 后序遍历
    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};



