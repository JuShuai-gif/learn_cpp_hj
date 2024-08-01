#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

// 定义链表节点结构
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// 栈类
class LinkedListStack {
private:
    Node* head;

public:
    LinkedListStack() : head(nullptr) {}

    // 压入栈顶
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // 移除并返回栈顶元素
    int pop() {
        if (isEmpty()) {
            throw out_of_range("Stack underflow");
        }

        Node* temp = head;
        int data = head->data;
        head = head->next;
        delete temp;

        return data;
    }

    // 返回栈顶元素但不移除
    int top() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }

    // 检查栈是否为空
    bool isEmpty() {
        return head == nullptr;
    }

    // 打印栈中的元素
    void printStack() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 析构函数，释放栈内存
    ~LinkedListStack() {
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

