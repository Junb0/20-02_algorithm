#include<iostream>
#include<random>
#include<vector>
#include<math.h>

#define DIST(a, b) sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))

using namespace std;

random_device rd;
default_random_engine dre(rd());
uniform_real_distribution<>urd(0.0f, 300.0f);

class Point {
public:
	float x = urd(dre);
	float y = urd(dre);
};

void Swap(vector<Point>& arr, int a, int b) {
	float tmp;
	tmp = arr[a].x;
	arr[a].x = arr[b].x;
	arr[b].x = tmp;
}

void quickSort(vector<Point>& arr, int Left, int Right) {
	int p = (Left + Right) / 2;
	int a = Left + 1;
	int b = a;
	while (b <= Right) {
		if (arr[b].x < arr[Left].x) {
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

pair<Point, Point> closetPairCenter(vector<Point> SCL, vector<Point> SCR) {
	pair<Point, Point> minPair{SCL.front(), SCR.front()};
	for(int i = 0; i < SCL.size(); ++i)
		for (int j = 0; j < SCR.size(); ++j) {
			if (DIST(SCL[i], SCR[j]) < DIST(minPair.first, minPair.second))
				minPair = { SCL[i], SCR[j] };
		}
	return minPair;
}

pair<Point,Point> closetPair(vector<Point> S) {
	if (S.size() <= 3) {
		if (S.size() == 2)
			return { S[0], S[1] };
		else {
			pair<Point, Point> minPair{ S[0], S[1] };
			if (DIST(S[0], S[2]) < DIST(minPair.first, minPair.second))
				minPair = { S[0], S[2] };
			if (DIST(S[1], S[2]) < DIST(minPair.first, minPair.second))
				minPair = { S[1], S[2] };
			return minPair;
		}
	}

	vector<Point> SL;
	vector<Point> SR;
	if (S.size() % 2 == 1) {	// S의 크기가 홀수일때
		for (int i = 0; i < S.size() / 2 + 1; ++i)
			SL.push_back(S[i]);
		for (int i = S.size() / 2 + 1; i < S.size(); ++i)
			SR.push_back(S[i]);
	}
	else {						// S의 크기가 짝수일때
		for (int i = 0; i < S.size() / 2; ++i)
			SL.push_back(S[i]);
		for (int i = S.size() / 2; i < S.size(); ++i)
			SR.push_back(S[i]);
	}

	pair<Point, Point> CPL{ closetPair(SL) };	// SL중의 최근접쌍
	pair<Point, Point> CPR{ closetPair(SR) };	// SR중의 최근접쌍

	float d;
	if (DIST(CPL.first, CPL.second) < DIST(CPR.first, CPR.second))
		d = DIST(CPL.first, CPL.second);
	else
		d = DIST(CPR.first, CPR.second);

	vector<Point> SCL, SCR;

	if (S.size() % 2 == 1) {
		for (int i = 0; i < S.size() / 2 + 1; ++i)
			if (S[i].x >= S[S.size() / 2 + 1].x - d && S[i].x <= S[S.size() / 2 + 1].x + d)
				SCL.push_back(S[i]);
		for (int i = S.size() / 2 + 1; i < S.size(); ++i)
			if (S[i].x >= S[S.size() / 2 + 1].x - d && S[i].x <= S[S.size() / 2 + 1].x + d)
				SCR.push_back(S[i]);
	}
	else {
		for (int i = 0; i < S.size() / 2; ++i)
			if (S[i].x >= S[S.size() / 2].x - d && S[i].x <= S[S.size() / 2].x + d)
				SCL.push_back(S[i]);
		for (int i = S.size() / 2; i < S.size(); ++i)
			if (S[i].x >= S[S.size() / 2].x - d && S[i].x <= S[S.size() / 2].x + d)
				SCR.push_back(S[i]);
	}

	pair<Point, Point> CPC{closetPairCenter(SCL, SCR)};

	if (DIST(CPL.first, CPL.second) < DIST(CPR.first, CPR.second)) {
		if (DIST(CPL.first, CPL.second) < DIST(CPC.first, CPC.second))
			return CPL;
		else
			return CPC;
	}
	else {
		if (DIST(CPR.first, CPR.second) < DIST(CPC.first, CPC.second))
			return CPR;
		else
			return CPC;
	}
}

int main() {
	vector<Point> points(10);
	quickSort(points, 0, 9);

	for(Point p : points)
		cout << "(x : " << p.x << ", y : " << p.y << ")" << endl;

	pair<Point, Point> CP{ closetPair(points) };

	cout << "최근접 쌍 : (" << CP.first.x << ", " << CP.first.y << ") , (" << CP.second.x << ", " << CP.second.y << ")" << endl;
	cout << "dist : " << DIST(CP.first, CP.second) << endl;
}