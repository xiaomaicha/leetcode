
//
// Created by Administrator on 2019/8/13.
//

#include <vector>
#include <iostream>

using namespace std;

int find_reverse(vector<int> &vec, int targ) {
  int left = 0, right = vec.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (vec.at(mid) == targ)
      return mid;
    if (vec.at(mid) >= vec.at(left)) {
      //旋转点在中位数的右边
      if (vec.at(left) <= targ && targ < vec.at(mid))//中位数的左边是有序的
        right = mid - 1;
      else
        left = mid + 1;
    } else {//旋转点在中位数的左边
      if (vec.at(mid) < targ && targ <= vec.at(right))//中位数的右边是有序的
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return -1;
}

int find_reverse_postion(vector<int> &vec) {
  int left = 0, right = vec.size() - 1;
  int mid = 0;
  while (left <= right) {
    if (right - left == 1){
      mid = right;
      return mid;
    }
    mid = left + (right - left) / 2;
    if (vec[mid] >= vec[left]) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return mid;
}

int main() {
  vector<int> vec = {9, 10, 11, 12, 13, 1, 3, 4, 5, 8};
  int res = find_reverse(vec, 12);
  cout << "res: " << res << endl;
  vector<int> vec_2 = {1, 0, 1, 1, 1};
  auto resverse = find_reverse_postion(vec);
  cout << "resverse pos: " << resverse << endl;
  return EXIT_SUCCESS;
}