
//
// Created by Administrator on 2019/8/22.
//

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void div_package(string &pack, vector<int> &res) {
  unordered_map<char, vector<int>> hashmap_pack;
  int len = pack.size();
  for (int i = 0; i < len; ++i) {
    hashmap_pack[pack[i]].push_back(i);
  }
  int left = 0, right = 0;
  while (left < len) {
    right = hashmap_pack.at(pack[left]).back();
    for (int j = left; j <= right; ++j) {
      if (hashmap_pack.at(pack[j]).back() > right)
        right = hashmap_pack.at(pack[j]).back();
    }
    res.push_back({right - left + 1});
    left = right + 1;
  }
}

int main() {
  string package = "mpmpcpmcmdeeegdehnnhznnz";
//  cin >> package;
  vector<int> res;
  div_package(package, res);
  for_each(res.begin(), res.end(), [](int a) {
    cout << a << " ";
  });
  return 0;

}