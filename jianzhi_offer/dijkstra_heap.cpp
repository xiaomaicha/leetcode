//
// Created by Administrator on 2019/4/25 0025.
//

#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class cmp{
public:
    bool operator()(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
};

bool cmp1(vector<int>a, vector<int>b){
    return a[1]>b[1];
}

int main(){
//    unordered_map<int,int> map1;
//    map1[2] = 12;
//    map1[1] = 15;
//    map1[3] = 20;

    priority_queue<vector<int>, vector<vector<int>>, cmp> queue1;
    queue1.push({1,3});
    queue1.push({2,1});
    queue1.push({3,2});

    auto res = queue1.top();

    cout<<endl;
    return 0;
}