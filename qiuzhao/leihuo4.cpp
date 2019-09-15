
//
// Created by Administrator on 2019/9/15.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//void diff_per(int level, int w, int h, unordered_set<int>  pre_end, int curr_end){
//
//}

long jie(long n){
  long res;
  if(n == 1)
    return 1;
  res = n * jie(n - 1);
}

long diff_per(int w, int h){
//  vector<vector<long >> board(h, vector<long >(w, 0));
  vector<vector<long> > board(w +1, {0, 0});
  board[2]= {1, jie(1)};
  board[3]= {1, jie(1)};


  for (int i = 0; i <h ; ++i) {
    for (int j = 4; j <= w; ++j) {
      if(i == 0){
        board[j][0] = board[j - 2][0] + 1;
        board[j][1] = board[j - 2][1] * board[j][0];
      }
      else{
        board[j][1] = board[j][1] * (board[j][1] - 1);
      }
    }
  }
  return board[w][1];
}

int main(){
  int w, h;
  int res = diff_per(9, 5);
  cout<<res<<endl;
  return 0;
}