#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n < 1){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        // Recursive call
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}; 


int main() {
    Solution s;

    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int ways = s.climbStairs(n);

    cout << "Number of ways found by your function: " << ways << endl;

    return 0;
}