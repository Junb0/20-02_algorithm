/* 독이 든 술단지 */

/*
#include<iostream>
#include<random>
using namespace std;

int main() {
	// 술단지의 개수는 1024개로 함.
	int num_of_pot = 1024;
	// 신하 배열(신하는 10명 동원, 0번째 신하부터 9번째 신하까지)
	bool people[10] = { false, };	// 살아있으면 false 죽었으면 true로 기록함.
	// 술단지 배열(독이 든 술단지는 true)
	bool pot[1024] = { false, };
	
	random_device rd;
	default_random_engine dre(rd());

	pot[dre() % 1024] = true;	// 0 ~ 1023번 중 하나의 술단지에 독을 탐

	// 술단지에 든 술을 2진수 규칙에 맞게 마심
	// ex) 0번 술단지 : 0000000000 : 아무도 안마심
	// 15번 술단지 : 0000001111 : 0, 1, 2, 3 번 신하
	// 256번 술단지 : 0100000000 : 8번 신하

	for (int i = 0; i < 1024; ++i) {
		int j = i;
		int k = 0;
		while (j > 0) {
			if (j % 2 == 1) {	// 해당되는 신하가 술을 마심
				if (pot[i] == false) {
					//독이 없는 술이면 아무일도 없음
				}
				else if (pot[i] == true) {
					// 독이 든 술이면 사망
					people[k] = true;
				}
			}
			++k;
			j /= 2;
		}
	}

	// 신하들의 생존여부 출력
	for (int i = 0; i < 10; ++i) {
		cout << i << "번 신하 : ";
		if (people[i] == true)
			cout << "사망" << endl;
		else
			cout << "생존" << endl;
	}

	int num = 0;
	int temp = 1;
	// 독이 든 술단지의 번호 출력
	for (int i = 0; i < 10; ++i) {
		if (people[i] == true) {
			num += temp;
		}
		temp *= 2;
	}

	cout << endl << num << "번 술단지에 독이 들어 있습니다." << endl;
}
*/

/* 하노이 탑 */
#include<iostream>
using namespace std;

void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		cout << "원판 1을 " << from << " 에서 " << to << "로 이동." << endl;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		cout << "원판 " << n << "을 " << from << "에서 " << to << "로 옮긴다." << endl;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	hanoi(5, 'A', 'B', 'C');
}