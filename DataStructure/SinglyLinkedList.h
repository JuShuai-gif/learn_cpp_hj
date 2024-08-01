#pragma once
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) :
        data(val), next(nullptr) {
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() :
        head(nullptr) {
    }

    // 插入节点到链表头部
    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // 反转链表
    void reverse() {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    // 删除链表中第一个匹配的节点
    void deleteNode(int key) {
        Node *temp = head;
        Node *prev = nullptr;

        // 如果头结点是要删除的节点
        if (temp != nullptr && temp->data == key) {
            // 改变头指针
            head = temp->next;
            // 释放旧头结点
            delete temp;
            return;
        }

        // 查找要删除的节点
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // 如果找不到该节点
        if (temp == nullptr) {
            return;
        }

        // 断开连接，并删除节点
        prev->next = temp->next;
        delete temp;
    }

    // 打印链表
    void printList() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    int size() {
        int length{0};
        Node *temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    // 拆分链表为两半
    Node *getMiddle(Node *head) {
        if (head == nullptr) {
            return head;
        }

        Node *slow = head;
        Node *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // 合并两个有序链表
    Node *sortedMerge(Node *left, Node *right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        Node *result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = sortedMerge(left->next, right);
        } else {
            result = right;
            result->next = sortedMerge(left, right->next);
        }
        return result;
    }
    // 归并排序链表
    Node *mergeSort(Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node *middle = getMiddle(head);
        Node *nextOfMiddle = middle->next;
        middle->next = nullptr;

        Node *left = mergeSort(head);
        Node *right = mergeSort(nextOfMiddle);

        return sortedMerge(left, right);
    }
    // 排序链表
    void sort() {
        head = mergeSort(head);
    }
    ~LinkedList() {
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};
