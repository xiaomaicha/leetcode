//
// Created by Administrator on 2019/9/10.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
//  string str = "i am wuqi i am";
//  auto pos = str.find_first_of("am", 10);
//  cout<<(int)pos<<endl;


  string str = "# :. a:.3#b:.4#c:.9";
  stringstream sss(str);
  cin.rdbuf(sss.rdbuf());
  getline(cin, str);


//  string str;
  stringstream ss(str);

  vector<string> lie;
  string temp;
  while (getline(ss, temp, ' ')) {
    lie.push_back(temp);
  }

  int count = 0;
  int len = lie[2].size();

  vector<vector<string>> res;
  string lie_temp;
  int left = 0;
  int right = 0;
  while ((right = lie[2].find_first_of(lie[0], left)) != string::npos) {
    lie_temp = lie[2].substr(left, right - left);
    int mid = lie_temp.find_first_of(lie[1]) + left;
    string a = lie[2].substr(left, mid - left);
    string b = lie[2].substr(mid + 1, right - mid - 1);
    vector<string> ab = {a, b};
    res.push_back(ab);
    left = right + 1;
    count++;
  }

  right = lie[2].size();
  lie_temp = lie[2].substr(left, right - left);
  int mid = lie_temp.find_first_of(lie[1]) + left;
  string a = lie[2].substr(left, mid - left);
  string b = lie[2].substr(mid + 1, right - mid - 1);
  vector<string> ab = {a, b};
  res.push_back(ab);
  count++;

  cout << count << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i][0] << " " << res[i][1] << endl;
  }
  return 0;
}