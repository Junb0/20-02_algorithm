#include<iostream>
#include<iomanip>

using namespace std;

int CoinChanger(int n, int* arr, int m) {
	int* C = new int[n + 1];
	for(int i = 1; i <= n; ++i)
		C[i] = INT_MAX;
	C[0] = 0;
	for (int j = 1; j <= n; ++j) {
		for (int i = 0; i < m; ++i) {
			if (arr[i] <= j && C[j - arr[i]] + 1 < C[j]) {
				C[j] = C[j - arr[i]] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << i << setw(5);
	cout << endl << setw(0);
	for (int i = 1; i <= n; ++i)
		cout << C[i] << setw(5);
	cout << endl;
	int tmp = C[n];
	delete[] C;
	return tmp;
}

int main() {
	int arr[] = { 16, 10, 5, 1 };
	int n = 20;
	int m = sizeof(arr) / sizeof(arr[0]);
	cout << endl << "동전의 수 : " << CoinChanger(n, arr, m) << endl;
	return 0;
}