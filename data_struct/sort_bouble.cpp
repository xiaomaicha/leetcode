
//
// Created by Administrator on 2019/8/12.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//template <class T>
void swap_value(int & a, int & b){
  int temp = a;
  a = b;
  b = temp;
}

void print(int a){
  cout<<a<<",";
}

//冒泡排序时间复杂度
//1+2+3+...n-1
void bouble_sort(vector<int>& vec){
  bool flags = true;
  int len = vec.size();
  for (int i = 0; i < len && flags; ++i) {
    flags = false;
    for (int j = len - 1; j > i; --j) {
      if(vec[j-1] >vec[j]){
        swap_value(vec[j-1], vec[j]);
        flags = true;
      }}}
}

int main(){
  vector<int> vec = {5,8,1,2,3,6};
  bouble_sort(vec);
  for_each(vec.begin(), vec.end(), print);
  return EXIT_SUCCESS;
}