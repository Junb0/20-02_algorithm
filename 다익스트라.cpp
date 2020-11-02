#include<iostream>
#define V 10

using namespace std;

int Graph[][V] = {
{0,15,0,12,0,0,0,0,0,0},
{15,0,21,0,0,0,7,0,0,0},
{0,21,0,0,0,0,0,25,0,0},
{12,0,0,0,4,10,0,0,0,0},
{0,0,0,4,0,3,0,0,13,0},
{0,0,0,10,3,0,10,0,0,0},
{0,7,0,0,0,10,0,19,0,9},
{0,0,25,0,0,0,19,0,0,5},
{0,0,0,0,13,0,0,0,0,15},
{0,0,0,0,0,0,9,5,15,0}
};

int D[V];		// start 정점에서 각 정점까지의 최소거리
bool T[V];		// 각 정점의 최소거리가 확정되었는지 여부

int findMin() {
	int MinDist = INT_MAX;
	int MinIdx = -1;

	for (int i = 0; i < V; ++i) {
		if (T[i] == false && D[i] < MinDist) {
			MinDist = D[i];
			MinIdx = i;
		}
	}
	return MinIdx;
}

void Update(int N) {
	for (int i = 0; i < V; ++i)
		if (T[i] == false && D[i] > D[N] + Graph[N][i] && Graph[N][i])
			D[i] = D[N] + Graph[N][i];
}

void Dijkstra(int start) {
	for (int i = 0; i < V; ++i) {
		if (Graph[start][i] == 0)
			D[i] = INT_MAX;
		else
			D[i] = Graph[start][i];
		T[i] = false;
	}
	D[start] = 0;
	T[start] = true;

	for (int i = 0; i < V - 1; ++i) {
		int N = findMin();
		T[N] = true;
		Update(N);
	}
}

int main() {
	Dijkstra(0);
	for (int i = 0; i < V; ++i) {
		cout << i << " : " << D[i] << endl;
	}
}