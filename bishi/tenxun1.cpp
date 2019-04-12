//
// Created by Administrator on 2019/4/7 0007.
//


#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

void split(int m, int k,vector<vector<int>>& num,int& res){
    int max = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> out;
        for (int a : num[i]) {
            int l = a/2;
            int r = a - l;
            out.push_back(l);
            out.push_back(r);
        }
        num.push_back(out);
    }
    auto maxPosition = max_element(num[k].begin(),num[k].end());
    max = *maxPosition;
    res = max + k;
}

int main(){
    int m,k;
    int res=0;
    cin>>m>>k;
    vector<vector<int>> num = {{m}};

    split(m,k,num,res);
    cout<<res;
    return 0;

}
