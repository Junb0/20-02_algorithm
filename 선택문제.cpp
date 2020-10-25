#include<iostream>
using namespace std;

void Swap(int* arr, int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int selection(int* arr, int Left, int Right, int k) {
	int p = (Left + Right) / 2;
	Swap(arr, Left, p);
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
	int S = a - 2 - Left + 1;
	if (k <= S)
		selection(arr, Left, a - 2, k);
	else if (k == S + 1)
		return arr[a - 1];
	else
		selection(arr, a, Right, k - S - 1);
}

int main() {
	int arr[10] = { 14, 21, 1, 9, 31, 3, 22, 41, 99, 33 };
	cout << "Á¤·Ä Àü : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
	cout << selection(arr, 0, 9, 3);
	
}