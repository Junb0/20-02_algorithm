#include<iostream>
#include<vector>
#define N 6
using namespace std; 

int check[N];

class Edge {
public:
	int LNode;
	int RNode;
	int Distance;
	Edge() {
		int LNode = -1;
		int RNode = -1;
		int Distance = -1;
	}
	Edge(int a, int b, int dist) {
		this->LNode = a;
		this->RNode = b;
		this->Distance = dist;
	}

	void Print() {
		cout << LNode << " -> " << RNode << " : " << Distance << endl;
	}
};

void Swap(vector<Edge>& arr, int a, int b) {
	Edge tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void quickSort(vector<Edge>& arr, int Left, int Right) {
	int p = (Left + Right) / 2;
	int a = Left + 1;
	int b = a;
	while (b <= Right) {
		if (arr[b].Distance < arr[Left].Distance) {
			Swap(arr, a, b);
			a++;
		}
		b++;
	}
	Swap(arr, Left, a - 1);
	if (Left < Right) {
		quickSort(arr, Left, a - 2);
		quickSort(arr, a, Right);
	}
}

void setParent() {
	for (int i = 0; i < N; ++i)
		check[i] = i;
}

int getParent(int node) {
	if (check[node] == node)
		return node;
	return getParent(check[node]);
}

void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 < node2)
		check[node2] = node1;
	else
		check[node1] = node2;
}

bool isCycle(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 == node2)
		return true;
	return false;
}

int main() {
	vector<Edge> v;
	v.push_back(Edge(1, 2, 9));
	v.push_back(Edge(1, 3, 7));
	v.push_back(Edge(1, 4, 5));
	v.push_back(Edge(1, 6, 6));
	v.push_back(Edge(2, 3, 9));
	v.push_back(Edge(3, 5, 5));
	v.push_back(Edge(4, 6, 5));
	v.push_back(Edge(5, 6, 1));

	quickSort(v, 0, v.size() - 1);

	setParent();

	for (Edge e : v)
		e.Print();
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (!isCycle(v[i].LNode, v[i].RNode)) {
			sum += v[i].Distance;
			unionParent(v[i].LNode, v[i].RNode);
		}
	}
	cout << sum << endl;
}