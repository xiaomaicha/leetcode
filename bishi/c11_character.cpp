//
// Created by Administrator on 2019/4/26.
//

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void abssort(float *x, unsigned N)
{
    std::sort(x,
              x + N,
              [](float a, float b) { return std::abs(a) < std::abs(b); });
}

class C
{
    int a;
    int b;
public:
    C(int i, int j){};
};

class X {
    int a[4];
public:
    X() : a{1,2,3,4} {} //C++11, 初始化数组成员
};

int main(){
    float f0 = 1.0;
    std::cout << [&](float f) mutable { return f0 += std::abs(f); } (-3.5);
    std::cout << '\n' << f0 << '\n';
//    float f0 = 1.0f;
//    float f1 = 10.0f;
//    std::cout << [=, &f0](float a) { return f0 += f1 + std::abs(a); } (-3.5);
//    std::cout << '\n' << f0 << '\n';

    float f2 = 10.0f;
    cout<<[=, &f0](float a) { return f0 = f2 + a;}(3.5)<<endl;


    C c {0,0}; //C++11 only. 相当于 C c(0,0);
    int* a = new int[3] { 1, 2, 0 };


    return 0;
}