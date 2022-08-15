/** Link to that problem is :
 *  https://www.codechef.com/problems/REVERSE
 **/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <pair<int,int>> graph[N];
int level[N];

void bfs(int source)
{
    deque <int> q;
    q.push_back(source);
    level[source] = 0;

    while(!q.empty()){
        int curr_vertex = q.front();
        q.pop_front();
        for(pair <int,int> child:graph[curr_vertex]){
            int ver = child.first, wt = child.second;
            if(level[curr_vertex]+wt < level[ver]){
                if(wt == 0) q.push_front(ver);
                else q.push_back(ver);
                level[ver] = level[curr_vertex] + wt;
            }
        }
    }
}

int main()
{
    int v,e,i,j;
    cin>>v>>e;
    for(i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        if(x == y) continue;
        graph[x].push_back({y,0});
        graph[y].push_back({x,1});
        level[x] = 1e5;
        level[y] = 1e5;
    }
    bfs(1);
    int reversals = -1;
    if(level[v] < 1e5) reversals = level[v];
    cout<<reversals;
}