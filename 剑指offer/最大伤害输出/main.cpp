# include<iostream>
# include <cstdio>
# include <vector>
# include<map>
# include<algorithm>
using namespace std;

// �Ƚ���
bool cmp(int x, int y)
{
	return x > y;
}

int main() {
	// �������
	int Q; scanf_s("%d", &Q);
	// ��ÿһ����Ҽ��㲢���
	for (int i = 0; i < Q; i++) {
		// ����ʱ�䡢������
		int T, s;
		cin >> T >> s;
		// ʱ���ߣ�ָʾʱ����Ƿ�ʹ��
		bool* timeline = new bool[T];
		for (int i = 0; i < T; i++)	timeline[i] = false;
		// �洢�˺�����ȴʱ���Ӧ��
		map<int, int> corres;
		// �˺���
		int* attack = new int[s];

		// ����
		int tmpAttack;
		for (int i = 0; i < s; i++) {
			scanf_s("%d", &tmpAttack);
			attack[i] = tmpAttack;
		}
		int tmpDelay;
		for (int i = 0; i < s; i++) {
			scanf_s("%d", &tmpDelay);
			corres.insert(pair<int, int>(attack[i], tmpDelay));
		}

		// ���˺�ֵ����
		sort(attack, attack + s, cmp);
		// ���˺�ֵ���Ŀ�ʼ����
		int ans = 0;
		for (int i = 0; i < s; i++) {
			// �ҵ�һ���ͷŵ�
			int p = i;
			while (timeline[p] == true)	p++;
			while (p < T) {
				timeline[p] = true;
				ans += attack[i];
				p += corres.find(attack[i])->second;
				while (timeline[p] == true)	p++;
			}
		}

		// �������
		cout << ans << endl;
	}

	return 0;
}