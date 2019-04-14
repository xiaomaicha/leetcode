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