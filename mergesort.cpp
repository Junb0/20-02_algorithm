#include <iostream>

using namespace std;

void mergesort(int*, int, int, int(*)(int, int));	// �պ� ���� �Լ�
int compare(int, int);								// �պ� ������ �� �ݹ����� ����� �Լ�

int main(void)
{
	int arr[] = { 4, 7, 2, 1, 9, 5, 10, 8, 6, 3 };	// ������ �迭 ����
	int i, size = sizeof(arr) / sizeof(int);

	mergesort(arr, 0, size - 1, compare);			// �迭 ����

	cout << arr[0];						// ���ĵ� �迭 �� ���
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

	if (p < q)										// ������ ������ 2�� �̻��� ��� ����
	{
		k = (p + q) / 2;

		mergesort(arr, p, k, compare);				// arr[p]~arr[k] �� ���� �Լ� ��� ȣ��
		mergesort(arr, k + 1, q, compare);			// arr[k+1]~arr[q] �� ���� �Լ� ��� ȣ��

		buffer = new int[size];	// �պ��� ���� �ӽ� �迭 ����
													// arr[p]~arr[k]�� arr[k+1]~arr[q] �պ�
		for (i = p, j = k + 1, t = 0; t < size; ++t)
		{
			if (!(i > k) && (j > q || compare(arr[i], arr[j]) > 0))
				buffer[t] = arr[i++];
			else
				buffer[t] = arr[j++];
		}

		for (t = 0; t < size; ++t)
			arr[p + t] = buffer[t];					// �ӽ� �迭�� ���� �迭�� ����

		delete[] buffer;
	}
}

int compare(int a, int b)
{
	return (int)(a < b);
}