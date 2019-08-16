//
// Created by Administrator on 2019/4/24.
//

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <unordered_set>
//
//using namespace std;
//
//unordered_map<int, int> dijistra_distance(const unordered_map<int,vector<vector<int >>>& grapgh, int vertex, int src, int targ){
//    unordered_set<int> visited;
//    unordered_map<int, int> distancemap;
//    for (int i = 0; i < vertex; ++i) {
//        if(i!=src){
//            distancemap[i] = INT32_MAX;
//        }
//    }
//    visited.insert(src);
//    for(auto& edge:grapgh.at(src)){
//        distancemap[edge[0]] = edge[1];
//    }
//
//    for (int j = 0; j < vertex; ++j) {
//        if(j == src)
//            continue;
//        int mindis_from_start = INT32_MAX;
//        int mindis_index = -1;
//      for (int l = 0; l < vertex; ++l){
//        if (!visited.count(l) && distancemap[l] < mindis_from_start) {
//          mindis_from_start = distancemap[l];
//          mindis_index = l;
//        }
//      }
//
//        if(mindis_index == -1)
//            break;
//
//        visited.insert(mindis_index);
//        for(auto edge:grapgh.at(mindis_index)){
//            if(visited.count(edge[0]))
//                continue;
//            int predis = distancemap[edge[0]];
//            if(edge[1]!=INT32_MAX && mindis_from_start+edge[1]<predis){
//                distancemap[edge[0]] = mindis_from_start+edge[1];
//            }
//        }
//    }
//    return distancemap;
//}
//
//
//int main()
//{
//    int m,n;
//    cin>>m>>n;
//    vector<vector<int>> route(n);
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            int data;
//            cin>>data;
//            route[i].push_back(data);
//        }
//    }
//    int src,targ;
//    cin>>src>>targ;
//
//    unordered_map<int,vector<vector<int >>> grapgh;
//    for(auto rou:route)
//    {
//        grapgh[rou[1]].push_back({rou[2],rou[3]});
//        grapgh[rou[2]].push_back({rou[1],rou[3]});
//    }
//
//    auto res = dijistra_distance(grapgh, m, src,targ);
//
//    cout<<res[targ]<<endl;
//
//    return 0;
//
//}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> dijistra_distance(unordered_map<int, vector<vector<int >>> &grapgh,
                                          int vertex,
                                          int src,
                                          int targ = 1) {
  unordered_set<int> visited;
  unordered_map<int, int> distancemap;
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
  return distancemap;
}

int main() {

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

    auto res = dijistra_distance(graph_s1, n, 0);

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
