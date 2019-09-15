//
// Created by Administrator on 2019/9/7.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void to_binary(int num, vector<int> &binary) {
  while (num) {
    if (num & 1) {
      binary.push_back(1);
    } else {
      binary.push_back(0);
    }
    num = num >> 1;
  }
}

bool huiwen(vector<int > &binary){
  int len = binary.size();
  vector<int> reverse(len, 0);
  for (int i = 0; i < len; ++i) {
    reverse[i] = binary[len - 1 - i];
  }
  for (int j = 0; j < len; ++j) {
    if(binary[j] != reverse[j]){
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  vector<int> nums;
  for (int i = 0; i < t; ++i) {
    int a;
    cin>>a;
    nums.push_back(a);
  }
  for(auto num :nums){
    vector<int> binary;
    to_binary(num, binary);
    bool res = huiwen(binary);
    if(res)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}