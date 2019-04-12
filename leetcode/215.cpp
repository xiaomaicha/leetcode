//
// Created by Administrator on 2019/4/2 0002.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res;
        int left = 0, right = nums.size() - 1;
        res = quicksort(nums, left, right, k-1);
        return res;
    }

    int quicksort(vector<int>& nums, int left, int right, int k){
        int par =  findpartion(nums, left, right);;
        if(par == k)
            return nums[par];
        else if(par<k)
            quicksort(nums, par+1, right, k);
        else if(par>k)
            quicksort(nums, left, par-1, k);
    }

    int findpartion(vector<int>& nums, int left, int right){
        int par = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] <=par)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] >= par)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = par;
        return left;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int res = solution.findKthLargest(nums, 4);
    return 0;
}