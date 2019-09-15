//
// Created by Administrator on 2019/5/8 0008.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> finddup(vector<int>&nums){
    vector<int> res;
    if(nums.empty())
        return res;

    unordered_set<int> hashmap;

    for (int& data:nums){
        if(hashmap.count(data)==0){
            hashmap.insert(data);
        } else{
            res.push_back(data);
        }
    }

    return res;

}

int main(){
    vector<int> nums = {2,1,2,3,1};
    auto res = finddup(nums);

    for (int& data:res){
        cout<<data<<" ";
    }
    return 0;
}