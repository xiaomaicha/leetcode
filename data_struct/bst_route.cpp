//
// Created by Administrator on 2019/9/1.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int tree_route_core(TreeNode *root, int &res) {
  if (!root) {
    return 0;
  }
  int left, right;
  left = max(tree_route_core(root->left, res), 0);
  right = max(tree_route_core(root->right, res), 0);
  res = max(res, root->val + left + right);
  return max(left, right) + root->val;
}

int tree_route(TreeNode *root) {
  int res = INT32_MIN;
  tree_route_core(root, res);
  return res;
}

void max_depth(TreeNode *root, int &depth) {
  if (!root) {
    depth = 0;
    return;
  }
  int left;
  int right;
  max_depth(root->left, left);
  max_depth(root->right, right);
  depth = max(left, right) + 1;
}
bool is_balance_tree(TreeNode *root, int &depth) {
  if (!root) {
    depth = 0;
    return true;
  }

  int left, right;
  bool b_left, b_right;
  b_left = is_balance_tree(root->left, left);
  b_right = is_balance_tree(root->right, right);

  if (b_left && b_right) {
    if (abs(left - right) <= 1) {
      depth = 1 + ((left > right) ? left : right);
      return true;
    }
  }
  return false;
}

void print_bst(TreeNode *root) {
  queue<TreeNode *> bst;
  bst.push(root);

  int next_level = 0;
  int tobe_print = 1;

  while (!bst.empty()) {
    auto temp = bst.front();
    bst.pop();
    cout << temp->val << " ";
    tobe_print--;
    if (temp->left != nullptr){
      bst.push(temp->left);
      next_level++;
    }

    if (temp->right != nullptr){
      bst.push(temp->right);
      next_level++;
    }

    if(tobe_print == 0){
      cout<<endl;
      tobe_print = next_level;
      next_level = 0;
    }
  }
}

int main() {
  TreeNode *node1 = new TreeNode(-10);
  TreeNode *node2 = new TreeNode(9);
  TreeNode *node3 = new TreeNode(20);
  TreeNode *node4 = new TreeNode(15);
  TreeNode *node5 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;
  cout<<"-----print_bst-----"<<endl;
  print_bst(node1);

  int depth;
  cout<<"-----is_balance_tree-----"<<endl;
  bool balance = is_balance_tree(node1, depth);
  cout << balance << endl;

  cout<<"-----depth-----"<<endl;
  max_depth(node1, depth);
  cout << depth << endl;

  cout<<"-----tree_route-----"<<endl;
  int res = tree_route(node1);
  cout << res << endl;
  return 0;
}