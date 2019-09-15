
//
// Created by Administrator on 2019/8/16.
//

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

using Func = function<bool(int)>;
//using f = bool (*)(int);

void swap_value(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(int n) {
  cout << n << " ";
}

bool is_even(int n) {
  return (n & 1) == 0;
}

void recorder(vector<int> &vec, const Func& func) {
  int len = vec.size();
  if (len == 0)
    return;
  int left = 0, right = len - 1;
  while (left < right) {
    while (left < right && !func(vec[left]))
      ++left;
    while (left < right && func(vec[right]))
      --right;

    if (left < right) {
      int temp = vec[left];
      vec[left] = vec[right];
      vec[right] = temp;
    }
  }
}

void recorder_2(vector<int> &vec, const Func& func) {
  int len = vec.size();
  if (len == 0)
    return;
  int small = -1;
  for (auto index = 0; index < len; ++index) {
    if (!func(vec[index])) {
      ++small;
      if (small != index) {
        swap_value(vec[index], vec[small]);
      }
    }
  }
}

int main() {
  vector<int> vec = {2, 1, 3, 5, 7, 4, 1, 6};
  recorder_2(vec, is_even);
  for_each(vec.begin(), vec.end(), print);
  return 0;
}

