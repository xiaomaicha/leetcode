
//
// Created by Administrator on 2019/9/7.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int cal_max_drink_caffee_day(vector<int> &days, int k, int m) {
  int max_caffee = m;
  if(days.empty()){
    max_caffee = 29 / (k + 1) + 2;
    return max_caffee;
  }

  int first_interval = days[0] - 1;
  int first_caffee_day = first_interval / (k + 1);
  max_caffee += first_caffee_day;

  for (int i = 1; i < days.size(); ++i) {
    int caffee_day = (days[i] - days[i - 1]) / (k + 1) - 1;
    max_caffee += caffee_day;
  }
  int last_interval = 30 - days.back();
  int last_caffee_day = last_interval / (k + 1);
  max_caffee += last_caffee_day;
  return max_caffee;
}

int main() {
  string nu ="2\n"
             "2 0\n"
             "1 15\n"
             "1 3 5 7 9 11 13 15 17 19 21 23 25 27 29";
  stringstream ss(nu);
  cin.rdbuf(ss.rdbuf());
  int t;
  cin >> t;
  vector<vector<int>> kms(t);
  vector<vector<int>> ms(t);
  for (int i = 0; i < t; ++i) {
    int k, m;
    cin >> k >> m;
    kms[i].push_back(k);
    kms[i].push_back(m);
    for (int j = 0; j < m; ++j) {
      int day;
      cin >> day;
      ms[i].push_back(day);
    }
  }

  for (int i = 0; i < t; ++i) {
    int res = cal_max_drink_caffee_day(ms[i], kms[i][0], kms[i][1]);
    cout << res << endl;
  }
  return 0;
}