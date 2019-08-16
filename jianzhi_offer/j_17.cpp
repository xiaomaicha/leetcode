//
// Created by Administrator on 2019/8/16.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

void print_res(const string &res) {
  bool is_begain = true;
  int len = res.size();
  for (int i = 0; i < len; ++i) {
    if (is_begain && res[i] != '0')
      is_begain = false;
    if (!is_begain) {
      printf("%c", res[i]);
//      cout << res[i];
    }
  }
  printf("\n");
}

void print_maxof_n_digits_recursive(string &res, int len, int index) {
  if (index == len) {
    print_res(res);
    return;
  }
  for (int i = 0; i < 10; ++i) {
    res[index] = i + '0';
    print_maxof_n_digits_recursive(res, len, index + 1);
  }
}

void print_maxof_n_digits(int n) {
  if (n == 0)
    return;
  string res(n, '0');
  print_maxof_n_digits_recursive(res, n, 0);
}

int main() {
  print_maxof_n_digits(3);
  return 0;
}