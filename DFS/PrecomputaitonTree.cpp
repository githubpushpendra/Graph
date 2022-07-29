/** Given Q queries as the vertex name -- 
 *  find sum and number of even numbers of subtree of this vertex
 *  for all Q queries
 **/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
bool vis[N];
int sum[N], even[N];

void dfs(int vertex)
{
    vis[vertex] = 1;
    for(int child:graph[vertex]){

        if(vis[child]) continue;
        dfs(child);
        //sum[vertex] = max(sum[vertex], sum[vertex] + sum[child]);
        sum[vertex] += sum[child];
        even[vertex] += even[child];
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
    
    for(i=1; i<=v; i++){
        sum[i] = i;
        if(i%2 == 0) even[i] = 1;
    }
    
    dfs(1);
    for(i=1; i<=v; i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=v; i++){
        cout<<even[i]<<" ";
    }
}