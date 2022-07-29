/**
 * Tells present and 
 * Count of Cycles 
 * in graph
 **/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
bool vis[N];
int cycles=0, isCycle = false;

bool dfs(int vertex, int par)
{
    vis[vertex] = true;
    //cout<<vertex<<" ";
    for(int child:graph[vertex]){
        if(child == par) continue;
        if(vis[child]) {
            cycles++;
            isCycle =  true;
            continue;
           // return true;
        }
        isCycle |= dfs(child, vertex);
        
        //if(isCycle) return true;
    }
    return isCycle;
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
    cout<<"Is cycle present - "<<dfs(1, 0)<<endl;
    cout<<"Number of cycles - "<<cycles/2;
}