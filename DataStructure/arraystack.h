#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayStack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    // 构造函数
    ArrayStack(int size) : capacity(size), topIndex(-1) {
        arr = new int[capacity];
    }

    // 压入栈顶
    void push(int data) {
        if (topIndex == capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        arr[++topIndex] = data;
    }

    // 移除并返回栈顶元素
    int pop() {
        if (isEmpty()) {
            throw out_of_range("Stack underflow");
        }
        return arr[topIndex--];
    }

    // 返回栈顶元素但不移除
    int top() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return arr[topIndex];
    }

    // 检查栈是否为空
    bool isEmpty() {
        return topIndex == -1;
    }

    // 打印栈中的元素
    void printStack() {
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 析构函数，释放栈内存
    ~ArrayStack() {
        delete[] arr;
    }
};