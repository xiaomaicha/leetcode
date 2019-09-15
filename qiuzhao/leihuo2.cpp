
//
// Created by Administrator on 2019/9/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct job {
  int deadline;
  int time;
};

bool comp(job &a, job &b) {
    return (a.deadline - a.time) < (b.deadline - b.time);
}

int main() {
  int num;
  cin >> num;

  vector<job> jobs;
  for (int i = 0; i < num; ++i) {
    int dead, cost;
    cin>>dead>>cost;
    jobs.push_back({dead, cost});
  }
  sort(jobs.begin(), jobs.end(), comp);
  int start = 0;
  int postpone = 0;
  for (int i = 0; i < num; ++i) {
    start += jobs[i].time;
    postpone += max(0, start - jobs[i].deadline);
  }
  cout << postpone << endl;
  return 0;
}

