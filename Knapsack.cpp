#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int knapSack(int C, int* wt, int* val, int n) {
	int K[50][50];

	for (int i = 0; i <= n; ++i)	// 배낭의 용량이 0일떄
		K[i][0] = 0;
	for (int w = 0; w <= C; ++w)
		K[0][w] = 0;				// 어떤 물건도 고려하지 않았을떄
	for (int i = 1; i <= n; ++i) {
		for (int w = 1; w <= C; ++w) {
			if (wt[i - 1] > w)
				K[i][w] = K[i - 1][w];
			else
				K[i][w] = max(K[i - 1][w], K[i - 1][w - wt[i - 1]] + val[i - 1]);
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= C; ++j) {
			cout << K[i][j] << "\t";
		}
		cout << endl;
	}

	return K[n][C];
}

int main() {
	int val[] = { 10, 40, 30, 50 };
	int wt[] = { 5, 4, 6, 3 };
	int w = 10;
	int n = sizeof(val) / sizeof(val[0]);

	cout << "최종해 : " << knapSack(w, wt, val, n) << endl;
}