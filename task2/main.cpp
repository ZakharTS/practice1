#include <iostream>

void display_array(int *array, int arraySize);

bool next_array_swap(int *array, int arraySize);

int main() {
    int arraySize = 0;
    std::cout << "Array size: ";
    std::cin >> arraySize;
    int array[arraySize];
    std::cout << "Array: ";
    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i];
    }
    std::cout << std::endl;
    while (next_array_swap(array, arraySize)) {
        display_array(array, arraySize);
    }
    return 0;
}

void display_array(int *array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

bool next_array_swap(int *array, int arraySize) {
    int first = -1;
    for (int i = arraySize - 2; i >= 0; i--) {
        if (array[i] < array[i + 1]) {
            first = i;
            break;
        }
    }
    if (first == -1) return 0;
    for (int i = arraySize - 1; i >= 0; i--) {
        if (array[i] > array[first]) {
            std::swap(array[first], array[i]);
            break;
        }
    }

    int left = first + 1, right = arraySize - 1;
    while (left < right) {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
    return 1;
}