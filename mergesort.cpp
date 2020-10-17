#include <iostream>

using namespace std;

void mergesort(int*, int, int, int(*)(int, int));	// 합병 정렬 함수
int compare(int, int);								// 합병 정렬의 비교 콜백으로 사용할 함수

int main(void)
{
	int arr[] = { 4, 7, 2, 1, 9, 5, 10, 8, 6, 3 };	// 무작위 배열 정의
	int i, size = sizeof(arr) / sizeof(int);

	mergesort(arr, 0, size - 1, compare);			// 배열 정렬

	cout << arr[0];						// 정렬된 배열 값 출력
	for (i = 1; i < size; i++)
		cout << ", " << arr[i];
	cout << endl;

	return 0;
}

void mergesort(int* arr, int p, int q, int (*compare)(int, int))
{
	int i, j, k, t;
	int size = q - p + 1;
	int* buffer;

	if (p < q)										// 원소의 개수가 2개 이상일 경우 실행
	{
		k = (p + q) / 2;

		mergesort(arr, p, k, compare);				// arr[p]~arr[k] 에 대한 함수 재귀 호출
		mergesort(arr, k + 1, q, compare);			// arr[k+1]~arr[q] 에 대한 함수 재귀 호출

		buffer = new int[size];	// 합병을 위한 임시 배열 생성
													// arr[p]~arr[k]와 arr[k+1]~arr[q] 합병
		for (i = p, j = k + 1, t = 0; t < size; ++t)
		{
			if (!(i > k) && (j > q || compare(arr[i], arr[j]) > 0))
				buffer[t] = arr[i++];
			else
				buffer[t] = arr[j++];
		}

		for (t = 0; t < size; ++t)
			arr[p + t] = buffer[t];					// 임시 배열의 값을 배열로 복사

		delete[] buffer;
	}
}

int compare(int a, int b)
{
	return (int)(a < b);
}