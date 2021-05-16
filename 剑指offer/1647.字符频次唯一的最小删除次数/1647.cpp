/* 1647. �ַ�Ƶ��Ψһ����Сɾ������
����ַ��� s �� ������ ������ͬ�ַ� Ƶ�� ��ͬ��������ͳ� s �� �����ַ��� ��

����һ���ַ��� s������ʹ s ��Ϊ �����ַ��� ��Ҫɾ���� ��С �ַ�����

�ַ������ַ��� Ƶ�� �Ǹ��ַ����ַ����еĳ��ִ��������磬���ַ��� "aab" �У�'a' ��Ƶ���� 2���� 'b' ��Ƶ���� 1 ��*/
# include<iostream>
# include<set>
using namespace std;

/* ͳ��ÿ�����ֵĳ��ִ�����ʹ�ù�ϣ��洢
    ���������˴������ֹ����򽫵�ǰ��ĸ��һ��
    �Ȳ���������*/
class Solution {
public:
    int minDeletions(string& S) {
        int ascllOfa = 97;

        // ͳ��Ƶ��
        int count[26] = {0};
        for (int i = 0; i < S.size(); i++) {
            count[int(S[i]) - ascllOfa]++;
        }

        // ̰�ģ���ͷ��β����
        set<int> map;
        int totalDel = 0;
        for (int i = 0; i < 26; i++) {
            // �Ѵ����Ҳ�Ϊ0��һֱɾ��ֱ��������
            while (map.count(count[i]) != 0 && count[i] != 0) {  
                count[i]--;
                totalDel++;
            }
            // ����Ϊ0�����뼯��
            if (count[i] != 0) {
                map.insert(count[i]);
            }
        }

        return totalDel;
    }
};

int main() {
    cout << "Hello world" << endl;
}