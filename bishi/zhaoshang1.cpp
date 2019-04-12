//
// Created by Administrator on 2019/4/9 0009.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void split(const string& s,vector<int>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
}

int mul_sol(vector<int>& nums,int max_data,int n){
    int mid = n/2;
    int mid_data = nums[mid];
    int res=0;
    for (int i = 0; i < mid; ++i) {
        int data = nums[i];
        int log_data = static_cast<int>(log(mid_data / data) / log(2));
        res+=log_data;
    }
    for (int j = n-1; j > mid; --j) {
        int data = nums[j];
        int log_data = static_cast<int>(log(data/mid_data) / log(2));
        res+=log_data;
    }
    return res;
}

int div_sol(vector<int>& nums){
    int res=0;
    for(auto data:nums){
        int log_data = static_cast<int>(log(data) / log(2));
        res+=log_data;
    }
    return res;
}

int main() {
    int num;
    cin>>num;
    cin.get();
    string nums_str;
    getline(cin,nums_str);
    vector<int> nums,nums_log;
    split(nums_str, nums, ' ');
    sort(nums.begin(),nums.end());

    int max_data = 0;
    int sol_flag = 0;
    int res;
    for(auto data:nums){
        if(data%2==0){
            if(max_data<data)
                max_data = data;
        } else{
            sol_flag = 1;
            break;
        }
    }

    if(sol_flag ==0){
        res = mul_sol(nums,max_data,num);
    } else{
        res = div_sol(nums);
    }

    cout<<res<<endl;
    return 0;
}