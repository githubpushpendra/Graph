#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
bool vis[N];

void dfs(int vertex)
{
    vis[vertex] = 1;
    cout<<vertex<<" ";
    for(int child:graph[vertex]){

        if(vis[child]) continue;
        dfs(child);
    }
}

int main()
{
    int v,e,i;  // v = number of verteces. e = number of edges.
    cin>>v>>e;
    for(i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
}