
#include <iostream>

using namespace std;

template <class T>
struct stack {
    const size_t capacity = 100;
    int top;
    T* elements;
    stack() {
        top = -1;
        elements = new char[capacity];
    }
    bool isEmpty() {
        // if the size is 0 then we we will get that top is -1;
        return top == -1;
    }
    bool isFull() { return top == capacity - 1; }
    void push(T ele) {
        if (isFull()) {
            cout << "\n this stack is full \n";
            return;
        }
        elements[++top] = ele;
    }
    void clear() {
        top = -1;
        delete elements;
        cout << "\ncleared the stack";
    }
    T pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return '\0';  // or handle with an exception
        }
        return elements[top--];
    }
};

void read_input(stack<char>& s) {
    char a;

    cout << "type ssomething ma: \n";

    while (a != '\n') {
        cout << a;
        s.push(char(a));
        cin.get(a);
    }
}
int main() {
    stack<char> s;
    read_input(s);
    cout << "\n";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    s.clear();
    return 0;
}
