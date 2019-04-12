//
// Created by Administrator on 2019/4/7 0007.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using  namespace std;

int main(){
    cout<<INT32_MAX;
    vector<vector<int> > res(1);
//    cout<<INT16_MAX;
    int n,k;
    cin>>n>>k;
    vector<int> num;
    for (int i = 0; i < n; ++i) {
        int a;cin>>a;
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    for (int i = 0; i < k; ++i) {
        int min =0;
        while (num[min]==0&&min<num.size()-1)
        {
            min++;
        }
        cout<<num[min]<<endl;
        int first = num[min];
        for (int j = min; j < num.size(); ++j) {
            num[j] = num[j] - first;
        }
    }
    return 0;
}

