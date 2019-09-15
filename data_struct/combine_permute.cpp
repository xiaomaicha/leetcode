//
// Created by Administrator on 2019/8/17.
//

#include <iostream>
#include <vector>

using namespace std;

//combine c(n,k)
void helper(int n, int k, int level, vector<int> &out, vector<vector<int>> &res) {
  if (out.size() == k) {
    res.push_back(out);
    return;
  }
  for (int i = level; i <= n; ++i) {
    out.push_back(i);
    helper(n, k, i + 1, out, res); // 这里其实就强制了组合只有一种顺序，也就是从前往后的顺序、
    // 如果是排列的话，每次递归的循环可以从头开始
    out.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> res;
  vector<int> out;
  helper(n, k, 1, out, res);
  return res;
}

//permute a(n,k)
void permuteDFS(vector<int> &num, int k, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &res) {
  if (level == k) {
    res.push_back(out);
    return;
  }
  for (int i = 0; i < num.size(); ++i) {
    if (visited[i] == 1)
      continue;
    visited[i] = 1;
    out.push_back(num[i]);
    permuteDFS(num, k, level + 1, visited, out, res);
    out.pop_back();
    visited[i] = 0;
  }
}

vector<vector<int>> permute(vector<int> &num, int k) {
  vector<vector<int>> res;
  vector<int> out, visited(num.size(), 0);
  permuteDFS(num, k, 0, visited, out, res);
  return res;
}

int main() {
  auto res = combine(4, 2);
  vector<int> vec = {1, 2, 3, 4};
  res = permute(vec, 2);
  return 0;
}
