//
// Created by Administrator on 2019/3/31 0031.
//

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    restore(s, 4, "", res);
    return res;
  }
  void restore(string s, int k, string out, vector<string> &res) {
    if (k == 0) {
      if (s.empty())
        res.push_back(out);
    } else {
      for (int i = 1; i <= 3; ++i) {
        if (s.size() >= i && isvalid(s.substr(0, i))) {
          if (k == 1)
            restore(s.substr(i), k - 1, out + s.substr(0, i), res);
          else
            restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
        }
      }
    }
  }
  bool isvalid(string s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
      return false;
    int res = atoi(s.c_str());
    return res <= 255 && res >= 0;
  }
};

class Solution2 {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    helper(s, 0, "", res);
    return res;
  }
  void helper(string s, int n, string out, vector<string> &res) {
    if (n == 4) {
      if (s.empty())
        res.push_back(out);
    } else {
      for (int k = 1; k < 4; ++k) {
        if (s.size() < k)
          break;
        int val = atoi(s.substr(0, k).c_str());
        if (val > 255 || k != std::to_string(val).size())
          continue;
        helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
      }
    }
  }
};

static int sa = 1;

void show(){
  cout<<sa<<endl;
}

int main() {
  Solution solution;
  string s{"0000"};
  auto res = solution.restoreIpAddresses(s);

  Solution *sol = new Solution[5];

  int f = 128;
  char i = f;
  printf("%d\n",i);
  char i_ = 1;
  float f_ = i_;

  return 0;
}