//
// Created by Administrator on 2019/4/24 0024.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


using namespace std;
int inf = 9999999;
vector<int> Dijkstra_shortestDistance(vector<vector<int> >& matrix , int src)
{
    int rows = matrix.size();
    int min = 0;
    int cur = 0;
    vector<int> res(rows, 0);
    vector<int> book(rows, 0);
    for (int i=1;i<rows;i++)
        res[i] = matrix[src][i];

    for (int i=1; i<rows-1; i++)
    {
        min = inf;
        for (int j=1; j<rows; j++)
        {
            if(book[j] == 0 && res[j] < min)
            {
                min = res[j];
                cur = j;
            }
        }
        book[cur] = 1;
        for (int v=1; v< rows; v++)
        {
            if (matrix[cur][v]<inf)
            {
                if(res[v]>res[cur]+matrix[cur][v])
                    res[v] = res[cur] + matrix[cur][v];
            }
        }
    }
    return res;


}

int main()
{
    int  n=0,m=0,t1,t2,t3,t0;

    cin >> n >> m;

    vector<vector<int> > e(n+1, vector<int>(n+1));

    for(int i=1;i<n+1;i++)
        for (int j=1;j<n+1;j++)
        {
            if (i==j) e[i][j] = 0;
            else e[i][j] = inf;
        }

    for (int i=1;i<m+1;i++)
    {
        cin >>t0>> t1>>t2>>t3;
        e[t1][t2] = t3;

    }
    cin>>t0>>t1;


    // for(int i=0; i<n+1; i++)
    // {
    //     for(int j=0; j<n+1; j++)
    //     {
    //         cout<<e[i][j]<<',';
    //     }
    //     cout<<endl;
    // }

    vector<int> res = Dijkstra_shortestDistance(e,t0);
    // for (vector<int>::iterator i = res.begin(); i!=res.end(); i++)
    // {
    //     cout<< *i<<',';
    // }
    if (res[t1]<inf)
        cout<<res[t1]<<endl;
    else cout<<"NA"<<endl;
    return 0;
}