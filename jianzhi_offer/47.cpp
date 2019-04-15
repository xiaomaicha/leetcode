//
// Created by Administrator on 2019/4/15.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int maxgift(const vector<int>& val, int rows, int cols){
    if(val.empty()||rows==0||cols==0)
        return 0;
    vector<int> dp(rows*cols,0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(i==0&&j==0){
                dp[0] = val[0];
            } else if(i==0){
                dp[j] = dp[j-1] + val[j];
            } else if(j==0){
                dp[i*cols] = dp[(i-1)*cols] + val[i*cols];
            } else{
                dp[i*cols + j] = max(dp[i*cols +j-1], dp[(i-1)*cols+j]) + val[i*cols+j];
            }
        }
    }
    int res = dp[cols*rows-1];
    return  res;
}


int main(){
    int val[16] = {1,10,3,100,12,2,9,6,5,7,4,11,3,7,16,5};
    vector<int> value(val,val+16);
    int res = maxgift(value,4,4);
    cout<<res<<endl;
    return 0;

}