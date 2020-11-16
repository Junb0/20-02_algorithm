#include<iostream>
#define N 10
using namespace std;

int getMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 0; i < n; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countingSort(int arr[], int n, int exp) {
	int C[10] = { 0, };
	for (int i = 0; i < n; ++i)
		C[(arr[i] % (exp * 10)) / exp]++;
	for (int i = 1; i < 10; ++i)
		C[i] = C[i] + C[i - 1];
	int* arr_tmp = new int;
	for (int i = n - 1; i >= 0; --i) {
		arr_tmp[C[(arr[i] % (exp * 10)) / exp]] = arr[i];
		C[(arr[i] % (exp * 10)) / exp]--;
	}
	arr = arr_tmp;
	delete[] arr_tmp;
}

void radixSort(int arr[], int n) {
	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}

int main() {
	int arr[N] = { 33, 12, 36, 10, 20, 99, 10, 3, 50, 49 };
	cout << "정렬 전 : ";
	for(int i = 0; i < N; ++i)
		cout << arr[i] << ' ';
	cout << endl;

	radixSort(arr, N);
	cout << "정렬 후 : ";
	for (int i = 0; i < N; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}