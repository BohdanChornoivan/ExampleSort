/*

*/

#include <iostream>
#include <chrono>
#include "study.h"

const int SIZE = 100;

int main()
{
	using namespace std;

    SetRandomSeed();

	int arr01[SIZE] = {};

	Initialization(arr01, SIZE, 0, 200);
    int arr02[SIZE] = {};
    int arr03[SIZE] = {};
    int arr04[SIZE] = {};

	std::copy(std::begin(arr01), std::end(arr01), arr02);
	std::copy(std::begin(arr01), std::end(arr01), arr03);
	std::copy(std::begin(arr01), std::end(arr01), arr04);

    auto start1 = std::chrono::high_resolution_clock::now();

    selectionSort(arr01, SIZE);

    auto end1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    std::cout << "Selection sort time: " << duration1.count() << " microseconds" << std::endl;

    std::cout << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();

    bubbleSort(arr02, SIZE, false);

    auto end2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "Bubble sort time: " << duration2.count() << " microseconds" << std::endl;

    std::cout << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();

    insertionSort(arr03, SIZE);

    auto end3 = std::chrono::high_resolution_clock::now();

    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

    std::cout << "Insertion sort time: " << duration3.count() << " microseconds" << std::endl;

    std::cout << std::endl;

    auto start4 = std::chrono::high_resolution_clock::now();

	fastSort(arr04, 0, SIZE - 1);

    auto end4 = std::chrono::high_resolution_clock::now();

    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);

    std::cout << "Fast sort time: " << duration4.count() << " microseconds" << std::endl;

    ShowArray(arr04, SIZE);

    std::cout << std::endl;

    int value;
    cout << "Enter value: ";
    cin >> value;

    if (binarySearch(arr04, SIZE, value))
    {
        cout << "Find\n";
    }

	return 0;
}