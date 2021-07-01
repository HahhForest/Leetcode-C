/* ��ָ Offer 13. �����˵��˶���Χ
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ���
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�*/
# include<iostream>
# include<vector>
# include<queue>
using namespace std;

// ���巽��
struct grid {
    // ��������
    int x, y;
    // ����������λ��
    int sumX, sumY;
};

/* �鿴���ɣ���λ����ȵ�������б��Ϊһ��ͬһ��ֱ���ϣ��������򹹳�һ������ֱ��������
    ���ǿ�������һ���ɴ�����Ҫʹ�������㷨�������Ͻǿ�ʼ���ƶ�����Ϊ�Һ��£�dfs��bfs��
    ���ƹ�ϵ�����ں�����������꣬����һ������Ϊ10��������������λ��-8������+1
    Java���Ѿ�ʹ����dfs������ʹ�ö��н��в��ݹ��bfs*/
class Solution {
public:
    int movingCount(int m, int n, int k) {
        queue<grid> que;
        vector<vector<bool>> visited(m+5, vector<bool>(n+5, false));
        que.push(grid{0, 0, 0, 0});

        int sum = 0;
        while (que.size() > 0) {
            grid tmp = que.front();
            que.pop();
            // ���ʹ�
            if (visited[tmp.x][tmp.y])   continue;
            // �߳���Χ
            if (tmp.x == m || tmp.y == n)    continue;
            // ������k������
            if (tmp.sumX + tmp.sumY > k) continue;

            // ����
            visited[tmp.x][tmp.y] = true;
            sum++;
            // �����ڵ����
            que.push(grid{ tmp.x + 1, tmp.y, (tmp.x + 1) % 10 == 0 ? tmp.sumX - 8 : tmp.sumX + 1, tmp.sumY });
            que.push(grid{ tmp.x, tmp.y + 1, tmp.sumX, (tmp.y + 1) % 10 == 0 ? tmp.sumY - 8 : tmp.sumY + 1});
        }

        return sum;
    }
};

int main() {
    cout << "Hello world!" << endl;
    return 0;
}