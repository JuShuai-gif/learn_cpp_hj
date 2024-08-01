#include <iostream>
#include <stack>

using namespace std;

int factorial(int n) {
    struct Frame {
        int n;
        int result;
        Frame(int n) : n(n), result(1) {}
    };

    stack<Frame> callStack;
    callStack.push(Frame(n));

    while (!callStack.empty()) {
        Frame& current = callStack.top();

        if (current.n <= 1) {
            current.result = 1;
            callStack.pop();
            if (!callStack.empty()) {
                Frame& parent = callStack.top();
                parent.result *= current.result;
            }
        } else {
            callStack.push(Frame(current.n - 1));
        }
    }

    return callStack.empty() ? 1 : callStack.top().result;
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    return 0;
}
