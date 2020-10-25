#include<iostream>
using namespace std;

void mergeSort(int* arr, int p, int q) {
	int tmp[10];
	int k = (p + q) / 2;
	int a, b, i;
	if (q > p) {
		mergeSort(arr, p, k);
		mergeSort(arr, k + 1, q);
		a = p;
		b = k + 1;
		i = 0;
		while (i < q-p + 1) {
			if (a <= k && b <= q) {
				if (arr[a] > arr[b]) {
					tmp[i++] = arr[b];
					b++;
				}
				else {
					tmp[i++] = arr[a];
					a++;
				}
			}
			else if (a <= k) {
				tmp[i++] = arr[a];
				a++;
			}
			else {
				tmp[i++] = arr[b];
				b++;
			}
			
		}
		i = 0;
		for (int j = p; j <= q; ++j) {
			arr[j] = tmp[i++];
		}
	}
}

int main() {
	int arr[10] = { 14, 21, 1, 9, 71, 3, 22, 41, 99, 33 };
	cout << "정렬 전 : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;

	mergeSort(arr, 0, 9);
	cout << "정렬 후 : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
}