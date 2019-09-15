
//
// Created by Administrator on 2019/9/7.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
  int t;
  cin >> t;
  vector<int> jiedian_num;
  vector<vector<vector<int>>> bst(t, vector<vector<int>>());
  for (int i = 0; i < 2; ++i) {
    int jiedian;
    cin >> jiedian;
    jiedian_num.push_back(jiedian);
    bst[i].resize(jiedian);
    for (int j = 0; j < jiedian; ++j) {
      for (int k = 0; k < 3; ++k) {
        int a;
        cin>>a;
        bst[i][j].push_back(a);
      }
    }
    vector<TreeNode *> bst_node;
    bst.resize(jiedian);
    for (int l = 0; l < jiedian; ++l) {

    }

  }

}

//
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//using namespace std;
//void split(const string &s, vector<int> &sv, const char flag = ' ') {
//  sv.clear();
//  istringstream iss(s);
//  string temp;
//
//  while (getline(iss, temp, flag)) {
//    sv.push_back(stoi(temp));
//  }
//}
//
//int cal_min_step(vector<int> &nums) {
//  int max_first_step = nums.size() / 2;
//  int min_step = INT32_MAX;
//  for (int i = 1; i < max_first_step; ++i) {
//    int reach = i;
//    int step = 1;
//    while (reach < nums.size()) {
//      reach = reach + nums[reach];
//      step++;
//      if (reach == nums.size() - 1) {
//        min_step = min(step, min_step);
//        break;
//      }
//    }
//  }
//  return min_step;
//}
//
//int main() {
////  string nu = "7 5 9 4 2 6 8 3 5 4 3 9";
////  stringstream ss(nu);
////  cin.rdbuf(ss.rdbuf());
//  string str;
//  getline(cin, str);
//  vector<int> nums;
//  split(str, nums, ' ');
//  int res = cal_min_step(nums);
//  cout << res << endl;
//  return 0;
//}