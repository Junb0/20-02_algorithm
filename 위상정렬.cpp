#include<iostream>
#include<vector>
#define N 6

using namespace std;

int Graph[N][N] = {
	{0, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0}
};

int A[N];		// 정렬된 노드들
bool T[N];		// 삭제된 노드들

int findIsolateNode() {
	bool pass;
	for (int i = 0; i < N; ++i) {
		if (T[i] == false) {
			pass = true;
			for (int j = 0; j < N; ++j) {
				if (Graph[j][i] == 1 && T[j] == false)
					pass = false;
			}
			if (pass == true)
				return i;
		}
	}
}

void topologicalSort1() {
	for (int i = 0; i < N; ++i)
		T[i] = false;

	for (int i = 0; i < N; ++i) {
		int u = findIsolateNode();
		A[i] = u;
		T[u] = true;
	}
}

int main() {
	topologicalSort1();
	for (int i = 0; i < N; ++i)
		cout << A[i] << ' ';
	cout << endl;
}