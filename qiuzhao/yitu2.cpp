//
// Created by Administrator on 2019/8/23.
//

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void dice_permute(vector<vector<int>> &dice, int level, int n, int &res, int k, int sum) {
  if (sum == k && level == n) {
    res++;
    return;
  } else if (sum == k || level == n) {
    return;
  }
  for (int i = 0; i < 6; ++i) {
    if (sum + dice[level][i] <= k) {
      dice_permute(dice, level + 1, n, res, k, sum + dice[level][i]);
    }
  }
}

int main() {
//  string input = "2 7\n"
//                 "1 2 3 4 5 6\n"
//                 "1 2 3 4 5 6";
//  stringstream ss(input);
//  cin.rdbuf(ss.rdbuf());
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dice(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      int num;
      cin >> num;
      dice[i].push_back(num);
    }
  }
  int res = 0;
  dice_permute(dice, 0, n, res, k, 0);
  cout<<res<<endl;
  return 0;
}