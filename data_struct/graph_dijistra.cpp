//
// Created by Administrator on 2019/8/12.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print_route(const unordered_map<int, int> &pre_vertex, int cur, int src){
  if(cur !=src){
    print_route(pre_vertex, pre_vertex.at(cur), src);
  }
  cout<<cur<<",";
}

void dijistra_route_distance(const unordered_map<int, vector<vector<int >>> &grapgh,
                             unordered_map<int, int> &distancemap,
                             int vertex,
                             int src,
                             int targ = 1) {
  unordered_set<int> visited;
  unordered_map<int, int> pre_vertex;
  for (int i = 0; i < vertex; ++i) {
    if (i != src) {
      distancemap[i] = INT32_MAX;
    }
  }
  visited.insert(src);
  for (auto &edge:grapgh.at(src)) {
    distancemap[edge[0]] = edge[1];
    pre_vertex[edge[0]] = src;
  }

  for (int j = 0; j < vertex; ++j) {
    if (j == src)
      continue;
    int mindis_from_start = INT32_MAX;
    int mindis_index = -1;
    for (int l = 0; l < vertex; ++l) {
      if (!visited.count(l) && distancemap[l] < mindis_from_start) {
        mindis_from_start = distancemap[l];
        mindis_index = l;
      }
    }

    if (mindis_index == -1)
      break;

    visited.insert(mindis_index);
    for (auto edge:grapgh.at(mindis_index)) {
      if (visited.count(edge[0]))
        continue;
      int predis = distancemap[edge[0]];
      if (edge[1] != INT32_MAX && mindis_from_start + edge[1] < predis) {
        distancemap[edge[0]] = mindis_from_start + edge[1];
        pre_vertex[edge[0]] = mindis_index;
      }
    }
  }
  print_route(pre_vertex, targ, src);
  //output:0,1,3,5,6,
}

void dijistra_distance(const unordered_map<int, vector<vector<int >>> &grapgh,
                       unordered_map<int, int> &distancemap,
                       int vertex,
                       int src,
                       int targ = 1) {
  unordered_set<int> visited;
  for (int i = 0; i < vertex; ++i) {
    if (i != src) {
      distancemap[i] = INT32_MAX;
    }
  }
  visited.insert(src);
  for (auto &edge:grapgh.at(src)) {
    distancemap[edge[0]] = edge[1];
  }

  for (int j = 0; j < vertex; ++j) {
    if (j == src)
      continue;
    int mindis_from_start = INT32_MAX;
    int mindis_index = -1;
    for (int l = 0; l < vertex; ++l) {
      if (!visited.count(l) && distancemap[l] < mindis_from_start) {
        mindis_from_start = distancemap[l];
        mindis_index = l;
      }
    }

    if (mindis_index == -1)
      break;

    visited.insert(mindis_index);
    for (auto edge:grapgh.at(mindis_index)) {
      if (visited.count(edge[0]))
        continue;
      int predis = distancemap[edge[0]];
      if (edge[1] != INT32_MAX && mindis_from_start + edge[1] < predis) {
        distancemap[edge[0]] = mindis_from_start + edge[1];
      }
    }
  }
}

int findPeakElement(vector<int>& nums) {
  int left = 0;
  int right = nums.size()-1;
  while(left < right)
  {
    int mid = (left + right)/2;
    if(nums[mid]>nums[mid+1])
    {
      right=mid;
    }
    else
    {
      left=mid+1;
    }
  }
}




int main(){
  const string INPUT = "7 10\n"
                       "0 1 5\n"
                       "0 2 2\n"
                       "1 3 1\n"
                       "1 4 6\n"
                       "2 3 6\n"
                       "2 5 8\n"
                       "3 4 1\n"
                       "3 5 2\n"
                       "4 6 7\n"
                       "5 6 3";
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

  unordered_map<int, int> distancemap;
  dijistra_route_distance(graph_s1, distancemap, n, 0, 6);

  return EXIT_SUCCESS;
}

int main_1() {
  while (true) {
    int n, p, c;
    cin >> n >> p >> c;

    unordered_map<int, vector<vector<int>>> graph_s1;
    vector<int> destination;
    for (int i = 0; i < p; ++i) {
      int a, b, t;
      cin >> a >> b >> t;
      graph_s1[a].push_back({b, t});
      graph_s1[b].push_back({a, t});
    }

    for (int j = 0; j < c; ++j) {
      int des;
      cin >> des;
      destination.push_back(des);
    }

    unordered_map<int, int> distancemap;
    dijistra_distance(graph_s1, distancemap, n, 0);
    auto res = distancemap;

    int res_sum = 0;
    for (int des: destination) {
      res_sum += res[des];
    }
    cout << res_sum << endl;
//    string number;
//    getline(cin, number);
    getchar();
    if ((getchar() == '\n')) {
      break;
    }
  }
  return 0;
}
