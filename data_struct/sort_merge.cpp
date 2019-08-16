
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

void merge_vec(vector<int> &vec, int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;

  vector<int> temp(r - l + 1);
  for (int n = l; n <= r; ++n) {
    temp[n - l] = vec[n];
  }
  for (; k <= r; ++k) {
    if (i > mid) {
      vec[k] = temp[j - l];
      ++j;
    } else if (j > r) {
      vec[k] = temp[i - l];
      i++;
    } else if (temp[i - l] < temp[j - l]) {
      vec[k] = temp[i - l];
      i++;
    } else {
      vec[k] = temp[j - l];
      ++j;
    }
  }
}

void merge_sort(vector<int> &vec, int l, int r) {
  int mid;
  if (l == r)
    return;
  else {
    mid = (l + r) / 2;
    merge_sort(vec, l, mid);
    merge_sort(vec, mid + 1, r);
    merge_vec(vec, l, mid, r);
  }
}

int main() {
  vector<int> vec = {5, 8, 1, 2, 3, 6, 0};
  int len = vec.size() - 1;
  merge_sort(vec, 0, len);
  for_each(vec.begin(), vec.end(), print);
  return EXIT_SUCCESS;
}