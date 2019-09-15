
//
// Created by Administrator on 2019/9/12.
//

//
// Created by Administrator on 2019/4/15.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int mindistance(const vector<int> &board, int rows, int cols) {
  if (board.empty() || rows == 0 || cols == 0)
    return 0;
  vector<int> dp(rows * cols, 0);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (i == 0 && j == 0) {
        dp[0] = board[0];
      } else if (i == 0) {
        dp[j] = dp[j - 1] + board[j];
      } else if (j == 0) {
        dp[i * cols] = dp[(i - 1) * cols] + board[i * cols];
      } else {
        dp[i * cols + j] = min(dp[i * cols + j - 1], dp[(i - 1) * cols + j]) + board[i * cols + j];
      }
    }
  }
  int res = dp[cols * rows - 1];
  return res;
}

int main() {
//  string input = "3\n"
//                 "3\n"
//                 "1 3 4\n"
//                 "2 1 2\n"
//                 "4 3 1";
//  stringstream ss(input);
//  cin.rdbuf(ss.rdbuf());
  int row, col;
  cin >> row >> col;
  vector<int> board;
  for (int i = 0; i < row * col; ++i) {
    int num;
    cin >> num;
    board.push_back(num);
  }

  int res = mindistance(board, row, col);
  cout << res << endl;
  return 0;

}