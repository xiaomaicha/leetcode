//
// Created by Administrator on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

bool cal_expression_core(string &str, unordered_map<string, int> &num_map, int &res){
  string left, right;
  for (int i = 0; i < str.size(); ++i) {
    if(str[i] == '='){
      left = str.substr(0,i);
      right = str.substr(i + 1);
      break;
    }
}

int cal_expression(vector<string> &num_str){
  unordered_map<string, int> num_map;
  for (int i = 0; i < num_str.size(); ++i) {

  }
}

int main(){
  int n;
  cin>>n;
  cin.get();
  vector<string> num_str(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, num_str[i]);
  }
}