
//
// Created by Administrator on 2019/8/28.
//

#include <iostream>
#include <vector>

using namespace std;

void array_spilit(vector<int> &num, vector<int> &out, vector<vector<int>> &res, int level) {
  if (level == num.size()) {
    res.push_back(out);
    return;
  }

  for (int i = level; i < num.size(); ++i) {
    out.push_back(i);
    array_spilit(num, out, res, i + 1);
    out.pop_back();
  }
}

vector<int> diffWaysToCompute(string input) {
  vector<int> res;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
      vector<int> left = diffWaysToCompute(input.substr(0, i));
      vector<int> right = diffWaysToCompute(input.substr(i + 1));
      for (int j = 0; j < left.size(); ++j) {
        for (int k = 0; k < right.size(); ++k) {
          if (input[i] == '+')
            res.push_back(left[j] + right[k]);
          else if (input[i] == '-')
            res.push_back(left[j] - right[k]);
          else
            res.push_back(left[j] * right[k]);
        }
      }
    }
  }
  if (res.empty())
    res.push_back(stoi(input));
  return res;
}

int main() {
  vector<int> num = {1, 2, 3, 4};
  vector<int> out;
  vector<vector<int>> res;
  return 0;
}