#include <iostream>
#include <string>
using namespace std;

int main() {

    string input {};
    cout << "Enter the string to use for pyramid: ";
    getline(cin, input);


    size_t myLength {input.length()};

    for (size_t i {myLength}; i > 0; i--) {
        for (size_t j {0}; j < i; j++) {
            cout << " ";
        }
        for (size_t k {0}; k <= (myLength-i); k++) {
            cout << input.at(k);
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}