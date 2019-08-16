
//
// Created by Administrator on 2019/8/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <csignal>
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

void handle(int) {
  cout << "exit" << endl;
}

int partition(vector<int> &vec, int low, int high) {
  int pivotkey = vec.at(low);
  while (low < high) {
    while (low < high && vec.at(high) >= pivotkey) {
      --high;
    }
    vec.at(low) = vec.at(high);
    while (low < high && vec.at(low) <= pivotkey) {
      ++low;
    }
    vec.at(high) = vec.at(low);
  }
  vec.at(low) = pivotkey;
  return low;
}

int partition_2(vector<int> &vec, int low, int high) {
  swap_value(vec[low], vec[high]);
  int small = low - 1;
  for (int index = low; index < high; ++index) {
    if (vec[index] < vec[high]) {
      ++small;
      if (index != small) {
        swap_value(vec[index], vec[small]);
      }
    }
  }
  ++small;
  swap_value(vec[small], vec[high]);
  return small;
}

void quick_sort(vector<int> &vec, int low, int high) {
  if (low < high) {
    int par = partition_2(vec, low, high);
    quick_sort(vec, low, par - 1);
    quick_sort(vec, par + 1, high);
  }
}

int main() {
  signal(SIGINT, handle);
  vector<int> vec = {5, 8, 1, 2, 3, 6, 0};
  quick_sort(vec, 0, vec.size() - 1);
  for_each(vec.begin(), vec.end(), print);
  return EXIT_SUCCESS;
}