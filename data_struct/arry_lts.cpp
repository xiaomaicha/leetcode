#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  static int coins(vector<int> deno, int v) {
    if (deno.size() == 0 || v < 0) {
      return 0;
    }
    vector<int> dp = vector<int>(v + 1, 0);
    for (int j = 0; deno[0] * j <= v; j++) {
      dp[deno[0] * j] = 1;
    }
    for (int i = 1; i < deno.size(); i++) {
      for (int j = 1; j <= v; j++) {
        dp[j] += j - deno[i] >= 0 ? dp[j - deno[i]] : 0;
      }
    }
    return dp[v];
  }
};

int main() {
  vector<int> deno = {50, 20, 10, 5, 1};
  Solution sln;
  int solutions = sln.coins(deno, 100);
  std::cout << solutions << "\n";
  getchar();

  return 0;
}