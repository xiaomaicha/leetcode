//
// Created by Administrator on 2019/4/11 0011.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int add(int a, int b){
    int re = a;
    while(b){
        int tmp = a;
        a = a^b;
        b = (tmp&b)<<1;        re = a;
    }
    return re;
}


int main(){

    int res = add(2,3);
//    vector<int> abc;
//    long res;
//    for (int i = 0; i < 3; ++i) {
//        int data;
//        cin>>data;
//        abc.push_back(data);
//    }
//    vector<string> abc_str;
//    for (int j = 0; j < 3; ++j) {
//        string str{'1'};
//        for (int i = 0; i < abc[j]; ++i) {
//            str.push_back('0');
//        }
//        abc_str.push_back(str);
//    }
//
//    vector<int > res_str(abc[0]+1,0);
//    int m=0,n=0;
//    for (auto it1 = abc_str[0].rbegin(); it1 != abc_str[0].rend(); it1++) {
//        for (auto it2 = abc_str[1].rbegin(); it2 != abc_str[1].rend(); it2++){
//            char a = *it1, b =*it2;
//            int tmp = (a-'0') * (b-'0') + v[i+j];
//        }
//    }
//
//
//
//
//    int a = 2<<abc[0];
//    int b = 2<<abc[1];
//    int c = 2<<abc[2];
//
//    res = a+b-c;
//    int cnt=0;
//    while(res/2!=0){
//        int mu = res%2;
//        if(mu==1)
//            cnt++;
//        res/=2;
//    }
//    if(res%2==1)
//        cnt++;
//    cout<<cnt<<endl;
    return 0;
}