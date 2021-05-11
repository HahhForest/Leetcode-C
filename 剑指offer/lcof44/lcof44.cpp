/* 剑指 Offer 44. 数字序列中某一位的数字
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等
请写一个函数，求任意第n位对应的数字。*/
# include<iostream>
using namespace std;

int main() {
    cout << 5.0 / 3 << endl;
}

/* 找规律
    一位数1~9共9个，起始为1，每个数字位数为1，共1*9*1 = 9位
    二位数10~99共90个，起始为10，每个数字位数为2，共2*9*10 = 180位
    三位数100~999共900个，起始为100，每个数字位数为3，共3 * 9*100 = 2700位
    因此思路分三步走：先找到是几位数，再找到是哪一个数字内部，最后看是这个数字内部第几位·*/
class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;

        int num = n;
        // 找是几位数，循环结束后digit指示为几位数，num指示在这位数中的第几位，从1开始
        // 如num=10，结束后digit=2，num=1，即二位数中第一位，为1
        int digit = 1;  // 位数
        long int start = 1;  // 这位数起始数字，使用long int防止计算countThisDigit时int运算溢出
        long int countThisDigit = digit * 9 * start; // 这位数的总数量，使用long int，int存不下
        while (num > countThisDigit) {
            num -= countThisDigit;
            digit++;
            start *= 10;
            countThisDigit = digit * 9 * start;
        }
        
        // 找在此位数中属于哪个数字
        // 每个数字digit位，因此在start+(num-1)/digit
        int thisNum = start + (num - 1) / digit;

        // 找是这个数字中的哪一位数
        // 是这个数字中的第(num-1) % digit位，从0开始
        int subTimes = digit - 1 - (num - 1) % digit;
        for (int i = 0; i < subTimes; i++) {
            thisNum /= 10;
        }
        return thisNum % 10;
    }
};