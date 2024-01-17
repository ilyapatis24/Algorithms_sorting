#include <iostream>

void countSort(int* arr, int size)
{
	int arrMaxValue = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arrMaxValue)
		{
			arrMaxValue = arr[i];
		}
	};

	int arrForCountSize = arrMaxValue + 1;

	int* arrForCount = new int[arrForCountSize] {};

	for (int i = 0; i < size; i++)
	{
		arrForCount[arr[i]]++;
	};

	int arrIndex = 0;
	for (int i = 0; i < arrForCountSize; ++i)
	{
		for (int j = 0; j < arrForCount[i]; ++j)
			arr[arrIndex++] = i;
	};

	delete[] arrForCount;
	arrForCount = nullptr;
};

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
}

int main(int argc, char** argv) {
    system("chcp 1251");
    int data[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    int size = sizeof(data) / sizeof(data[0]);
    std::cout << "Исходный массив:" << std::endl;
    printArray(data, size);
	countSort(data, size);
    std::cout << std::endl;
    std::cout << "Отсортированный массив:" << std::endl;
    printArray(data, size);
    return 0;
}

// Алгоритмическая сложность: по времени О(n), по памяти О(n).