//
// Created by Administrator on 2019/9/9.
//

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string str = "20\n"
               "10\n"
               "3 8 5 9 2 3 5 7 4 3\n"
               "1 2 3 4 5 6 7 8 9 10";
  stringstream ss(str);
  cin.rdbuf(ss.rdbuf());
  int m, n;
  cin>>m>>n;
  vector<int> movie_size(1,0), movie_favorite(1,0);
  for (int i = 0; i < n; ++i) {
    int size;
    cin>>size;
    movie_size.push_back(size);
  }
  for (int i = 0; i < n; ++i) {
    int favo;
    cin>>favo;
    movie_favorite.push_back(favo);
  }
  vector<int> dp(m + 1, 0);

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= movie_size[i]; j--)
      dp[j] = max(dp[j], dp[j - movie_size[i]] + movie_favorite[i]);

  cout << dp[m] << endl;
  return 0;
}

//#include <iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//  int total_weight = 10;
//  int w[6] = { 0,5,4,3,2,1};
//  int v[6] = { 0,1,2,3,4,5};
//  int dp[11] = { 0 };
//
//  for (int i = 1; i <= 5; i++)
//    for (int j = w[i]; j <= 10;j++)
//      dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
//
//  cout << "总的价值为: " << dp[10] << endl;
//  return 0;
//}

//#include <iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//  int total_weight = 10;
//  int w[6] = { 0,5,4,3,2,1 };
//  int v[6] = { 0,1,2,3,4,5 };
//  int cot[6] = { 0,1,2,1,2,1 };
//  int dp[11] = { 0 };
//
//  for (int i = 1; i <= 5; i++)
//    for (int k = 1; k <= cot[i];k++)
//      for (int j = 10; j >= w[i]; j--)
//        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//
//  cout << "总的价值为: " << dp[10] << endl;
//  return 0;
//}