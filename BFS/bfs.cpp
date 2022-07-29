// Time Complexity - O(V + E)


#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector <int> graph[N];
bool vis[N];
int level[N];

void bfs(int source)
{
    queue <int> q;
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        int curr_v = q.front();
        q.pop();
        cout<<curr_v<<" ";
        for(int child:graph[curr_v]){
            if(vis[child]) continue;
            q.push(child);
            vis[child] = true;
            level[child] = level[curr_v] + 1;
        }
    }
}

int main()
{
    int v,e,i;
    cin>>v>>e;
    for(i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    cout<<endl;
    for(i=1; i<=v; i++){
        cout<<i<<" : "<<level[i]<<"\n";
    }
}