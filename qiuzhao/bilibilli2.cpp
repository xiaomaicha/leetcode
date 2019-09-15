
//
// Created by Administrator on 2019/9/10.
//

//
// Created by Administrator on 2019/4/25 0025.
//
#include <iostream>
#include <vector>

using namespace std;

int findcontinues(int sum) {
  vector<vector<int>> res;
  vector<int> middle_res;
  int res_num = 0;

  int low = 1, high = 2, mid = (1 + sum) >> 1;
  int s = low + high;
  while (low < mid) {
    if (s == sum) {
      res_num++;
      high++;
      s += high;
    } else if (s < sum) {
      ++high;
      s += high;
    } else {
      s -= low;
      low++;
    }
  }
  return res_num + 1;
}

int main() {
  int num;
  cin >> num;
  auto res = findcontinues(num);
  cout<<res<<endl;
  return 0;
}
