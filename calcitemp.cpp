#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        throw "Division by zero is not allowed!";
    }
    return a / b;
}

int main() {
    double num1, num2;
    char op;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;
    
    try {
        if (op == '+') {
            cout << "Result: " << add(num1, num2) << endl;
        } else if (op == '-') {
            cout << "Result: " << subtract(num1, num2) << endl;
        } else if (op == '*') {
            cout << "Result: " << multiply(num1, num2) << endl;
        } else if (op == '/') {
            cout << "Result: " << divide(num1, num2) << endl;
        } else {
            cout << "Invalid operator!" << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}



