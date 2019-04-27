//
// Created by Administrator on 2019/4/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> dijistra_distance(unordered_map<int,vector<vector<int >>>& grapgh, int vertex, int src, int targ){
    unordered_set<int> visited;
    unordered_map<int, int> distancemap;
    for (int i = 0; i < vertex; ++i) {
        if(i!=src){
            distancemap[i] = INT32_MAX;
        }
    }
    visited.insert(src);
    for(auto& edge:grapgh[src]){
        distancemap[edge[0]] = edge[1];
    }

    for (int j = 0; j < vertex; ++j) {
        if(j == src)
            continue;
        int mindisfromstart = INT32_MAX;
        int mindisindex = -1;
        if(!visited.count(j) && distancemap[j]<mindisfromstart){
            mindisfromstart = distancemap[j];
            mindisindex = j;
        }

        if(mindisindex == -1)
            break;

        visited.insert(mindisindex);
        for(auto edge:grapgh[mindisindex]){
            if(visited.count(edge[0]))
                continue;
            int predis = distancemap[edge[0]];
            if(edge[1]!=INT32_MAX && mindisfromstart+edge[1]-1<predis){
                distancemap[edge[0]] = mindisfromstart+edge[1]-1;
            }
        }
    }
    return distancemap;
}


int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> route(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            int data;
            cin>>data;
            route[i].push_back(data);
        }
    }
    int src,targ;
    cin>>src>>targ;

    unordered_map<int,vector<vector<int >>> grapgh;
    for(auto rou:route)
    {
        grapgh[rou[1]].push_back({rou[2],rou[3]});
        grapgh[rou[2]].push_back({rou[1],rou[3]});
    }

    auto res = dijistra_distance(grapgh, m, src,targ);

    cout<<res[targ]<<endl;

    return 0;

}