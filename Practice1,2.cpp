/* ���� �� ������ */

/*
#include<iostream>
#include<random>
using namespace std;

int main() {
	// �������� ������ 1024���� ��.
	int num_of_pot = 1024;
	// ���� �迭(���ϴ� 10�� ����, 0��° ���Ϻ��� 9��° ���ϱ���)
	bool people[10] = { false, };	// ��������� false �׾����� true�� �����.
	// ������ �迭(���� �� �������� true)
	bool pot[1024] = { false, };
	
	random_device rd;
	default_random_engine dre(rd());

	pot[dre() % 1024] = true;	// 0 ~ 1023�� �� �ϳ��� �������� ���� Ž

	// �������� �� ���� 2���� ��Ģ�� �°� ����
	// ex) 0�� ������ : 0000000000 : �ƹ��� �ȸ���
	// 15�� ������ : 0000001111 : 0, 1, 2, 3 �� ����
	// 256�� ������ : 0100000000 : 8�� ����

	for (int i = 0; i < 1024; ++i) {
		int j = i;
		int k = 0;
		while (j > 0) {
			if (j % 2 == 1) {	// �ش�Ǵ� ���ϰ� ���� ����
				if (pot[i] == false) {
					//���� ���� ���̸� �ƹ��ϵ� ����
				}
				else if (pot[i] == true) {
					// ���� �� ���̸� ���
					people[k] = true;
				}
			}
			++k;
			j /= 2;
		}
	}

	// ���ϵ��� �������� ���
	for (int i = 0; i < 10; ++i) {
		cout << i << "�� ���� : ";
		if (people[i] == true)
			cout << "���" << endl;
		else
			cout << "����" << endl;
	}

	int num = 0;
	int temp = 1;
	// ���� �� �������� ��ȣ ���
	for (int i = 0; i < 10; ++i) {
		if (people[i] == true) {
			num += temp;
		}
		temp *= 2;
	}

	cout << endl << num << "�� �������� ���� ��� �ֽ��ϴ�." << endl;
}
*/

/* �ϳ��� ž */
#include<iostream>
using namespace std;

void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		cout << "���� 1�� " << from << " ���� " << to << "�� �̵�." << endl;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		cout << "���� " << n << "�� " << from << "���� " << to << "�� �ű��." << endl;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	hanoi(5, 'A', 'B', 'C');
}