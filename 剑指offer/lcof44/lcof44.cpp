/* ��ָ Offer 44. ����������ĳһλ������
������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵ�
��дһ���������������nλ��Ӧ�����֡�*/
# include<iostream>
using namespace std;

int main() {
    cout << 5.0 / 3 << endl;
}

/* �ҹ���
    һλ��1~9��9������ʼΪ1��ÿ������λ��Ϊ1����1*9*1 = 9λ
    ��λ��10~99��90������ʼΪ10��ÿ������λ��Ϊ2����2*9*10 = 180λ
    ��λ��100~999��900������ʼΪ100��ÿ������λ��Ϊ3����3 * 9*100 = 2700λ
    ���˼·�������ߣ����ҵ��Ǽ�λ�������ҵ�����һ�������ڲ����������������ڲ��ڼ�λ��*/
class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;

        int num = n;
        // ���Ǽ�λ����ѭ��������digitָʾΪ��λ����numָʾ����λ���еĵڼ�λ����1��ʼ
        // ��num=10��������digit=2��num=1������λ���е�һλ��Ϊ1
        int digit = 1;  // λ��
        long int start = 1;  // ��λ����ʼ���֣�ʹ��long int��ֹ����countThisDigitʱint�������
        long int countThisDigit = digit * 9 * start; // ��λ������������ʹ��long int��int�治��
        while (num > countThisDigit) {
            num -= countThisDigit;
            digit++;
            start *= 10;
            countThisDigit = digit * 9 * start;
        }
        
        // ���ڴ�λ���������ĸ�����
        // ÿ������digitλ�������start+(num-1)/digit
        int thisNum = start + (num - 1) / digit;

        // ������������е���һλ��
        // ����������еĵ�(num-1) % digitλ����0��ʼ
        int subTimes = digit - 1 - (num - 1) % digit;
        for (int i = 0; i < subTimes; i++) {
            thisNum /= 10;
        }
        return thisNum % 10;
    }
};