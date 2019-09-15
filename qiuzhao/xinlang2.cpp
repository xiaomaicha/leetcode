//
// Created by Administrator on 2019/8/31.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void cal_max_set_max(vector<int> &nums, vector<int> &out, int &res, int first, int level, int m, int k) {
  int size = min(m, k + 1);
  if (out.size() == size) {
    int temp = 0;
    for (int i = 0; i < size; ++i) {
      temp += out[i];
    }
    res = max(temp, res);
    return;
  }

  for (int i = level; i < nums.size() && (i - first) <= k; ++i) {
    if (out.empty()) {
      first = i;
    }
    out.push_back(nums[i]);
    cal_max_set_max(nums, out, res, first, i + 1, m, k);
    out.pop_back();
  }
}

int main() {
  string input = "6 3 0\n"
                 "4 1 2 3 1 4";
  stringstream ss(input);
  cin.rdbuf(ss.rdbuf());
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }

  vector<int> out;
  int res = 0;
  cal_max_set_max(nums, out, res, 0, 0, m, k);
  cout << res << endl;
  return 0;

}