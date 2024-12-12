#include <iostream>
#include<vector>
#include <algorithm>
#include <cstdlib>
#include<ctime>
#include <chrono>
#include <string>
using namespace std;


vector<int> random_arrays(int size) {
	vector<int> arr(size);
	for (int& x : arr) {
		x = rand() % 100;
	}
	return arr;
}


vector<int> sorted_arrays(int size) {
	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	return arr;
}


vector<int> inversely_sorted_arrays(int size) {
	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		arr[i] = size - i;
	}
	return arr;
}


void heapify(int arr[], int n, int i, int& comparisonCount) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n) {
		comparisonCount++;
		if (arr[left] < arr[smallest]) {
			smallest = left;
		}
	}
	if (right < n) {
		comparisonCount++;
		if (arr[right] < arr[smallest]) {
			smallest = right;
		}
	}
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		heapify(arr, n, smallest, comparisonCount);
	}
}


int heap_sort_count(int arr[], int n) {
	int comparisonCount = 0;
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, comparisonCount);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, comparisonCount);
	}
	return comparisonCount;
}


int bubble_sort_count(int arr[], int n) {
	int comparisonCount = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			comparisonCount++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return comparisonCount;
}


int Selection_sort_count(int arr[], int n) {
	int comparisonCount = 0;
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			comparisonCount++;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}
	return comparisonCount;
}


int insertion_sort_count(int arr[], int n) {
	int comparisonCount = 0;

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			comparisonCount++;
			arr[j + 1] = arr[j];
			j--;
		}

		if (j >= 0) {
			comparisonCount++;
		}

		arr[j + 1] = key;
	}
	return comparisonCount;
}


void test_comparisions() {
	srand(time(0));

	vector<vector<string>> all_results;

	for (int size = 1; size <= 30; size++) {
		
			vector<int> random_array = random_arrays(size);
			vector<int> sorted_array = sorted_arrays(size);
			vector<int> inverse_array = inversely_sorted_arrays(size);

			int* arr = new int[size];
			auto test_sort = [&](int (*sort_func)(int[], int), const vector<int>& array, const string& sort_name, const string& array_type) {
				/*copy(array.begin(), array.end(), arr);*/
				vector<int> arr(array.begin(), array.end());

				auto start = chrono::high_resolution_clock::now();
				int comparisons = sort_func(arr.data(), size);
				auto end = chrono::high_resolution_clock::now();
				chrono::duration<double> duration = end - start;

				double duration_ms = duration.count() * 1000;


				all_results.push_back({ std::to_string(size), array_type + " Array", sort_name, std::to_string(comparisons), std::to_string(duration_ms) });
				cout << array_type << "array size: " << size << ", " << sort_name << ": " << comparisons << " comparisons, " << duration_ms << " seconds" << endl;
		};


			test_sort(bubble_sort_count, random_array, "Bubble sort", "Random");
			test_sort(Selection_sort_count, random_array, "Selection Sort", "Random");
			test_sort(insertion_sort_count, random_array, "Insertion sort", "Random");
			test_sort(heap_sort_count, random_array, "Heap Sort", "Random");

			test_sort(bubble_sort_count, sorted_array, "Bubble sort", "Sorted");
			test_sort(Selection_sort_count, sorted_array, "Selection sort", "Sorted");
			test_sort(insertion_sort_count, sorted_array, "insertion sort", "Sorted");
			test_sort(heap_sort_count, sorted_array, "Heap sort", "Sorted");

			test_sort(bubble_sort_count, inverse_array, "Bubble sort", "Inversely sorted");
			test_sort(Selection_sort_count, inverse_array, "Selection sort", "Inversely sorted");
			test_sort(insertion_sort_count, inverse_array, "insertion sort", "Inversely sorted");
			test_sort(heap_sort_count, inverse_array, "Heap sort", "Inversely sorted");

			delete[] arr;
		}
	}


int main() {
	srand(static_cast<unsigned>(time(0)));
	test_comparisions();
}