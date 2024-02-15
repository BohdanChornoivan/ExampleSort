#pragma once
unsigned int GetSeedRandom();
void SetRandomSeed(unsigned seed = GetSeedRandom());
int GetRandomNumRange(int min, int max);

template <typename T>
void Initialization(T arr[], int size, int min = 0, int max = 99)
{
	for (int i = 0; i < size; ++i)
		arr[i] = GetRandomNumRange(min, max);
}

template <typename T>
void ShowArray(const T arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

template <typename T>
bool binarySearch(T arr[], int size, T value)
{
	int leftBound = 0;
	int rightBound = size - 1;
	int middle;

	do
	{
		middle = (rightBound + leftBound) / 2;

		if (value < arr[middle])
			rightBound = middle - 1;
		else if (value > arr[middle])
			leftBound = middle + 1;
		else
			return true;

	} while (leftBound <= rightBound);

	return false;
}

template <typename T>
void selectionSort(T arr[], int size, bool isAscendingOrder = true)
{
	if (isAscendingOrder)
	{
		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
				if (arr[i] > arr[j])
					std::swap(arr[i], arr[j]);
	}
	else
	{

		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
				if (arr[i] < arr[j])
					std::swap(arr[i], arr[j]);
	}
}

template <typename T>
void bubbleSort(T arr[], int size, bool isAscendingOrder = true)
{
	bool swapped;

	for (int i = 0; i < size - 1; ++i) {

		swapped = false;

		for (int j = size - 1; j > i; --j)
		{
			if (isAscendingOrder && arr[j] > arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
				swapped = true;
			}
			else if (!isAscendingOrder && arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

template <typename T>
void insertionSort(T arr[], int size, bool isAscendingOrder = true)
{
	for (int i = 1; i < size; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		while (isAscendingOrder && j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		while (!isAscendingOrder && j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
}

template <typename T>
void fastSort(T arr[], int first, int last)
{
	T middle = arr[(last + first) / 2];
	int i = first;
	int j = last;

	do
	{
		while (middle > arr[i])
			++i;
		
		while (middle < arr[j])
			--j;

		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}

	} while (i <= j);

	if (i < last)
		fastSort(arr, i, last);
	
	if (j > first)
		fastSort(arr, first, j);
}