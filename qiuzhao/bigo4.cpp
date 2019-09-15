//
// Created by Administrator on 2019/8/27.
//

#include<iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
  int rows = matrix.size();
  int cols = 0;
  if (rows != 0) {
    cols = matrix[0].size();
  }
  if (rows == 0 || cols == 0)
    return;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        for (int k = 0; k < cols; k++) {
          if (matrix[i][k] != 0) {   //跳过该行中其他值为0 的元素
            //if(k!=j){
            matrix[i][k] = '*';
          }
        }
        for (int k = 0; k < rows; k++) {
          if (matrix[k][j] != 0) {
            matrix[k][j] = '*';
          }
        }
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == '*') {
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  vector<vector<int >> matrix = {{1, 2, 3, 4}, {1, 3, 0, 2}, {1, 3, 2, 1}};
  setZeroes(matrix);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}




//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//void split(const string &s, vector<int> &sv, const char flag = ' ') {
//  sv.clear();
//  istringstream iss(s);
//  string temp;
//
//  while (getline(iss, temp, flag)) {
//    sv.push_back(stoi(temp));
//  }
//}
//
//int findPeakElement(vector<int> &nums) {
//  int left = 0;
//  int right = nums.size() - 1;
//  while (left < right) {
//    int mid = (left + right) / 2;
//    if (nums[mid] > nums[mid + 1]) {
//      right = mid;
//    } else {
//      left = mid + 1;
//    }
//  }
//}
//
//int main(){
//  string vec_word;
//  getline(cin, vec_word);
//  vector<int > sv;
//  split(vec_word, sv, ' ');
//  int res = findPeakElement(sv);
//  cout<<res<<endl;
//  return 0;
//}