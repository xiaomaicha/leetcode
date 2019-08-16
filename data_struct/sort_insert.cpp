
//
// Created by Administrator on 2019/8/12.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//template <class T>
void swap_value(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(int a) {
  cout << a << ",";
}

//插入排序时间复杂度
//2+3+...+n
void insert_sort(vector<int> &vec) {
  int len = vec.size();
  for (int i = 1; i < len; ++i) {
    if (vec[i - 1] > vec[i]) {
      int temp = vec[i];
      int j;
      for (j = i - 1; vec[j] > temp && j >= 0; --j) {
        vec[j + 1] = vec[j];
      }
      vec[j + 1] = temp;
    }
  }
}

int main() {
  vector<int> vec = {5, 8, 1, 2, 3, 6};
  insert_sort(vec);
  for_each(vec.begin(), vec.end(), print);
  return EXIT_SUCCESS;
}