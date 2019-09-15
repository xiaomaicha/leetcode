//
// Created by Administrator on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

long long cal_res(int len, int k) {
  if (k > len) {
    return 1;
  }
  vector<int> k_nums;
  int multiple = 1;
  while (k * multiple <= len) {
    k_nums.push_back(k * multiple);
    multiple++;
  }
  long long res = 1;
  for (int i = 0; i < k_nums.size(); ++i) {
    res += (len + 1 - k_nums[i]);
  }
  return res;
}

int main() {
  string input = "3 3 \n"
                 "1 1\n"
                 "2 2 \n"
                 "5 5";
  stringstream ss(input);
  cin.rdbuf(ss.rdbuf());
  int t, k;
  cin >> t >> k;
  vector<vector<int >> intervals(t);
  int max_len = INT32_MIN;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    int max_ab = max(a, b);
    max_len = max(max_len, max_ab);
    intervals[i].push_back(a);
    intervals[i].push_back(b);
  }

  vector<long long> single_res;
  for (int i = 1; i <= max_len; ++i) {
    long long temp = cal_res(i, k);
    single_res.push_back(temp);
  }

  for (int i = 0; i < t; ++i) {
    long long res = 0;
    for (int j = intervals[i][0]; j <= intervals[i][1]; ++j) {
      res += single_res[j - 1];
    }
    res = res % 1000000007;
    cout << res << endl;
  }
  return 0;
}