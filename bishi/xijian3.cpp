//////
////// Created by Administrator on 2019/4/17 0017.
//////
////
////#include<iostream>
////
////using namespace std;
////const int MAX=1000;
////
////int countWays(int n, int cnt[])
////{
////    if (n<0)
////        return 0;
////    if (n==0)
////        return 1;
////    if (cnt[n]>0)
////        return cnt[n]; //如果大于0  说明这个子问题已经计算过，直接调用数组
////    else
////    {	cnt[n]=countWays(n-1,cnt)+countWays(n-2,cnt)+countWays(n-3,cnt);  //否则 还需计算该数组
////        return cnt[n];
////    }
////}
////int main()
////{
////    int m[MAX]={0};
////    cout<<countWays(10,m)<<endl;
////}
//
//
//
////#include<iostream>
////#include<vector>
////using namespace std;
////
////vector<vector<int>> matrix_multiply(vector<vector<int>> arrA, vector<vector<int>> arrB)
////{
////    int rowA = arrA.size();
////    int colA = arrA[0].size();
////    int rowB = arrB.size();
////    int colB = arrB[0].size();
////    vector<vector<int>>  res;
////    if (colA != rowB)
////    {
////        return res;
////    }
////    else
////    {
////        res.resize(rowA);
////        for (int i = 0; i < rowA; ++i)
////        {
////            res[i].resize(colB);
////        }
////        for (int i = 0; i < rowA; ++i)
////        {
////            for (int j = 0; j < colB; ++j)
////            {
////                for (int k = 0; k < colA; ++k)
////                {
////                    res[i][j] += arrA[i][k] * arrB[k][j];
////                }
////            }
////        }
////    }
////    return res;
////}
////
////int main()
////{
////    vector<vector<int>> arrA = { { 2, 1 }, { 4, 3 } };
////    vector<vector<int>> arrB = { { 1, 2 }, { 1, 0 } };
////    vector<vector<int>> res = matrix_multiply(arrA, arrB);
////    return 0;
////}
//
//
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//long sequence(long long m, unordered_map<long long, long>& map_cnt) {
//    long long n = m;
//    long count = 1;
//    while (n != 1) {
//        if (n % 2 == 0)
//            n /= 2;
//        else
//            n = n*3 + 1;
//
//        auto search = map_cnt.find(n);
//        if(search != map_cnt.end()){
//            count += search->second;
//
//            map_cnt.insert({m, count});
//            return count;
//        }
//        ++count;
//    }
//    map_cnt.insert({m, count});
//    return count;
//}
//
//int main() {
//    long max = 0;
//    long long maxi;
//    unordered_map<long long,long> map_cnt;
//    for (int i = 1; i < 1000000; ++i) {
//        long s = sequence(i, map_cnt);
//        if (s > max) {
//            max = s;
//            maxi = i;
//        }
//    }
//    cout << maxi << endl;
//}


#include <cstdio>
#include <string>

using namespace std;

union Data
{
  int i;
  float f[6];
  char  str[20];
};

int main( )
{
  union Data data{};

  printf( "Memory size occupied by data : %d\n", sizeof(data));

  const char * a = "abc";
  const char * b = "abc";
  printf("%d\n",a == b);

  char c[] = "abc";
  char d[] = "abc";
  printf("%d\n",c == d);

  string &&str1 = "abc";
  string &&str2 = "abc";
  printf("%d\n",str1 == str2);
  printf("%d\n",str1.c_str() == str2.c_str());


  return 0;
}