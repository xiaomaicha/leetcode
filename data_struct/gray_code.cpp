
//
// Created by Administrator on 2019/8/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void grap_code(int n, vector<int> &res){
  for (int i = 0; i < n; ++i) {
    int size = res.size();
    for (int j = size - 1; j >=0 ; --j) {
      res.push_back(res[j] | 1<<i);
    }
  }
}

int main(){
  vector<int> res(1,0);
  grap_code(2, res);
  for_each(res.begin(), res.end(), [](int a){
    cout<<a<<" ";
  });
  return 0;
}