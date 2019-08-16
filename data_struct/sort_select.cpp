
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

//选择排序时间复杂度：
//1+2+3+...n-1
void select_sort(vector<int> &vec) {
  int len = vec.size();
  int min;
  for (int i = 0; i < len - 1; ++i) {
    min = i;
    for (int j = i + 1; j < len; ++j) {
      if (vec[min] > vec[j]) {
        min = j;
      }
    }
    if (i != min) {
      swap_value(vec[i], vec[min]);
    }
  }

}

int main() {
  vector<int> vec = {5, 8, 1, 2, 3, 6};
  select_sort(vec);
  for_each(vec.begin(), vec.end(), print);
  return EXIT_SUCCESS;
}