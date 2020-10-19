#include<iostream>
#define N 6
#define MAXVALUE 101
using namespace std;

template<class T> class Queue
{
public:
	int front;
	int rear;
	int size;
	T* key;

	Queue()
	{
		size = N;
		key = new T[size];
		front = 0;
		rear = 0;
	}
	~Queue()
	{
		delete[] key;
	}

	bool isFull()
	{
		if ((rear + 1) % size == front)
			return true;
		else
			return false;
	}

	bool empty()
	{
		if (rear == front)
			return true;
		else
			return false;
	}

	void push(T key)
	{
		if (!isFull())
		{
			this->key[rear] = key;
			rear = (rear + 1) % size;
		}
		else
			cout << "Queue is Full" << endl;
	}

	T pop()
	{
		if (!empty()) {
			T tmp = key[front];
			front = (front + 1) % size;
			return tmp;
		}
		else
			cout << "Queue is Empty" << endl;
		return -1;
	}
};


int Graph[N][N] = {
	{0, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0},
	{1, 1, 0, 0, 1, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 1, 0},
};
int Visited[N];
Queue<int> Q;

void DFS(int s);
void aDFS(int v);
void BFS(int s);

int main() {
	int DFSs = 0;
	int BFSs = 0;
	cout << "DFS (" << DFSs + 1 << "에서 시작)" << endl;
	DFS(DFSs);
	cout << endl << endl << "BFS (" << BFSs + 1 << "에서 시작)" << endl ;
	BFS(BFSs);

}

void DFS(int s) {
	for (int i = 0; i < N; ++i) {
		Visited[i] = 0;
	}
	for (int i = s; i < N + s; ++i) {
		if (Visited[i % N] == 0)
			aDFS(i);
	}
}

void aDFS(int v) {
	Visited[v] = 1;
	cout << v + 1 << " ";
	for (int i = 0; i < N; ++i) {
		if (Graph[v][i] == 1 && Visited[i] == 0)
			aDFS(i);
	}
}

void BFS(int s) {
	int u;
	for (int i = 0; i < N; ++i) {
		Visited[i] = 0;
	}
	Visited[s] = 1;
	cout << s + 1 << " ";
	Q.push(s);
	while (!Q.empty()) {
		u = Q.pop();
		for (int i = 0; i < N; ++i) {
			if (Graph[u][i] == 1 && Visited[i] == 0) {
				Visited[i] = 1;
				cout << i + 1 << " ";
				Q.push(i);
			}
		}
	}
}