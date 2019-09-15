//
// Created by Administrator on 2019/9/12.
//

#include <unordered_set>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

using namespace std;
void split(const string& s,vector<int>& sv,const char flag = ' ') {
  sv.clear();
  istringstream iss(s);
  string temp;

  while (getline(iss, temp, flag)) {
    sv.push_back(stoi(temp));
  }
}

int main(){
  string nums;
  getline(cin,nums);
  vector<int> sv;
  split(nums, sv, ',');

  unordered_set<int> set;

  for (int i = 0; i < sv.size(); ++i) {
    if(set.find(sv[i]) == set.end()){
      set.insert(sv[i]);
    }
  }

  cout<<set.size()<<endl;
}
