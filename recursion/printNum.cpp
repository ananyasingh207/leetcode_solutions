#include <iostream>
using namespace std;

// This is only for recurion, not optimized with DP

void printNto1(int n) {
    // Base case
    if (n == 0) {
        return;
    }

    // Work is done first
    cout << n << " ";
    
    // Recursive call
    printNto1(n - 1);
}

void print1toN(int n) {
    // Base case
    if (n == 0) {
        return;
    }

    // Recursive call is made first
    print1toN(n - 1);

    // Work is done on the way back
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;

    cout << endl << "Printing " << n << " to 1:" << endl;
    printNto1(n);
    cout << endl;

    cout << endl << "Printing 1 to " << n << ":" << endl;
    print1toN(n);
    cout << endl << endl;

    return 0;
}