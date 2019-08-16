//
// Created by Administrator on 2019/4/24 0024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool haspath(string &matrix, string &sear, int rows, int cols);
bool haspathcore(string &matrix, string &sear, int rows, int cols, int row, int col, int &pl, vector<bool> &visited);

bool haspathcore(string &matrix, string &sear, int rows, int cols, int row, int col, int &pl, vector<bool> &visited) {
  if (sear[pl] == '\0')
    return true;

  bool haspath = false;
  if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == sear[pl]
      && !visited[row * cols + col]) {
    pl++;
    visited[row * cols + col] = true;
    haspath = haspathcore(matrix, sear, rows, cols, row + 1, col, pl, visited) ||
        haspathcore(matrix, sear, rows, cols, row, col + 1, pl, visited) ||
        haspathcore(matrix, sear, rows, cols, row - 1, col, pl, visited) ||
        haspathcore(matrix, sear, rows, cols, row, col - 1, pl, visited);
    if (!haspath) {
      pl--;
      visited[row * cols + col] = false;
    }
  }
  return haspath;
}

bool haspath(string &matrix, string &sear, int rows, int cols) {
  if (matrix.size() == 0 || sear.size() == 0 || rows < 1 || cols < 1)
    return false;

  vector<bool> visited(rows * cols, false);
  int pl = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (haspathcore(matrix, sear, rows, cols, i, j, pl, visited)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string matrix = "asdfghjkl";
  string search = "asdhgfjkl";
  bool res = haspath(matrix, search, 3, 3);
  cout << res;
  return 0;
}

