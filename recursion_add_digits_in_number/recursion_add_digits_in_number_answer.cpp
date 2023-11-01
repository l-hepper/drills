#include <iostream>
using namespace std;

int recursiveFunction(int n);

int main() {
    cout << recursiveFunction(1234) << endl;
}

// Write a recursive function call which adds up all of the digits in a number. e.g. passing in 12 should return 3, passing in 1234 should return 10, etc.

int recursiveFunction(int n) {
    
    // applying modulus to the last digit will result in just the last digit, with 0 being the answer passed to the last function call
    if (n == 0) {
        return n;
    }
    
    int lastDigit = n % 10; // the last number can be 'got' by applying % 10.
    int remainingDigits = n / 10; // the remaining digits can be 'got' by dividing by 10
    return lastDigit + recursiveFunction(remainingDigits);
}



