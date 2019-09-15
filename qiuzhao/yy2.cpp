//
// Created by Administrator on 2019/9/9.
//

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

struct tree {
  int val;
  tree *left;
  tree *rightt;
  explicit tree(int val) : val(val), left(nullptr), rightt(nullptr) {}
};

void midtaverse(tree *root) {
  if (root == nullptr){
    return;
  }
  midtaverse(root->left);
  cout<<root->val<<endl;
  midtaverse(root->rightt);
}

int main() {
  int n;
  cin >> n;
  int node_num = pow(2, n) - 1;
  int parent_num = pow(2, n - 1) - 1;
  vector<tree *> node;
  tree *head = new tree(-1);
  node.push_back(head);
  for (int i = 0; i < node_num; ++i) {
    int node_;
    cin >> node_;
    tree *tree_mode = new tree(node_);
    node.push_back(tree_mode);
  }

  for (int i = 1; i <= parent_num; ++i) {
    node[i]->left = node[2 * i];
    node[i]->rightt = node[2 * i +1];
  }
  midtaverse(node[1]);
  return 0;
}