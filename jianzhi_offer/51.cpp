//
// Created by Administrator on 2019/5/8 0008.
//

#include <vector>
#include <iostream>

using namespace std;

int inversepaircore(vector<int>& nums, vector<int>& tmp, int start, int end){
    if(start == end){
        tmp[start] = nums[start];
        return 0;
    }

    int len = (start + end)/2;
    int low = inversepaircore(tmp,nums,start,len);
    int high = inversepaircore(tmp,nums,len+1,end);

    int i = len,j  = end, index = end;
    int cnt = 0;
    while (i>=start && j>=len+1){
        if(nums[i]>nums[j]){
            tmp[index--] = nums[i--];
            cnt += j-len;
        } else{
            tmp[index--] = nums[j--];
        }
    }

    for (;i >=start ; --i) {
        tmp[index--] = nums[i];
    }
    for(; j>=len+1;--j){
        tmp[index--] = nums[j];
    }
    return low + high + cnt;
}


int inversepair(vector<int>& nums){
    unsigned int size = nums.size();
    if(size<=1)
        return 0;

    vector<int> tmp = nums;

    int res = inversepaircore(nums,tmp, 0,size-1);
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,0};

    int res = inversepair(nums);
    cout<<res<<endl;
    system("pause");
    return 0;
}