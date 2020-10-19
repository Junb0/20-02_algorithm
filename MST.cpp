#include<iostream>
#define N 6

int parent[N];

using namespace std;

int cost[N][N] = {
	{0, 8, 2, 0, 4, 0},
	{8, 0, 4, 1, 0, 2},
	{2, 4, 0, 0, 3, 7},
	{0, 1, 0, 0, 0, 1},
	{4, 0, 3, 0, 0, 9},
	{0, 2, 7, 1, 9, 0},
};

int find_v(int i);
void union1(int i, int j);
void kruskalMST();

int main() {

}

int find_v(int i) {
	int v = i;
	while (parent[v] == v) {
		v = parent[v];
	}
	return v;
}

void kruskalMST() {

}