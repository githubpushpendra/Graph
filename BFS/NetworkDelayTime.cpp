
/** Link of this problem
 *  https://leetcode.com/problems/network-delay-time/
 **/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1, INF = 1e9+1;
vector <pair<int,int>> g[N];

int dijkstra(int n, int source)
{
    set <pair<int,int>> st;
    vector <int> dist(N,INF);
    vector <bool> vis(N,0);
    dist[source] = 0;
    st.insert({0,source});

    while(st.size() > 0){
        auto par = *st.begin();
        int par_v = par.second, par_wt = par.first;
        vis[par_v] = 1;
        st.erase(st.begin());

        for(auto child:g[par_v]){
            int child_v = child.first, child_wt = child.second;
            if(vis[child_v]) continue;
            if(par_wt + child_wt < dist[child_v]){
                dist[child_v] = par_wt + child_wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(dist[i]==INF) return -1;
        if(ans < dist[i]) ans = dist[i];
    }
    return ans;
}

int main()
{
    int n,k,i,j;
    cin>>n>>k;
    for(i=1; i<n; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    cout<<dijkstra(n,k);
}