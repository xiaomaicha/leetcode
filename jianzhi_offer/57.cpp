//
// Created by Administrator on 2019/4/25 0025.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findcontinues(int sum){
    vector<vector<int>> res;
    vector<int> middle_res;

    int low = 1,high = 2, mid = (1+sum)>>1;
    int s = low + high;
    while (low < mid){
        if(s == sum){
            middle_res.clear();
            for (int i = low; i <=high ; ++i) {
                middle_res.push_back(i);
            }
            res.push_back(middle_res);
            high++;
            s+=high;
        } else if(s < sum){
            ++high;
            s += high;
        } else{
            s-= low;
            low++;
        }
    }
    return res;
}

int main(){
    auto res = findcontinues(10);
    cout<<endl;
    return 0;
}
