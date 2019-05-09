//
// Created by Administrator on 2019/4/27.
//


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void maxdistance(unordered_map<int,vector<int>>& gragh, int cur,unordered_set<int>& visited, int dis, int& maxdis){
    for(auto& next:gragh[cur]){
        if(visited.count(next)==0){
            visited.insert(next);
            dis++;
            if(dis>maxdis)
                maxdis = dis;
            maxdistance(gragh,next,visited,dis,maxdis);
            dis--;
            visited.erase(next);
        }
    }
}

int main(){
    unsigned int test_n;
    cin>>test_n;
    vector<int> vetex_num;
    vector<unordered_map<int,vector<int>>> gragh(test_n);

    for (int i = 0; i < test_n; ++i) {
        int m;
        cin>>m;
        vetex_num.push_back(m);
        for (int j = 0; j < m-1; ++j) {
            int src, des;
            cin>>src>>des;
            gragh[i][src].push_back(des);
            gragh[i][des].push_back(src);
        }
    }

    for (int i = 0; i < test_n; ++i) {
        int maxdis = INT32_MIN;
        int curdis = INT32_MIN;
        unordered_set<int> visited;
        for (int j = 0; j < vetex_num[i]; ++j) {
            maxdistance(gragh[i],j,visited,-1,curdis);
            visited.clear();
            if(curdis>maxdis){
                maxdis = curdis;
            }
        }
        cout<<maxdis<<endl;
    }

    return 0;
}