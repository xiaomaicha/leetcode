////
//// Created by Administrator on 2019/5/8 0008.
////
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mincheckstep(string origen, string check) {
  unsigned int size1 = origen.size();
  unsigned int size2 = check.size();

  vector<vector<int>> dp_matrix(size1 + 1, vector<int>(size2 + 1, 0));
  for (int i = 0; i <= size1; ++i)
    dp_matrix[i][0] = i;
  for (int j = 0; j <= size2; ++j)
    dp_matrix[0][j] = j;

  for (int i = 1; i <= size1; ++i) {
    for (int j = 1; j <= size2; ++j) {
      if (origen[i - 1] == check[j - 1])
        dp_matrix[i][j] = dp_matrix[i - 1][j - 1];
      else
        dp_matrix[i][j] = 1 + std::min(dp_matrix[i - 1][j - 1], std::min(dp_matrix[i][j - 1], dp_matrix[i - 1][j]));
    }
  }

  return dp_matrix[size1][size2];
}

int main() {
  unsigned int N = 1;
  int checkstep = 0;
//  cin >> N;
  vector<string> s(2 * N);
//    string s[2 * N];
  for (int i = 0; i < 2 * N; i++)
    cin >> s[i];

  for (int j = 0; j < N; j++)
    checkstep += mincheckstep(s[j], s[j + N]);

  cout << checkstep;
  return 0;
}