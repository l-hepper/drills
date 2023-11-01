#include <iostream>
#include <string>
using namespace std;

int *createArray(size_t, int);
string reverse_string(const string &str);
int *apply_all(int *array1, size_t array1Size, int *array2, size_t array2Size);
void print(const int *const arrayName, size_t arraySize);

int main() {

    int array1[] {1, 2, 3};
    int array2[] {10, 20, 30};


    int *results = apply_all(array1, 3, array2, 3);
    print(results, 9);
    delete [] results;
}

int *apply_all(int *array1, size_t array1Size, int *array2, size_t array2Size) {

    size_t sizeOfNewArray = array1Size * array2Size;
    cout << sizeOfNewArray << endl;

    int *newArray {new int[sizeOfNewArray]};

    int newArrayIndex {0};
    for (size_t i {0}; i < array1Size; i++) {
        for (size_t j {0}; j < array2Size; j++) {
            *(newArray + newArrayIndex) = *(array1 + i) * *(array2 + j);
            newArrayIndex++;
        }
    }

    return newArray;

}

void print(const int *const arrayName, size_t arraySize) {
    for (size_t i {0}; i < arraySize; i++) {
        cout << arrayName[i] << endl;
    }
}

// write a function which swaps the destination of two pointers without using a temp variable
void swapPointers(int* ptr1, int* ptr2) {
//-- Write your code below this inline
    
    *ptr1 = *ptr1 + *ptr2; // Add the values of both pointers together and store in pointer 1
    *ptr2 = *ptr1 - *ptr2; // Minus the value of pointer 2 from pointer 1 to get the value of pointer 2 (results in the original value of pointer 1 being stored in pointer 2)
    *ptr1 = *ptr1 - *ptr2; // Minus the value of pointer 2 from pointer 1 to get the value of pointer 1 (results in the original value of pointer 2 being stored in pointer 1)
    
//-- Write your code above this line

}

// Write a function which creates and returns the pointer to an array of integers - pass in the size of the array and its initial value
int *createArray(size_t arraySize, int initialValue) {

    int *arrayName {new int[arraySize]};

    for (int i {0}; i < arraySize; i++) {
        * (arrayName + i) = initialValue;
    }

    return arrayName;
}


// Write a function to reverse the array - the pointer for the array and the size is being passed to the function
void reverse_array(int* arr, int size) {
    
    // Declare pointers for the start of the array and the end
    int *start = arr;
    int *end = arr + (size - 1);
    
    while (end > start) {

    // Swamp the elements at the start and the end of the array with the usual temp technique
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Move the pointers toward each other to continue swapping
        start++;
        end--;
    }
}


// // Write a function which takes in the reference to a string and reverses it
// string reverse_string(const string &str) {
//     string reversed;
    
//     int string_size = static_cast<int>(str.length());

//     for (int i {string_size - 1}; i >= 0; i--) {
//         reversed += str[i];
//     }
    
    
//     return reversed;
// }
// // Same thing but the solution uses pointer arithmetic
// std::string reverse_string(const std::string& str) {
//     std::string reversed;

//     const char* start = str.c_str();                    // Pointer to the first character
//     const char* end = str.c_str() + str.size() - 1;     // Pointer to the last character

//     while (end >= start) {
//         reversed.push_back(*end);   // Append the character at the end pointer to the reversed string
//         end--;
//     }

//     return reversed;
// }