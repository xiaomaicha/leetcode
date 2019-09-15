//
// Created by Administrator on 2019/5/8 0008.
//

#include <iostream>
#include <vector>

using namespace std;

void gift(unsigned int gift_num,
          unsigned int child_k,
          int cur_gift,
          int cur_k,
          vector<int> &out,
          vector<vector<int>> &res) {
  if (cur_k == child_k) {
    int num = gift_num - cur_gift;
    out.push_back(num);
    res.push_back(out);
    out.pop_back();
    return;
  }

  for (int i = cur_gift; i <= gift_num; ++i) {
    int num = i - cur_gift;
    out.push_back(num);
    gift(gift_num, child_k, i, cur_k + 1, out, res);
    out.pop_back();
  }
}

void gift_1(int last_gift, int last_k, string out, vector<string> &res) {
  if (last_gift == 0 && last_k == 0) {
    res.push_back(out);
    return;
  }
  if (last_gift > 0)
    gift_1(last_gift - 1, last_k, out + '*', res);
  if (last_k > 0)
    gift_1(last_gift, last_k - 1, out + '|', res);
}

int main() {
  int n, k;
  cin >> n >> k;
  {
    vector<vector<int>> res;
    vector<int> out;

    gift(n, k, 0, 1, out, res);
    cout << res.size() << endl;

    for (int l = res.size() - 1; l >= 0; --l) {
      for (int i = 0; i < res[l].size(); ++i) {
        for (int j = 0; j < res[l][i]; ++j) {
          cout << char(42);
        }
        if (i != res[l].size() - 1) {
          cout << char(124);
        }
      }
      cout << endl;
    }
  }

  {
    string out;
    vector<string> res;
    cout << "function 2" << endl;
    gift_1(n, k - 1, out, res);
    cout << res.size() << endl;
    for (const auto &re : res) {
      cout << re << endl;
    }
  }

  return 0;
}