//
// Created by Administrator on 2019/3/31 0031.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combination(candidates, target, 0, 0, out, res);
        return res;

    }

    void combination(vector<int>& can, int target, int k,int sum, vector<int>& out, vector<vector<int>>& res){
        if(sum>target)
            return;;
        if(sum == target)
            res.push_back(out);
        else
            for (int i = k; i < can.size(); ++i) {
                if(sum + can[i] <= target){
                    out.push_back(can[i]);
                    combination(can,target,i+1,sum+can[i],out,res);
                    out.pop_back();
                }
        }
    }
};

int main()
{
//    Solution solution;
//    vector<int> can = {2,3,6,7};
//    int target = 7;
//    auto res = solution.combinationSum(can, target);
//
//    cout<<__DATE__<<' '<<__TIME__<<endl;

    unsigned short i=0,j=0, k = 0;
    for(i=0, j=2; i!=j; i+=5, j+=7)
    {++k;}
    cout<<k<<endl;

//    unsigned short i=0,j=0,
    k = 0;
    for(i=3,j=7;i!=j;i+=3,j+=7)
    {++k;}
    cout<<k<<endl;
    return 0;
}