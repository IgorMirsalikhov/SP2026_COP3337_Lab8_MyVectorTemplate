#include "MyVector.hpp"
#include <iostream>

template <typename T>
MyVector<T>::MyVector(int capacity) {
    this->capacity = capacity;
    size = 0;
    elements = new T[capacity];
}

// // Copy constructor
// MyVector::MyVector(const MyVector& other) {
//     capacity = other.capacity;
//     size = other.size;
//     elements = new int[capacity];
//     for(int i = 0; i < size; i++) {
//         elements[i] = other.elements[i];
//     }
// }

template <typename T>
MyVector<T>::~MyVector() {
    delete [] elements;
}

template <typename T>
void MyVector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << "]\n";
}

template <typename T>
void MyVector<T>::push_back(const T& val) {
    if (full()) {
        allocateMemory(capacity * 2);
    }
    elements[size] = val;
    size++;
}

// bool MyVector::empty() const {
//     return size == 0;
// }

template <typename T>
bool MyVector<T>::full() const {
    return size == capacity;
}

template <typename T>
void MyVector<T>::allocateMemory(int memory_size) {
    capacity = memory_size;
    // Save the old address of the array
    T* old_array = elements;
    elements = new T[capacity];

    // Copy the elements
    for (int i = 0; i < size; i++) {
        elements[i] = old_array[i];
    }
    delete [] old_array;
}

// int MyVector::pop_back() {
//     if (!empty()) {
//         if (size < capacity / 2) {
//             allocateMemory(capacity / 2);
//         }
//         return elements[--size];
//     }
//     else {
//         throw "Empty vector";
//     }
// }

// int MyVector::getCapacity() const {
//     return capacity;
// }

// int& MyVector::at(int index) const {
//     if (index < size * -1 || index > size - 1) {
//         throw "Invalid index";
//     }
//     if (index >= 0) {
//         return elements[index];
//     }
//     else {
//         return elements[size - (index * -1)];
//     }
// }


// void MyVector::clear() {
//     delete [] elements;
//     size = 0;
//     capacity = 10;
    
//     elements = new int[capacity];
// }

// int MyVector::getSize() const {
//     return size;
// }

// void MyVector::push_front(int value) {
//     if (size >= capacity) {
//         allocateMemory(capacity * 2);
//     }
//     for (int i = size; i >= 1; i--) {
//         elements[i] = elements[i - 1]; 
//     }
//     elements[0] = value;
//     size++;
// }

// void MyVector::insert(int pos, int value) {
//     if (size == 0 && pos == -1) {
//         push_back(value);
//         return;
//     }
//     if (pos < size * -1  || pos > size - 1) {
//         throw "Invalid index";
//     }
//     if (size >= capacity) {
//         allocateMemory(capacity * 2);
//     }
//     if (pos < 0) {
//         pos = size - (pos * -1);
//     }
//     for (int i = size; i >= pos; i--) {
//         elements[i] = elements[i - 1]; 
//     }
//     elements[pos] = value;
//     size++;
// }
