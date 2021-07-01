/* 剑指 Offer 13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？*/
# include<iostream>
# include<vector>
# include<queue>
using namespace std;

// 定义方格
struct grid {
    // 横纵坐标
    int x, y;
    // 横纵坐标数位和
    int sumX, sumY;
};

/* 查看规律，数位和相等的数都在斜率为一的同一条直线上，可行区域构成一个等腰直角三角形
    但是可行区域不一定可达，因此需要使用搜索算法，从左上角开始，移动方向为右和下（dfs或bfs）
    递推关系：对于横坐标或纵坐标，若下一个坐标为10的整数倍，则数位和-8；否则+1
    Java中已经使用了dfs，这里使用队列进行不递归的bfs*/
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
            // 访问过
            if (visited[tmp.x][tmp.y])   continue;
            // 走出范围
            if (tmp.x == m || tmp.y == n)    continue;
            // 不满足k的限制
            if (tmp.sumX + tmp.sumY > k) continue;

            // 访问
            visited[tmp.x][tmp.y] = true;
            sum++;
            // 后续节点入队
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