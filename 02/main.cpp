#include <iostream>


void quickSort(int* arr, int arrLeft, int arrRight)
{
	if (arrLeft >= arrRight)
	{
		return;
	}
	if ((arrRight - arrLeft) == 2)
	{
		if (arr[arrLeft] > arr[arrRight])
			std::swap(arr[arrLeft], arr[arrRight]);
		return;
	}

	int pivot = arr[(arrLeft + arrRight) / 2];

	int i = arrLeft; 
	int j = arrRight; 

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		};
	}

	quickSort(arr, arrLeft, j);
	quickSort(arr, i, arrRight);
};

void printArray(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
}

int main(int argc, char** argv) {
	system("chcp 1251");
	int data[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int size = sizeof(data) / sizeof(data[0]);
	std::cout << "Исходный массив:" << std::endl;
	printArray(data, size);
	quickSort(data, 0, size - 1);
	std::cout << std::endl;
	std::cout << "Отсортированный массив:" << std::endl;
	printArray(data, size);
	return 0;
}

// Алгоритмическая сложность: по времени О(n*log(n)), по памяти О(1).