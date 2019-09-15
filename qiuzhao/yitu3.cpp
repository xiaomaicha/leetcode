
//
// Created by Administrator on 2019/8/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int inv_score(int n) {
  vector<int> inv(n + 1, 1);
  int mod = 1000000007;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
  }
  return inv[n];
}

void get_expectation(int n, int level, vector<int> &res, bool flag, int sum) {
  if (level == n) {
    res.push_back(sum);
    return;
  }
  if(flag){
    get_expectation(n, level + 1, res, false, sum+1);
    get_expectation(n, level + 1, res, true, sum);
  } else{
    get_expectation(n, level + 1, res, true, sum);

  }
}

int cal_expection(const vector<int> &res, int n) {
  int sum = 0;
  for (int num:res) {
    sum += num;
  }
  int inv = inv_score(2<<n);
  int out = sum * inv;
  return out;
}

int main() {
  int n;
  cin >> n;
  vector<int> res;
  get_expectation(n, 0, res, true, 0);
  int out = cal_expection(res, n);
  return 0;
}