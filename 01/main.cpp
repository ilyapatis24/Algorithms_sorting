#include <iostream>

void merge(int* array, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArray = new int [leftSize];
    int* rightArray = new int [rightSize];

    for (int i = 0; i < leftSize; ++i) {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }

    int l = 0, r = 0, k = left;
    while (l < leftSize && r < rightSize) {
        if (leftArray[l] <= rightArray[r]) {
            array[k] = leftArray[l];
            ++l;
        }
        else {
            array[k] = rightArray[r];
            ++r;
        }
        ++k;
    }

    while (l < leftSize) {
        array[k] = leftArray[l];
        ++l;
        ++k;
    }

    while (r < rightSize) {
        array[k] = rightArray[r];
        ++r;
        ++k;
    }
    delete[] leftArray;
    leftArray = nullptr;
    delete[] rightArray;
    rightArray = nullptr;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
}

void mergeSort(int* array, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}

int main(int argc, char** argv) {
    system("chcp 1251");
    int data[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size = sizeof(data) / sizeof(data[0]);
    std::cout << "Исходный массив:" << std::endl;
    printArray(data, size);
    mergeSort(data, 0, size - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив:" << std::endl;
    printArray(data, size);
    return 0;
}

// Алгоритмическая сложность: по времени О(n), по памяти О(n).