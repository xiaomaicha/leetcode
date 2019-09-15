
//
// Created by Administrator on 2019/9/12.
//

#include <iostream>
#include <vector>

using namespace std;

int biscuits(vector<int> &grade) {
  if (grade.empty())
    return 0;
  int res = 1, pre = 1, cnt = 0;
  for (int i = 1; i < grade.size(); ++i) {
    if (grade[i] >= grade[i - 1]) {
      if (cnt > 0) {
        res += cnt * (cnt + 1) / 2;
        if (cnt >= pre)
          res += cnt - pre + 1;
        cnt = 0;
        pre = 1;
      }
      pre = (grade[i] == grade[i - 1]) ? 1 : pre + 1;
      res += pre;
    } else {
      ++cnt;
    }
  }
  if (cnt > 0) {
    res += cnt * (cnt + 1) / 2;
    if (cnt >= pre)
      res += cnt - pre + 1;
  }
  return res;
}

int main() {
  int num;
  cin >> num;
  vector<int> grade;
  for (int i = 0; i < num; ++i) {
    int a;
    cin >> a;
    grade.push_back(a);
  }
  int res = biscuits(grade);
  cout<<res<<endl;
  return 0;
}