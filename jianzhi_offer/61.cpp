//
// Created by Administrator on 2019/4/25 0025.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool iscontinuesdata(vector<int>& data){
    if(data.size()!=5)
        return false;
    sort(data.begin(), data.end());

    int zerpcnt = 0;
    for (int i = 0; i < 5; ++i) {
        if(data[i]==0)
            zerpcnt++;
    }
    int gap = 0;
    int beg = zerpcnt + 1;
    while (beg<5){
        if(data[beg] == data[beg-1])
            return false;
        gap += data[beg] - data[beg-1] - 1;
        beg++;
    }
    return zerpcnt >= gap;
}

int main(){
    vector<int> data = {1,2,3,5,0};
    auto res = iscontinuesdata(data);
    cout<<endl;
    return 0;
}