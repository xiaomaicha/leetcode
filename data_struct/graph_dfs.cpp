
//
// Created by Administrator on 2019/8/13.
//

//
// Created by Administrator on 2019/8/13.
//


#include "common.h"

using namespace std;

void dfs_traverse(const unordered_map<int, vector<vector<int>>> &graph,
                  unordered_set<int> &visited,
                  int src) {
  cout<<src<<",";
  visited.insert(src);
  for (auto &edge : graph.at(src)){
    if(!visited.count(edge[0])){
      dfs_traverse(graph, visited, edge[0]);
    }
  }
}

int main() {
  istringstream ss(INPUT);
//  istream in(ss.rdbuf());
  int n, p;
  ss >> n >> p;

  unordered_map<int, vector<vector<int>>> graph_s1;
  unordered_set<int> visited;
  vector<int> destination;
  for (int i = 0; i < p; ++i) {
    int a, b, t;
    ss >> a >> b >> t;
    graph_s1[a].push_back({b, t});
    graph_s1[b].push_back({a, t});
  }

  dfs_traverse(graph_s1, visited, 0);
  return EXIT_SUCCESS;
}