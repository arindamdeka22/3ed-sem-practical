#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int maxSize;
    int top;
    T *array;

public:
    // Constructor
    Stack(int size) {
        maxSize = size;
        top = -1;
        array = new T[maxSize];
    }

    // Destructor
    ~Stack() {
        delete[] array;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == maxSize - 1;
    }

    // Push an element onto the stack
    void push(T element) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push element " << element << ".\n";
            return;
        }
        array[++top] = element;
        cout << "Pushed: " << element << "\n";
    }

    // Pop an element from the stack
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop from an empty stack.\n";
            return T(); // Return default value for type T
        }
        T poppedElement = array[top--];
        cout << "Popped: " << poppedElement << "\n";
        return poppedElement;
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // Example usage with int type
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();

    int poppedValue = intStack.pop();
    cout << "Popped value: " << poppedValue << "\n";
    intStack.display();

    // Example usage with double type
    Stack<double> doubleStack(3);

    doubleStack.push(3.14);
    doubleStack.push(6.28);
    doubleStack.display();

    double poppedDouble = doubleStack.pop();
    cout << "Popped double: " << poppedDouble << "\n";
    doubleStack.display();

    return 0;
}
