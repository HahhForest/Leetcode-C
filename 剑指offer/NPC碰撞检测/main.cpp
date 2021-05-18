# include<iostream>
# include <cstdio>
# include <vector>
# include<map>
# include<algorithm>
using namespace std;

/* 两种情况，第一是四条边是否与圆碰撞，判断圆心与矩形中心某方向距离即可
	第二种情况，判断矩形的四个角是否在圆中，计算四角到圆心距离判断*/
int main() {
	// 输入数据
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

	// 计算
	bool isHappen = false;
	for (int i = 0; i < numNPC; i++) {
		continue;
	}

	// 返回
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