//
// Created by Administrator on 2019/8/13.
//

#include "common.h"

using namespace std;

void bfs_traverse(const unordered_map<int, vector<vector<int>>> &graph,
                  unordered_set<int> &visited,
                  int src) {
//  visited.insert(src);
  queue<int> quene_bfs;
  quene_bfs.push(src);
  while (!quene_bfs.empty()) {
    int front = quene_bfs.front();
    quene_bfs.pop();
    if (!visited.count(front)) {
      visited.insert(front);
      cout << front << ",";
      for (auto &edge:graph.at(front)) {
        quene_bfs.push(edge[0]);
      }
    }
  }
}

int main() {
  istringstream ss(INPUT);
  cin.rdbuf(ss.rdbuf());
//  istream in(ss.rdbuf());
  int n, p;
  cin >> n >> p;

  unordered_map<int, vector<vector<int>>> graph_s1;
  unordered_set<int> visited;
  vector<int> destination;
  for (int i = 0; i < p; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    graph_s1[a].push_back({b, t});
    graph_s1[b].push_back({a, t});
  }

  bfs_traverse(graph_s1, visited, 0);
  return EXIT_SUCCESS;
}
