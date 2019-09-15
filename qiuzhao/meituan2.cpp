//
// Created by Administrator on 2019/8/22.
//
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

void split(const string &s, vector<string> &sv, const char flag = ' ') {
  sv.clear();
  istringstream iss(s);
  string temp;

  while (getline(iss, temp, flag)) {
    sv.push_back(temp);
  }
}

string alien_order(vector<string> &vec_word) {
  set<pair<char, char>> st;
  unordered_set<char> ch;
  vector<int> in(256);
  queue<char> q;
  string res;
  for (auto a : vec_word)
    ch.insert(a.begin(), a.end());
  for (int i = 0; i < (int) vec_word.size() - 1; ++i) {
    int min_num = min(vec_word[i].size(), vec_word[i + 1].size()), j = 0;
    for (; j < min_num; ++j) {
      if (vec_word[i][j] != vec_word[i + 1][j]) {
        st.insert(make_pair(vec_word[i][j], vec_word[i + 1][j]));
        break;
      }
    }
    if (j == min_num && vec_word[i].size() > vec_word[i + 1].size())
      return "";
  }
  for (auto a : st)
    ++in[a.second];
  for (auto a : ch) {
    if (in[a] == 0) {
      q.push(a);
      res += a;
    }
  }
  while (!q.empty()) {
    char c = q.front();
    q.pop();
    for (auto a : st) {
      if (a.first == c) {
        --in[a.second];
        if (in[a.second] == 0) {
          q.push(a.second);
          res += a.second;
        }
      }
    }
  }
  return res.size() == ch.size() ? res : "";
}

int main() {
  string vec_word;
  getline(cin, vec_word);
  vector<string> sv;
  split(vec_word, sv, ' ');
  string res = alien_order(sv);
  if (res != "")
    cout << res << endl;
  else
    cout << "invalid" << endl;
  return 0;
}