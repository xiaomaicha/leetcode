//
// Created by Administrator on 2019/4/8 0008.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//int main(){
//    int a;
//    vector<int> nums;
//    while (cin.get() !='\n')
//    {
//        cin>>a;
//        nums.push_back(a);
//    }
//
//    int size = nums.size();
//
//    int res = INT32_MAX,cursum = 0;
//    int left,right;
//    for(int num:nums)
//    {
//        cursum = min(cursum+num,num);
//        res = min(res,cursum);
//    }
//
//    cout<<res;
//    return 0;
//
//}

int sol(vector<int>& num)
{
    if(num.size()<=1)
        return 1;
    int nondecnum = 0;
    for (auto iter = num.begin()+1; iter!=num.end(); iter++)
    {
        if (*iter<*(iter-1))
            nondecnum+=1;
        if (nondecnum>=2)
            return 0;
    }
    return 1;
}
int main()
{   int a;
    vector<int> num;

    do {
        cin>>a;
        num.push_back(a);
    }while (getchar() !='\n');

    int res = sol(num);
    cout<<res;
    return 0;
}