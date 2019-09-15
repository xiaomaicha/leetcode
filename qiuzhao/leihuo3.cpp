
//
// Created by Administrator on 2019/9/15.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int judge(int a, int k) {
  for (int i = 2; i <= a; i++)
    if (a % i == 0 && k % i == 0)
      return 0;
  return 1; //最简
}
int main() {
  float n;
  cin >> n;
  float res = 1;
  for (int m = 1; m <= n; ++m) {
    float count = 1;
    for (int i = 2; i <= m; ++i) {
      count = count + judge(i, m);
    }
    res = min(res, count / m);
  }

  printf("%6f", res);
//  cout.precision(6);
//  cout<<count/n<<endl;

  return 0;
}