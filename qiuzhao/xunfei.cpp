
//
// Created by Administrator on 2019/8/16.
//

#include <iostream>
#include <vector>

using namespace std;

int binary_find_recursive(vector<int> &vec, int target, int left, int right) {
  if (left == right) {
    return left;
  } else if (left > right) {
    return -1;
  }
  int mid = left + (right - left) / 2;
  if (target < vec[mid]) {
    return binary_find_recursive(vec, target, left, mid - 1);
  } else {
    return binary_find_recursive(vec, target, mid + 1, right);
  }
}

int main() {
  vector<int> vec = {2, 5, 6, 7, 9, 11, 12};
  int res = binary_find_recursive(vec, 12, 0, vec.size() - 1);
  cout<<"res: "<<res<<endl;
  return 0;
}