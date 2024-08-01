#pragma once
#include <iostream>

using namespace std;

// 定义双向链表节点结构
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// 双向链表类
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // 插入节点到链表头部
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // 插入节点到链表尾部
    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // 删除链表中第一个匹配的节点
    void deleteNode(int key) {
        Node* temp = head;

        // 找到要删除的节点
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        // 如果找不到该节点
        if (temp == nullptr) return;

        // 如果是头节点
        if (temp == head) {
            head = temp->next;
        }

        // 修改前一个节点的指针
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        // 修改下一个节点的指针
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // 反转链表
    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // 打印链表
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // 反向打印链表
    void printListReverse() {
        Node* temp = head;
        if (temp == nullptr) return;

        // 移动到链表末尾
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // 从末尾开始打印
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }

    // 析构函数，释放链表内存
    ~DoublyLinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};