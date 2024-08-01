#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

// 定义双向链表节点结构
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// 栈类
class DoublyListStack {
private:
    Node* head;
    Node* tail;

public:
    DoublyListStack() : head(nullptr), tail(nullptr) {}

    // 压入栈顶
    void push(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 移除并返回栈顶元素
    int pop() {
        if (isEmpty()) {
            throw out_of_range("DoublyListStack underflow");
        }

        Node* temp = tail;
        int data = tail->data;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        return data;
    }

    // 返回栈顶元素但不移除
    int top() {
        if (isEmpty()) {
            throw out_of_range("DoublyListStack is empty");
        }
        return tail->data;
    }

    // 检查栈是否为空
    bool isEmpty() {
        return head == nullptr;
    }

    // 打印栈中的元素
    void printDoublyListStack() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // 析构函数，释放栈内存
    ~DoublyListStack() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};