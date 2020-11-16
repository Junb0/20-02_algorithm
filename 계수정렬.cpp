#include<iostream>
#define N 10
#define DIGITS(i) (arr[i] % (exp * 10)) / exp
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
		C[DIGITS(i)]++;
	for (int i = 1; i < 10; ++i)
		C[i] = C[i] + C[i - 1];
	int arr_tmp[100];
	for (int i = n - 1; i >= 0; --i) {
		arr_tmp[C[DIGITS(i)]] = arr[i];
		C[DIGITS(i)]--;
	}
	for (int i = 0; i < n; ++i)
		arr[i] = arr_tmp[i + 1];
}

void radixSort(int arr[], int n) {
	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}

int main() {
	int arr[N] = { 33, 12, 36, 10, 121, 99, 472, 3, 50, 49 };
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