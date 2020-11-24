#include<iostream>
#define V 5
#define INF INT_MAX
using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

void floydWarshall(int graph[V][V]) {
	for (int k = 0; k < V; ++k) {
		for (int i = 0; i < V; ++i) {
			if (i != k) {
				for (int j = 0; j < V; ++j) {
					if (j != k && j != i) {
						graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
					}
				}
			}
		}
	}

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (graph[i][j] == INF)
				cout << "INF\t";
			else
				cout << graph[i][j] << '\t';
		}
		cout << endl;
	}

}

int main() {
	int graph[V][V] = {
	{0, 4, 2, 5, INF},
	{INF, 0, 1, INF, 4},
	{1, 3, 0, 1, 2},
	{-2, INF, INF, 0, 2},
	{INF, -3, 3, 1, 0}
	};

	floydWarshall(graph);
	return 0;
}