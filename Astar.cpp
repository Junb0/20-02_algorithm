#include<iostream>
#define V 10
using namespace std;

int Graph[V][V] = 
{ { 0,0,0,0,20,0,0,0,0,0 },
{ 19,0,0,24,0,0,0,0,0,0 },
{ 10,30,0,0,17,23,0,25,0,0 },
{ 0,0,0,0,0,0,20,0,0,0 },
{ 0,0,0,0,0,0,0,17,0,0 },
{ 0,16,0,18,0,0,0,28,0,0 },
{ 0,0,0,0,0,0,0,0,0,40 },
{ 0,0,0,0,0,0,0,0,39,0 },
{ 0,0,0,0,0,20,28,0,0,0 },
{ 0,0,0,0,0,0,0,0,29,0 } };

int E[V] = { 61,40,52,19,68,34,0,52,19,39 };		// �� ����� ���� �ܿ��Ÿ�
int D[V];		// start �������� �� ���������� �ּҰŸ�
bool T[V];		// �� ������ �ּҰŸ��� Ȯ���Ǿ����� ����

int findMin(int N) {
	int MinDist = INT_MAX;
	int MinIdx = -1;

	for (int i = 0; i < V; ++i) {
		if (T[i] == false && Graph[N][i] != 0 ) {
			cout << "  " << "�Ÿ� ������Ʈ "<< i << ": " << D[i] << " (" << D[i] + E[i] << ")" << endl;
			if (D[i] + E[i] < MinDist) {
				MinDist = D[i] + E[i];
				MinIdx = i;
			}
		}
	}
	return MinIdx;
}

void Update(int N) {
	for (int i = 0; i < V; ++i)
		if (T[i] == false && D[i] > D[N] + Graph[N][i] && Graph[N][i])
			D[i] = D[N] + Graph[N][i];
}

void aStar(int Start, int Dest) {
	for (int i = 0; i < V; ++i) {
		if (Graph[Start][i] == 0)
			D[i] = INT_MAX;
		else
			D[i] = Graph[Start][i];
		T[i] = false;
	}
	D[Start] = 0;
	T[Start] = true;

	int N = Start;
	cout << N << " �湮 ->" << endl;
	while(true) {
		N = findMin(N);
		T[N] = true;
		cout << N << " �湮 ->" << endl;
		if (N == Dest) {
			cout << "Done!" << endl;
			return;
		}
		Update(N);
	}
}

int main() {
	aStar(2, 6);
	return 0;
}