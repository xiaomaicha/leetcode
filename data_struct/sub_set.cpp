
//
// Created by Administrator on 2019/8/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sub_set(vector<int> &set, vector<vector<int>> &res) {
  sort(set.begin(), set.end());
  for (int i = 0; i < set.size(); ++i) {
    int len = res.size();
    for (int j = 0; j < len; ++j) {
      res.push_back(res[j]);
      res.back().push_back(set[i]);
    }
  }
}

void sub_set_recursive(vector<int> &set, vector<vector<int>> &res, vector<int> &out, int pos) {
  res.push_back(out);
  for (int i = pos; i < set.size(); ++i) {
    out.push_back(set[i]);
    sub_set_recursive(set, res, out, i + 1);
    out.pop_back();
  }
};

int main() {
  vector<vector<int>> res(1);
  vector<int> set = {1, 2, 3};
  vector<int> out;
  sort(set.begin(), set.end());
  sub_set_recursive(set,res,out,0);
//  sub_set(set, res);
  for_each(res.begin(), res.end(), [](vector<int> num) {
    for_each(num.begin(), num.end(), [](int a) {
      cout << a << "";
    });
    cout << endl;
  });
  return 0;
}