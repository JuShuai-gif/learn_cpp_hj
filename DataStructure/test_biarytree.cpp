#include "biarytree.h"

int main() {
    BinaryTree tree;

    // 插入节点
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // 查找节点
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    // 前序遍历
    cout << "Preorder traversal: ";
    tree.preOrder();

    // 中序遍历
    cout << "Inorder traversal: ";
    tree.inOrder();

    // 后序遍历
    cout << "Postorder traversal: ";
    tree.postOrder();

    return 0;
}
