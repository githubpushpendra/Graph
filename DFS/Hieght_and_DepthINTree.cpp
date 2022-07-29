#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
bool vis[N];
int depth[N], height[N];

void dfs(int vertex)
{
    vis[vertex] = 1;
    for(int child:graph[vertex]){

        if(vis[child]) continue;
        depth[child] = depth[vertex]+1;
        dfs(child);
        height[vertex] = max(height[vertex], height[child]+1);
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
    depth[1] = 0;
    dfs(1);
    for(i=1; i<=v; i++){
        cout<<depth[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=v; i++){
        cout<<height[i]<<" ";
    }
}