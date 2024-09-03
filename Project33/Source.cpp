#include <iostream>
#include <math.h>


using namespace std;


template<class T>
void swappi(T& firstElem, T& secondElem)
{
	auto temp = std::move(firstElem);
	firstElem = std::move(secondElem);
	secondElem = std::move(temp);
}

template<class T>
void bubbleSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)	
	{
		bool flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swappi(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

template<class T>
void selectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{	
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swappi(arr[i], arr[minIndex]);
		}
	}
}

template<class T>
void insertionSort(T arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int sortedIndex = i - 1;
		
		while (sortedIndex > -1 && arr[sortedIndex] > arr[sortedIndex + 1])
		{
			swappi(arr[sortedIndex], arr[sortedIndex + 1]);
			sortedIndex--;
		}
	}
}

template<class T>
int partitionHoaraSort(T arr[], int left, int right)
{
	int pivot = arr[(left + right) / 2];

	while (left <= right)
	{
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;

		if (left <= right)
		{
			swappi(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left;
}

template<class T>
void HoaraSort(T arr[], int start, int end) {
	if (start >= end) return;

	int partition = partitionHoaraSort(arr, start, end);

	HoaraSort(arr, start, partition - 1);
	HoaraSort(arr, partition, end);
}


template<class T>
int partitionLomutoSort(T arr[], int start, int end)
{
	int left = start;

	for (int current = start; current < end; current++)
	{
		if (arr[current] <= arr[end])
		{
			swappi(arr[current], arr[left]);
			left++;
		}
	}

	swappi(arr[left], arr[end]);

	return left;
}

template<class T>
void LomutoSort(T arr[], int start, int end) {
	if (start >= end) return;

	int partition = partitionLomutoSort(arr, start, end);

	LomutoSort(arr, start, partition - 1);
	LomutoSort(arr, partition + 1, end);
}



int main()
{
	int arr[100]; 

	cout << "Enter the array: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	cout << "Arr before the LomutoSort: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}

	LomutoSort<int>(arr, 0, 9);

	cout << endl;

	cout << "Arr after the LomutoSort: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}