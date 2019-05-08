//
// Created by Administrator on 2019/4/26 0026.
//

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

bool canarrivedes(unordered_map<int,vector<vector<int >>>& graph,unordered_set<int>& visited, int cur, int des, bool hask){
    if(cur==des && hask){
        return true;
    }
    bool res = false;
    for (auto& adj:graph[cur]){
        if(adj[2] == 1){
            hask = true;
        }
        if(visited.count(adj[0]) == 0){
            visited.insert(adj[0]);
            res = res || canarrivedes(graph, visited, adj[0], des, hask);
            if(res){
                return res;
            }
            visited.erase(adj[0]);
        }
    }
    return res;
}

int main(){
    unsigned int n, m, k, g;
    cin>>n>>m>>k>>g;
    vector<int> data_n;
    unordered_set<int> data_k;
    vector<vector<int>> route(g);

    for (int i = 0; i < n; ++i) {
        int data;
        cin>>data;
        data_n.push_back(data);
    }
    for (int i = 0; i <k ; ++i) {
        int data;
        cin>>data;
        data_k.insert(data);
    }
    for (int i = 0; i <g ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            int data;
            cin>>data;
            route[i].push_back(data);
        }
    }
    unordered_map<int,vector<vector<int >>> graph;

    for (auto& rou:route){
        int class_glag;
        class_glag = data_k.count(rou[0]); //补给还是终点 1补给
        graph[rou[0]].push_back({rou[1],rou[2], class_glag});
        class_glag = data_k.count(rou[1]);
        graph[rou[1]].push_back({rou[0],rou[2], class_glag});
    }

    bool res1 = false;
    bool res2 = false;
    unordered_set<int> visited;
    for(auto& des:data_n){
        bool res = canarrivedes(graph,visited,1,des, false);
        res1 = res1 && res;
        res2 = res2 || res;
    }
    if(res1){
        cout<<"Wonderful"<<endl;
    } else if(res2){
        cout<<"Good"<<endl;
    } else{
        cout<<"Terrible"<<endl;
    }
    return 0;
    
}