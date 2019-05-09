//
// Created by Administrator on 2019/5/8 0008.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findtarget(vector<vector<int>>& matrix, int target){
    int rows = matrix.size();
    if(rows==0)
        return false;
    int cols = matrix[0].size();
    if(cols==0)
        return false;

    int i =0, j = cols - 1;
    while (i<rows && j>=0){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]>target)
            j--;
        else
            i++;
    }

    return false;
}
int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,2,8,9});
    matrix.push_back({2,4,9,12});
    matrix.push_back({4,7,10,13});
    matrix.push_back({6,8,11,15});

    bool res = findtarget(matrix,20);
    cout<<res<<endl;

//    string str = "adf";
//    cout<<int(str[4])<<endl;
//    cout<<int(*str.end());
    return 0;
}