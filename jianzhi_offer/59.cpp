//
// Created by Administrator on 2019/4/25 0025.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxinwindows(vector<int>& data, int size){
    vector<int> res;
    if(data.size()>=size && size>=1){
        deque<int> windows;
        for (int i = 0; i < size; ++i) {
            while (!windows.empty() && data[i]>data[windows.back()]){
                windows.pop_back();
            }
            windows.push_back(i);
        }
        res.push_back(data[windows.front()]);
        for (int i = size; i < data.size(); ++i) {
            while (!windows.empty() && data[i]>data[windows.back()]){
                windows.pop_back();
            }
            if(!windows.empty() && windows.front()<= static_cast<int>(i-size)){
                windows.pop_front();
            }
            windows.push_back(i);
            res.push_back(data[windows.front()]);
        }
    }
    return res;
}

vector<int> maxinwindows_2(vector<int>& data, int size){
  vector<int> max_in_windows;
  if(data.size() >=size &&size >=1){
    deque<int> index;
    for (int i = 0; i < size; ++i) {
      while (!index.empty() && data[i] > data[index.back()])
        index.pop_back();
      index.push_back(i);
    }
    for (int i = size; i < data.size(); ++i) {
      max_in_windows.push_back(data[index.front()]);
      while (!index.empty() && data[i] > data[index.back()])
        index.pop_back();
      if(!index.empty() && index.front() <= (i -size))
        index.pop_front();
      index.push_back(i);
    }
    max_in_windows.push_back(data[index.front()]);
  }
  return max_in_windows;
}

int main(){
    vector<int> data = {2,3,4,2,6,2,5,1};
    auto res = maxinwindows_2(data, 3);
    cout<<endl;
    return 0;
}