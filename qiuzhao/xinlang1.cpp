//
// Created by Administrator on 2019/8/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int cal_max_competition(vector<int> &weights, int n, int k) {
  sort(weights.begin(), weights.end());
  vector<int> board(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if ((weights[j - 1] - weights[i - 1]) <= k) {
        board[j] = board[j - 1] + 1;
        int index = j + 1;
        while (index <= n) {
          board[index] = board[j];
//          if (i + 1 <= n) {
//            board[i + 1][index] = board[i][j];
//          }
          index++;
        }
        i++;
        break;
      } else {
        board[j] = max(board[j], board[j - 1]);
      }
    }
  }
  return board[n];
}

//int cal_max_competition(vector<int> &weights, int n, int k) {
//  sort(weights.begin(), weights.end());
//  vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
//  for (int i = 1; i <= n; ++i) {
//    for (int j = i + 1; j <= n; ++j) {
//      if ((weights[j - 1] - weights[i - 1]) <= k) {
//        board[i][j] = board[i - 1][j - 1] + 1;
//        int index = j + 1;
//        while (index <= n) {
//          board[i][index] = board[i][j];
//          if (i + 1 <= n) {
//            board[i + 1][index] = board[i][j];
//          }
//          index++;
//        }
//        i++;
//        break;
//      } else {
//        board[i][j] = max(board[i - 1][j], board[i][j - 1]);
//      }
//    }
//  }
//  return board[n - 1][n];
//}

int main() {
  string input = "4 5\n"
                 "65 66 67 68";
  stringstream ss(input);
  cin.rdbuf(ss.rdbuf());
  int n, k;
  cin >> n >> k;
  vector<int> weights;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    weights.push_back(a);
  }
  int res = cal_max_competition(weights, n, k);
  cout << res << endl;
  return 0;
}