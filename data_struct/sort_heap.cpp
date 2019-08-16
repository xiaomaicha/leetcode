
//
// Created by Administrator on 2019/8/12.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int a) {
  cout << a << ",";
}

void upadjuest(vector<int> &vec) {
  int child_index = vec.size() - 1;
  int parent_index = (child_index - 1) / 2;
  int temp = vec[child_index];
  while (child_index > 0 && temp < vec[parent_index]) {
    vec[child_index] = vec[parent_index];
    child_index = parent_index;
    parent_index = (child_index - 1) / 2;
  }
  vec[child_index] = temp;
}

void downadjust(vector<int> &vec, int parent_index, int len) {
  int temp = vec[parent_index];
  int child_index = 2 * parent_index + 1;
  while (child_index < len) {
    if (child_index + 1 < len && vec[child_index + 1] < vec[child_index]) {
      ++child_index;
    }
    if (temp < vec[child_index])
      break;
    vec[parent_index] = vec[child_index];
    parent_index = child_index;
    child_index = 2 * child_index + 1;
  }
  vec[parent_index] = temp;
}

void build_heap(vector<int> &vec) {
  int len = vec.size();
  for (int i = len / 2; i >=0; --i) {
    downadjust(vec, i, len);
  }
}

void heap_sort(vector<int >& vec){
  build_heap(vec);

  for (int i = vec.size() -1; i > 0; --i) {
    int temp = vec[i];
    vec[i] = vec[0];
    vec[0] = temp;
    downadjust(vec, 0, i);
  }
}

int main() {
  vector<int> vec = {5, 8, 1, 2, 3, 6};
  build_heap(vec);
  for_each(vec.begin(), vec.end(), print);

  cout<<endl;
  heap_sort(vec);
  for_each(vec.begin(), vec.end(), print);

  cout<<endl;
  vector<int> vec_2 = {5, 8, 1, 2, 3, 6};
  make_heap(vec_2.begin(), vec_2.end(), std::greater<int>());
  for_each(vec_2.begin(), vec_2.end(), print);

  return EXIT_SUCCESS;
}