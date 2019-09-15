
//
// Created by Administrator on 2019/8/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uglu_num(int index) {
  if (index <= 0)
    return 0;
  if (index == 1)
    return 1;

  vector<int> ugly_num_vec;
  ugly_num_vec.push_back(1);

  int t2 = 1, t3 = 1, t5 = 1;
  int u2, u3, u5;
  while (ugly_num_vec.size() != index) {
    u2 = t2 * 2;
    u3 = t3 * 3;
    u5 = t5 * 5;

    int next_ugly = min(u2, min(u3, u5));
    ugly_num_vec.push_back(next_ugly);

    auto iter2 = upper_bound(ugly_num_vec.begin(), ugly_num_vec.end(), next_ugly / 2);
    auto iter3 = upper_bound(ugly_num_vec.begin(), ugly_num_vec.end(), next_ugly / 3);
    auto iter5 = upper_bound(ugly_num_vec.begin(), ugly_num_vec.end(), next_ugly / 5);

    if (iter2 != ugly_num_vec.begin())
      t2 = *iter2;
    else
      t2 = 1;

    if (iter3 != ugly_num_vec.begin())
      t3 = *iter3;
    else
      t3 = 1;

    if (iter5 != ugly_num_vec.begin())
      t5 = *iter5;
    else
      t5 = 1;
  }
  return ugly_num_vec[index - 1];
}

int main(){
  auto res = uglu_num(5);
  cout<<"res: "<<res <<endl;
  return 0;
}