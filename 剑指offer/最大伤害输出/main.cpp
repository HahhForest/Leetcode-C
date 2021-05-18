# include<iostream>
# include <cstdio>
# include <vector>
# include<map>
# include<algorithm>
using namespace std;

// 比较器
bool cmp(int x, int y)
{
	return x > y;
}

int main() {
	// 玩家数量
	int Q; scanf_s("%d", &Q);
	// 对每一个玩家计算并输出
	for (int i = 0; i < Q; i++) {
		// 结束时间、技能数
		int T, s;
		cin >> T >> s;
		// 时间线，指示时间点是否被使用
		bool* timeline = new bool[T];
		for (int i = 0; i < T; i++)	timeline[i] = false;
		// 存储伤害和冷却时间对应表
		map<int, int> corres;
		// 伤害表
		int* attack = new int[s];

		// 输入
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

		// 对伤害值排序
		sort(attack, attack + s, cmp);
		// 从伤害值最大的开始计算
		int ans = 0;
		for (int i = 0; i < s; i++) {
			// 找第一次释放点
			int p = i;
			while (timeline[p] == true)	p++;
			while (p < T) {
				timeline[p] = true;
				ans += attack[i];
				p += corres.find(attack[i])->second;
				while (timeline[p] == true)	p++;
			}
		}

		// 测试输出
		cout << ans << endl;
	}

	return 0;
}