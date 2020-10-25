#include<iostream>
using namespace std;

void Swap(int* arr, int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void quickSort(int* arr, int Left, int Right) {
	int p = (Left + Right) / 2;
	int a = Left + 1;
	int b = a;
	while (b <= Right) {
		if (arr[b] < arr[Left]) {
			Swap(arr, a, b);
			a++;
		}
		b++;
	}
	Swap(arr, Left, a - 1);
	if (Left < Right) {
		quickSort(arr, Left, a - 2);
		quickSort(arr, a, Right);
	}
}

int main() {
	int arr[10] = { 14, 21, 1, 9, 31, 3, 22, 41, 99, 33 };
	cout << "정렬 전 : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;

	quickSort(arr, 0, 9);
	cout << "정렬 후 : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
}