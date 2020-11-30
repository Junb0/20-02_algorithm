#include<iostream>

using namespace std;

int min(int a, int b, int c) {
	if (a < b) {
		if (a < c)
			return a;
		else
			return c;
	}
	else {
		if (b < c)
			return b;
		else
			return c;
	}
}

int EditDistance(char* S, char* T, int m, int n) {
	int E[50][50];

	for (int i = 0; i <= m; ++i)
		E[i][0] = i;
	for (int i = 0; i <= n; ++i)
		E[0][i] = i;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			E[i][j] = min(E[i][j - 1] + 1, E[i - 1][j] + 1, E[i - 1][j - 1] + (S[i - 1] == T[j - 1] ? 0 : 1));

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j)
			cout << E[i][j] << ' ';
		cout << endl;
	}
	return E[m][n];
}

int main() {
	char S[] = "strong";
	char T[] = "stone";

	cout << "편집 거리 : " << EditDistance(S, T, strlen(S), strlen(T));
}
