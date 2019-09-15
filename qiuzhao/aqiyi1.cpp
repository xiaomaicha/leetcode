//
// Created by Administrator on 2019/9/8.
//

#include <iostream>
#include <vector>

using namespace std;

//permute a(n,k)
void permuteDFS(vector<int> &num,
                vector<int> &a_nums,
                vector<int> &one_nums,
                int one_index,
                int k,
                int level,
                vector<int> &visited,
                vector<int> &out,
                int out_min,
                int &res) {
  if (level == k) {
    res++;
    return;
  }

  for (int i = 0; i < num.size(); ++i) {
    if (visited[i] == 1)
      continue;
    if (level == 0) {
      visited[i] = 1;
      out.push_back(num[i]);
      permuteDFS(num, a_nums, one_nums, one_index, k, level + 1, visited, out, out_min, res);
      out.pop_back();
      visited[i] = 0;
    }
    if (level > 0 && a_nums[level - 1] == 0) {
      if (out.back() < num[i]) {
        visited[i] = 1;
        out.push_back(num[i]);
        permuteDFS(num, a_nums, one_nums, one_index + 1, k, level + 1, visited, out, num[i], res);
        out.pop_back();
        visited[i] = 0;
      }
    }
    if (level > 0 && a_nums[level - 1] == 1) {
//      if (out_min - 1 < one_nums[one_index]) {
//        return;
//      }
      if (out.back() > num[i]) {
        visited[i] = 1;
        out.push_back(num[i]);
        one_nums[one_index]--;
        permuteDFS(num, a_nums, one_nums, one_index, k, level + 1, visited, out, num[i], res);
        one_nums[one_index]++;
        out.pop_back();
        visited[i] = 0;
      }
    }
  }
}

int permute(vector<int> &num, vector<int> &a_nums, int k, vector<int> &one_nums) {
  int res = 0;
  int out_min = INT32_MAX;
  int one_index = 0;
  vector<int> out, visited(num.size(), 0);
  permuteDFS(num, a_nums, one_nums, one_index, k, 0, visited, out, out_min, res);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a_nums;
  vector<int> p_nums;
  vector<int> one_nums;
  int one_num = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a;
    cin >> a;
    if (a)
      one_num++;
    else {
      one_nums.push_back(one_num);
      one_num = 0;
    }
    a_nums.push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    p_nums.push_back(i);
  }

  int res = permute(p_nums, a_nums, n, one_nums);
  cout << res % 1000000007 << endl;
  return 0;
}