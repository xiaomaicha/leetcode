
//
// Created by Administrator on 2019/8/27.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void split(const string &s, vector<int> &sv, const char flag = ' ') {
  sv.clear();
  istringstream iss(s);
  string temp;

  while (getline(iss, temp, flag)) {
    sv.push_back(stoi(temp));
  }
}

void cal_gemstone(vector<int> &numa, vector<int> &numb, int total, int cost, int n, int &res) {
  auto sum_a = 0, sum_b = 0;
  int cur_num = 0, cur_cost = 0;
  int total_sum = 2 * n, last_sum = total_sum;
  while (sum_a < n && sum_b < n && (last_sum + cost) < (total - cur_cost)) {
    while (numa[sum_a] != numb[sum_b]) {
      sum_a++;
    }
    cur_cost += cost;
    res++;
    sum_a++;
    sum_b++;
    cur_num = sum_a + sum_b;
    last_sum = total_sum - cur_num;
  }
  cout << last_sum << endl;
}

int main() {
//  string str = "5 10000 1000\n"
//               "1 5 4 2 3\n"
//               "5 4 3 2 1";
//  stringstream ss(str);
//  cin.rdbuf(ss.rdbuf());
  int n, total, cost;
  cin >> n >> total >> cost;
  vector<int> numa, numb;

  string vec_word;
  cin.get();
  getline(cin, vec_word);
  split(vec_word, numa, ' ');
  getline(cin, vec_word);
  split(vec_word, numb, ' ');

  int res = 0;
  cal_gemstone(numa, numb, total, cost, n, res);
  cout << res << endl;
  return 0;
}