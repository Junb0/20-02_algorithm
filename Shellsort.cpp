#include <iostream>
#define N 10
using namespace std;

void shellSort(int* arr, int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int current = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > current) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = current;
		}
	}
}

int main() {
	int arr[N] = { 33, 12, 36, 10, 20, 99, 10, 3, 50, 49 };
	cout << "정렬 전 : ";
	for (int d : arr)
		cout << d << ' ';
	cout << endl;

	shellSort(arr, N);
	cout << "정렬 후 : ";
	for (int d : arr)
		cout << d << ' ';
	cout << endl;
}