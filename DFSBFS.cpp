#include<iostream>
#define N 6
#define Q_MAX 100
using namespace std;

int front = -1, rear = -1;
int Queue[Q_MAX];

bool isQEmpty() {
	if (front == rear)
		return true;
	return false;
}

bool isQFull() {
	if ((rear + 1) % Q_MAX == front)
		return true;
	return false;
}

void PushQ(int n) {
	if (isQFull())
		cout << "Queue is Full" << endl;
	else {
		rear = (rear + 1) % Q_MAX;
		Queue[rear] = n;
	}
}

int PopQ() {
	if (isQEmpty())
		cout << "Queue is Empty" << endl;
	else {
		front = (front + 1) % Q_MAX;
		return Queue[front];
	}
}


int Graph[N][N] = {
	{0, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0},
	{1, 1, 0, 0, 1, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 1, 0},
};

int visited[N];

void aDFS(int v) {
	visited[v] = 1;
	cout << v + 1 << " ";
	for (int i = 0; i < N; ++i) {
		if (Graph[v][i] == 1 && visited[i] == 0)
			aDFS(i);
	}
}

void DFS() {
	for (int i = 0; i < N; ++i) {
		visited[i] = 0;
	}
	for (int i = 0; i < N; ++i)
		if (visited[i] == 0)
			aDFS(i);
}

void BFS(int s) {
	for (int i = 0; i < N; ++i)
		visited[i] = 0;
	visited[s] = 1;
	cout << s + 1 << " ";
	PushQ(s);
	while (!isQEmpty()) {
		int tmp = PopQ();
		for (int i = 0; i < N; ++i) {
			if (Graph[tmp][i] == 1) {
				if (visited[i] == 0) {
					visited[i] = 1;
					PushQ(i);
					cout << i + 1 << " ";
				}
			}
		}
	}
	
}

int main() {
	DFS();
	cout << endl;
	BFS(0);
}