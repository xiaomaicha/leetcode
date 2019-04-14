//
// Created by Administrator on 2019/4/14.
//


#include <iostream>
using namespace std;


int main()
{

    int i=5;
    int j=6;
    int &r=i;
    void *pi,*pj;
    int *addr;
    int dis;
    pi=&i;
    cout<<pi<<endl;//i的地址
    pj=&j;
    cout<<pj<<endl;//j的地址
    dis=(int)pj-(int)pi;//地址差
    cout<<dis<<endl;
    addr=(int *)((int)pj-dis);//获得引用底层const指针，即lambda的地址
    (*addr)+=dis;//将r由指向i转向指向j
    r=10;
    cout<<i<<" "<<j<<endl;

}

//#include <time.h>
//#include <stdio.h>

//// 用自定义函数对象排序
//struct {
//    bool operator()(int a, int b) const
//    {
//        return a < b;
//    }
//} customgreater;
//


//    // // 使用 std::chrono 来给算法计时
//    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
//    clock_t start = clock();


//    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
//    chrono::duration<double> time_used =
//            chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//   cout<<"process time(chrono):" << time_used.count()*1000 << "ms"<<endl;
//
//    clock_t stop=clock();
//    double duration=(double)(stop-start)/CLK_TCK;
//    cout<<"clock time:"<<duration*1000<<"ms"<<endl;