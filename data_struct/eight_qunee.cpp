//
// Created by Administrator on 2019/8/29.
//

#include <iostream>
#include <vector>
#include <cstdio>
const int ROWS = 8;
const int COLS = 8;
using namespace std;

void print_chess_board(vector<vector<int>> &chess_board) {
  for (int row = 0; row < ROWS; ++row) {
    for (int col = 0; col < COLS; ++col) {
      printf("%d ", chess_board[row][col]);
    }
    cout << endl;
  }
}

bool check(vector<vector<int>> &chess_board, int row, int col) {
  for (int i = 1; i <= row; ++i) {
    if (chess_board[row - i][col] == 1)
      return false;
    if (col - i >= 0 && chess_board[row - i][col - i] == 1)
      return false;
    if (col + i <= COLS && chess_board[row - i][col + i] == 1)
      return false;
  }
  return true;
}

bool settle_qunee(vector<vector<int>> &chess_board, int row) {
  if (row == ROWS){
    print_chess_board(chess_board);
    cout<<endl;
    return true;
  }
  for (int col = 0; col < COLS; ++col) {
    if (check(chess_board, row, col)) {
      chess_board[row][col] = 1;
      if (settle_qunee(chess_board, row + 1)) {
        return true;
      } else {
        chess_board[row][col] = 0;
      }
    }
  }
  return false;
}


int main() {
  vector<vector<int>> chess_board(ROWS, vector<int>(COLS, 0));
  settle_qunee(chess_board, 0);
//  print_chess_board(chess_board);
  return 0;
}