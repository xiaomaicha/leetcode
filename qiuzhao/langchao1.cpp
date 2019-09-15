//
// Created by Administrator on 2019/9/9.
//

//
// Created by Administrator on 2019/5/8 0008.
//

#include <vector>
#include <iostream>

using namespace std;

int inversepaircore(vector<int> &nums, vector<int> &tmp, int start, int end) {
  if (start == end) {
    tmp[start] = nums[start];
    return 0;
  }

  int mid = (start + end) / 2;
  int low = inversepaircore(tmp, nums, start, mid);
  int high = inversepaircore(tmp, nums, mid + 1, end);

  int i = mid, j = end, index = end;
  int cnt = 0;
  while (i >= start && j >= mid + 1) {
    if (nums[i] > nums[j]) {
      tmp[index--] = nums[i--];
      cnt += 1;
    } else {
      tmp[index--] = nums[j--];
    }
  }

  for (; i >= start; --i) {
    tmp[index--] = nums[i];
  }
  for (; j >= mid + 1; --j) {
    tmp[index--] = nums[j];
  }
  return low + high + cnt;
}

int inversepair(vector<int> &nums) {
  unsigned int size = nums.size();
  if (size <= 1)
    return 0;

  vector<int> tmp = nums;

  int res = inversepaircore(nums, tmp, 0, size - 1);
  return res;
}

int main() {
  int len;
  cin>>len;

  vector<int> nums = {4, 1, 2, 5,3};

  int res = inversepair(nums);
  cout << res << endl;
  system("pause");
  return 0;
}