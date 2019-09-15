//
// Created by Administrator on 2019/8/11.
//
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
const int Inf = 2e9;
struct Node{
  int to,weight;// to-点的编号  weight-权值
  friend bool operator < (const Node& a,const Node& b);
};

bool operator < (const Node& a,const Node& b){
  return a.weight > b.weight;
}

int prim(const unordered_map<int, vector<Node> >& graph, int n){
  int visited[1000] = {0};
  int num = 1,sum = 0;
  priority_queue<Node> distance;
  Node node{}, min_distance{};
  //开始Pirm算法
  node.to = 1;
  node.weight = 0;
  distance.push(node);
  while(num <= n && !distance.empty()){
    min_distance = distance.top();
    distance.pop();
    if(visited[min_distance.to])
      continue;
    visited[min_distance.to] = 1;
    num++;
    sum += min_distance.weight;
    cout<<"min_distance.to = "<<min_distance.to <<"  min_distance.weight =  "<<min_distance.weight<<" sum =  "<<sum<<"\n";
    int len = graph.at(min_distance.to).size();
    for(int i = 0; i < len; i++){
      if(!visited[graph.at(min_distance.to)[i].to])
        distance.push(graph.at(min_distance.to)[i]);
    }
  }
  cout<<"\n最小代价为:\n"<<sum;
  return sum;
}

void creat_graph(unordered_map<int, vector<Node> >& graph){

}

int main(){
  int n,m;
  unordered_map<int, vector<Node> > graph;
  cout<<"请输入点的个数n和边的个数m:\n" ;
  cin>>n>>m;
  //建立邻接表
  graph.clear();
  int a,b,c;
  for(int i = 1;i <= m; i++){
    Node node{};
    cin>>a>>b>>c;
    node.to = b;
    node.weight = c;
    graph[a].push_back(node);
    node.to = a;
    graph[b].push_back(node);
  }
  cout<<"邻接表如下:\n\n";
  for(int i = 1; i <= n; i++){
    int size_ = graph[i].size();
    cout<<i<<":  ";
    for(int j = 0; j < size_;j++)
      cout<<graph[i][j].to<<" ";
    cout<<"\n";
  }
  cout<<"\n\n";
  prim(graph, n);
  return 0;
}
/*
test
6 9
1 2 34
1 6 19
1 3 46
2 5 12
3 6 25
3 4 17
4 6 25
4 5 38
5 6 26
ans:1 6 3 4 5 2
    99
**********************************
*/


//#include <iostream>
//#include <queue>
//#include <unordered_map>
//
//using namespace std;
//const int INF = 2e9;
//
//struct Node {
//  int num;
//  int weight;
//  friend bool operator<(const Node &a, const Node &b) {
//    return a.weight > b.weight;
//  }
//};
//
//int main() {
//  priority_queue<Node> mst;
//  unordered_map<int, vector<vector<int >>> graph;
//  int m, n;
//  cin >> m >> n;
//
//  for (int i = 0; i < m; ++i) {
//    int from, to, weight;
//    cin >> from >> to >> weight;
//    graph[from].push_back({to, weight});
//    graph[to].push_back({from, weight});
//  }
//}
