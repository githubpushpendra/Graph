/** Delete such a edge from tree
 *  that the product of sum of value
 *  of both parts of tree is maximized
 **/

/** Ques link for same ques
 *  https://www.interviewbit.com/problems/delete-edge/
 **/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
bool vis[N];
int subtre_sum[N];

void dfs(int vertex)
{
    vis[vertex] = 1;
    subtre_sum[vertex] += vertex;
    for(int child:graph[vertex]){

        if(vis[child]) continue;
        dfs(child);
        subtre_sum[vertex] += subtre_sum[child];
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

    int mx_product = 0;

    for(int child=2; child<=v; child++){
        int product = subtre_sum[child]*(subtre_sum[1]-subtre_sum[child]);
        mx_product = max(mx_product, product);
    }

    cout<<mx_product;

}