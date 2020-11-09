#include<iostream>
#define N 16
using namespace std;

void heapify(int A[], int k, int n) {
	int left = 2 * k;
	int right = 2 * k + 1;
	int smaller = -1;
	if (right <= n) {
		if (A[left] < A[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
		smaller = left;
	else
		return;
	if (A[smaller] < A[k]) {
		int tmp = A[k];
		A[k] = A[smaller];
		A[smaller] = tmp;

		heapify(A, smaller, n);	
	}
}

void buildHeap(int A[], int n) {
	for (int i = n / 2; i >= 1; --i) {
		heapify(A, i, n);
	}
}

void heapSort(int A[], int n) {
	buildHeap(A, n);
	for (int i = n; i >= 2; --i) {
		int tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;
		heapify(A, 1, i - 1);
	}
}

int main() {
	int arr[N] = { 0, 175, 130, 838, 457, 897, 345, 878, 802, 163, 743, 508, 593, 729, 68, 148 };
	cout << "정렬 전 : ";
	for (int i = 1; i < N; ++i)
		cout << arr[i] << " ";
	cout << endl;
	heapSort(arr, N);
	cout << "정렬 후 : ";
	for (int i = 1; i < N; ++i)
		cout << arr[i] << " ";
	cout << endl;
}