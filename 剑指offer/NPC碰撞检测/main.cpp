# include<iostream>
# include <cstdio>
# include <vector>
# include<map>
# include<algorithm>
using namespace std;

/* �����������һ���������Ƿ���Բ��ײ���ж�Բ�����������ĳ������뼴��
	�ڶ���������жϾ��ε��ĸ����Ƿ���Բ�У������Ľǵ�Բ�ľ����ж�*/
int main() {
	// ��������
	int recInfo[4];
	int numNPC;
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &recInfo[i]);
	}
	scanf_s("%d", &numNPC);
	int* xLabel = new int[numNPC];
	int* yLabel = new int[numNPC];
	bool* isColap = new bool[numNPC];
	for (int i = 0; i < numNPC; i++) {
		cin >> xLabel[i] >> yLabel[i];
	}

	// ����
	bool isHappen = false;
	for (int i = 0; i < numNPC; i++) {
		continue;
	}

	// ����
	if (isHappen == false) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < numNPC; i++) {
			if (isColap[1] == true) {
				printf_s("%d ", i);
			}
		}
	}

	return 0;
}