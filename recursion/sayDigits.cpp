#include <iostream>
#include <string>
using namespace std;

void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //recursive call
    sayDigit(n/10, arr);
    //processing
    int digit = n % 10;
    cout << arr[digit] << " " ;

}

int main() {

    string arr[10] = {"zero", "one", "two", "three",
                       "four", "five", "six",
                       "seven", "eight", "nine"};

    int n;
    cin >> n;

    cout << endl << endl << endl ;
    sayDigit(n, arr);
    cout << endl << endl << endl ;

}