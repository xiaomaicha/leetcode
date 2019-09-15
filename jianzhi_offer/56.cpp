//
// Created by Administrator on 2019/4/20.
//

//数组中只出现一次的两个数字
//        一个整形数组中除了两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O（n），空间复杂度是O（1）。
//
//解题思路：
//1.注意到时间复杂度是O（n）而空间复杂度是O（1）。
//2.看到这种出现偶数次数的情况，都可以考虑使用异或进行解答，因为一个数异或它本身为0。
//3.全部数异或之后能够消除掉出现偶数次数的数字，结果为出现一次的两个数字的异或结果。这个结果必然有一位不等于0，可以根据不等于0的这位把所有数字分成两组，则每组各包含一个出现一次的数字。此时对两组数据分别进行异或，两个结果就是最后的两个数字。
//---------------------
//作者：DigitalNexus
//        来源：CSDN
//        原文：https://blog.csdn.net/m0_37950361/article/details/82118491
//版权声明：本文为博主原创文章，转载请附上博文链接！

#include <vector>
#include <iostream>
using namespace std;
void FindNumsAppearOnce(const vector<int>& data, int* num1, int *num2);
int main() {
    vector<int> data{ 1,1,2,2,3,4,4,5,5,6,6,7 };
    int num1, num2;
    FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    system("pause");
    return 0;
}
void FindNumsAppearOnce(const vector<int>& data, int* num1, int *num2) {
    if (data.size() < 2)return;
    *num1 = *num2 = 0;
    int tmp = 0;
    for (auto a : data) {
        tmp = tmp ^ a;
    }
    if (tmp == 0)return;
    int posi = 0;
    //这里进行一个判断，即posi的大小不能大于int的位数大小
    while (posi < 8*sizeof(int)) {
        if (tmp & 0x1) {
            break;
        }
        tmp = tmp >> 1;
        posi++;
    }
    int scale = 1 << posi;
    for (auto a : data) {
        if (a & scale) {
            *num1 = (*num1) ^ a;
        }
        else {
            *num2 = (*num2) ^ a;
        }
    }
}