
//
// Created by Administrator on 2019/8/16.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check_is_pop_order(const vector<int> &push, const vector<int> &pop) {
  bool possible = false;
  stack<int> stack_data;
  auto pop_iter = pop.begin();
  auto push_iter = push.begin();
  while (pop_iter != pop.end()) {
    while (stack_data.empty() || stack_data.top() != *pop_iter) {
      if (push_iter == push.end())
        break;
      stack_data.push(*push_iter++);
    }
    if (stack_data.top() != *pop_iter) {
      break;
    }
    stack_data.pop();
    pop_iter++;
  }
  if (stack_data.empty() && pop_iter == pop.end())
    possible = true;
  return possible;
}

int main() {
  vector<int> push = {1, 2, 3, 4, 5};
  vector<int> pop = {4, 3, 5, 2, 1};
  auto res = check_is_pop_order(push, pop);
  cout << "res: " << res << endl;
  return 0;
}
