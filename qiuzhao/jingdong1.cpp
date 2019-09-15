//
// Created by Administrator on 2019/8/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void split_height(vector<int> &height, int left, int right, int &res) {
  if (left == right)
    return;
  while (left < right) {
    if (height[left] < height[right]) {
      left++;
    } else {
      break;
    }
  }
  if (left - 1 == right)
    return;
  res++;
  split_height(height, 0, left - 1, res);
}

int main() {
  int n;
  cin >> n;
  vector<int> height;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    height.push_back(a);
  }
  int res = 1;
  split_height(height, 0, n, res);
  cout << res << endl;
  return 0;
}