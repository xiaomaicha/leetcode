
//
// Created by Administrator on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool equal(float a, float b) {
  return fabs(a - b) < 0.0000001;
}

int func(float x, float d) {
  float res = sqrt((x * x - 1) / d);
  if (equal(floor(res), res)) {
    return floor(res);
  }
  if (equal(ceil(res), res)) {
    return ceil(res);
  }
  return -1;
}

int main() {
  int d, k;
  cin >> d >> k;

  int curr_k = 0;
  int x = 2;
  vector<vector<int>> res;
  res.push_back(vector<int>{1,0});
  while (curr_k < k) {
    int y = func(x, d);
    if (y == -1){
      x++;
      continue;
    }
    else {
      res.push_back(vector<int>{x, y});
      curr_k++;
    }
    x++;
  }
  int board = 0;
  for (auto &xy : res) {
    for (int i = 0; i < 2; ++i) {
      cout << xy[i] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < res.size() - 1; ++i) {
    board += res[i+1][0] - res[i][0];
    board += res[i+1][1] - res[i][1];
    board -= 1;
  }
  cout<<board<<endl;

  return 0;
}