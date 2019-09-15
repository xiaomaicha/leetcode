//
// Created by Administrator on 2019/8/31.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int find_reversr_index(vector<int> &nums) {
  for (int i = nums.size() - 1; i > 0; --i) {
    if (nums[i - 1] < nums[i]) {
      return i;
    }
  }
  return 0;
}

void exchange_nums(vector<int> &nums, int index) {
  int head = nums[index - 1];
  for (int i = nums.size() - 1; i >= index; --i) {
    if (head < nums[i]) {
      nums[index - 1] = nums[i];
      nums[i] = head;
      break;
    }
  }
}

void reverse_nums(vector<int> &nums, int index) {
  int left = index;
  int right = nums.size() - 1;
  while (left < right) {
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
    left++;
    right--;
  }
}

bool find_nearest_number(vector<int> &nums) {
  int index = find_reversr_index(nums);
  if (index == 0) {
    return false;
  }
  exchange_nums(nums, index);
  reverse_nums(nums, index);
  return true;
}

int main() {
  vector<int> nums = {1, 2, 4, 3, 5};
  find_nearest_number(nums);
  for_each(nums.begin(), nums.end(), [](int a) {
    cout << a << "";
  });
}