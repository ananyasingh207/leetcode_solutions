#include <iostream>
using namespace std;

int fib(int n) {
    // Base case 1
    if (n == 0) {
        return 0;
    }
    
    // Base case 2
    if (n == 1) {
        return 1;
    }

    // Recursive call
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter a number to find its Fibonacci value: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number." << endl;
    } else {
        cout << "The Fibonacci number at position " << n << " is: " << fib(n) << endl;
    }

    return 0;
}