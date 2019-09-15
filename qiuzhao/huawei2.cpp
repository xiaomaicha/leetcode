//
////
//// Created by Administrator on 2019/8/28.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//void fill_borad(vector<bool> &visited, vector<vector<int>> &board, int rows, int cols, int row, int col) {
//  visited[row * cols + col] = true;
//  if (row - 1 >= 0 && visited[(row - 1) * cols + col] == false)
//    board.push_back({row - 1, col});
//  if (row + 1 < rows && visited[(row + 1) * cols + col] == false)
//    board.push_back({row + 1, col});
//  if (col - 1 >= 0 && visited[row * cols + col - 1] == false)
//    board.push_back({row, col - 1});
//  if (col + 1 < cols && visited[row * cols + col + 1] == false)
//    board.push_back({row, col + 1});
//}
//
//bool check_matrix(vector<int> &matrix, vector<int> &nums, int rows, int cols, int n) {
//  bool flag = false;
//  vector<bool> visited(rows * cols, false);
//  vector<vector<int>> board;
//  int row, col;
//  bool flag_first = false;
//  for (row = 0; row < rows; ++row) {
//    if (flag_first){
//      row--;
//      break;
//    }
//    for (col = 0; col < cols; ++col) {
//      if (matrix[row * cols + col] == nums[0]) {
//        flag_first = true;
//        break;
//      }
//    }
//  }
//
//  fill_borad(visited, board, rows, cols, row, col);
//  for (int i = 1; i < 6; ++i) {
//    for (auto &axis:board) {
//      if (matrix[axis[0] * cols + axis[1]] != nums[i]) {
//        flag = false;
//        continue;
//      } else {
//        fill_borad(visited, board, rows, cols, axis[0], axis[1]);
//        flag = true;
//        break;
//      }
//    }
//    if (!flag)
//      return false;
//  }
//  return true;
//}
//
//int main() {
//  vector<int>
//      matrix = {1, 2, 3, 4, 5, 11, 12, 13, 14, 15, 21, 22, 23, 24, 25,
//                31, 32, 33, 34, 35, 41, 42, 43, 44, 45};
//  while (true) {
//    vector<int> nums;
//    for (int i = 0; i < 6; ++i) {
//      int num;
//      cin >> num;
//      nums.push_back(num);
//    }
//    bool res;
//    res = check_matrix(matrix, nums, 5, 5, 6);
//    cout << (res ? 1 : 0) << endl;
//    getchar();
////    if ((getchar() == '\n')) {
////      break;
////    }
//  }
//  return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int find(vector<int> &par, int num) {
  if (par[num] == num)
    return num;
  return par[num] = find(par, par[num]);
}
void unite(vector<int> &par, int num1, int num2) {
  int par_num1 = find(par, num1);
  int par_num2 = find(par, num2);
  par[par_num2] = par_num1;
}
int main() {
  string s;
  vector<vector<int>>
      m{{1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {21, 22, 23, 24, 25}, {31, 32, 33, 34, 35}, {41, 42, 43, 44, 45}};
  map<int, int> matrix;
  for (int i = 0; i != m.size(); ++i)
    for (int j = 0; j != m[0].size(); ++j) {
      matrix[m[i][j]] = i * 5 + j;
    }
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  while (getline(cin, s)) {
    vector<int> num;
    int start_index = 0;
    for (int i = 0; i != s.size(); ++i) {
      if (s[i] == ' ') {
        num.push_back(stoi(s.substr(start_index, i - start_index)));
        start_index = i + 1;
      }
    }
    num.push_back(stoi(s.substr(start_index, s.size() - start_index)));
    map<int, int> num_to_index;
    for (int i = 0; i != num.size(); ++i)
      num_to_index[num[i]] = i;
    vector<int> par = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i != num.size(); ++i) {
      int pos = matrix[num[i]];
      int x = pos / 5;
      int y = pos % 5;
      for (int i = 0; i != 4; ++i) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)
          continue;
        if (num_to_index.find(m[next_x][next_y]) == num_to_index.end())
          continue;
        unite(par, num_to_index[m[next_x][next_y]], num_to_index[m[x][y]]);
      }
    }
    int pre_par = find(par, num_to_index[num[0]]);
    bool fail = false;
    for (int i = 1; i < num.size(); ++i) {
      int cur_par = find(par, num_to_index[num[i]]);
      if (cur_par != pre_par) {
        cout << 0 << endl;
        fail = true;
        break;
      }
    }
    if (!fail)
      cout << 1 << endl;
  }

}