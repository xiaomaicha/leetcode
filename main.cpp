//#include <iostream>
//using namespace std;
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    cin.get();
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N=5;
//int Money[N]={5,2,2,3,5};
//int Value[N]={1,5,10,50,100};
//
//int solve(int money){
//    int num=0;
//    for(int i=N-1;i>0;i--){
//        //c为使用纸币的张数，在需要用面值为vaule[i]的张数和已有张数里选取最小的；
//        int c=min(money/Value[i],Money[i]);
//        money=money-Value[i]*c;
//        num+=c;
//    }
//    if(money>0){
//        num=-1;
//    }
//    return num;
//}
//int main(){
//    int money;
//    cin>>money;//输入一共需要支付多少钱
//    int res=solve(money);
//    if(res!=-1){
//        cout<<res<<endl;
//    }else{
//        cout<<"no"<<endl;
//    }
//    return 0;
//
//}



//#include <stdio.h>
//#include <tchar.h>
//#include <queue>
//#include "iostream"
//
//using namespace std;
////输入
//const int n = 5;
//int S[n]={1,2,4,6,8};
//int T[n]={3,5,7,9,10};
//
//pair<int, int> itv[n];//对工作排序的pair数组
//int solve()
//{
//    //对pair进行字典序比较
//    //为了让结束时间早的工作排在前面，把T存入first，把S存入second
//    for(int i = 0; i < n; i ++) {
//
//        itv[i].first = S[i];
//        itv[i].second = T[i];
//    }
//    sort(itv, itv + n);
//
//    int count = 0;//选取的结果
//    int t = 0;	//最后所选工作的结束时间
//    for(int i = 0; i < n; i ++) {
//        if(t < itv[i].first) {
//            count ++;
//            t = itv[i].second;
//        }
//    }
//    return count;
//}
//
//int main() {
//    int k=solve();
//    cout << k<< endl;
//    return 0;
//}
//


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = INT32_MAX;
        unordered_map<int,vector<vector<int>>> map;
        unordered_set<int> visited{{src}};
        for(auto flight:flights)
        {
            map[flight[0]].push_back({flight[1],flight[2]});
        }
        helper(map,src,dst,k,visited,0,res);
        return (res==INT32_MAX)?-1:res;
    }
    void helper(unordered_map<int, vector<vector<int>>>& m, int cur, int dst, int k, unordered_set<int>& visited, int out, int& res)
    {
        if(cur==dst){res = out;return;}
        if(k<0) return;
        for(auto a:m[cur])
        {
            if(visited.count(a[0])||out + a[1]>res) continue;
            visited.insert(a[0]);
            helper(m,a[0],dst,k-1,visited,out+a[1],res);
            visited.erase(a[0]);
        }
    }
};

//class Solution{
//public:
//    string multiply(string num1, string num2) {
//        if(num1=="0"||num2=="0")
//            return "0";
//        string res;
//        int n1 = num1.size(), n2 = num2.size();
//        int i=0,j=0;
//        vector<int> v(n1+n2,0);
//        for(string::reverse_iterator it1 = num1.rbegin(); it1 !=num1.rend(); it1++, i++)
//        {
//            for(string::reverse_iterator it2 = num2.rbegin(); it2 !=num2.rend(); it2++,j++)
//            {
//                char a = *it1, b =*it2;
//                int tmp = (a-'0') * (b-'0') + v[i+j];
//                v[i+j+1] += tmp/10;
//                v[i+j] = tmp%10;
//
//            }
//            j=0;
//
//        }
//
////        long r=0;
////        for (int l = 0; l < n1+n2; ++l) {
////            long factor = pow(10,l);
////            r+=long(v[l])*factor;
////        }
////        res = to_string(r);
//
//        int k = n1 + n2 - 1;
//        while (v[k]==0)
//            k--;
//
//        while (k>=0)
//        {
//            res.push_back(v[k]+'0');
//            k--;
//        }
//
//        if(res =="")
//            return "0";
//
//
//        return res;
//    }
//};

int main()
{
//    Solution solution;
//    string a ="123";
//    string b = "321";
//
//    auto res = solution.multiply(a,b);

    unordered_set<int> visited({2});
    queue<vector<int>> q({{2, 0}});

    cout<<endl;

    return 0;
}

