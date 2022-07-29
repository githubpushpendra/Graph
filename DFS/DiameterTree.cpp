/** LCA - Least Common Ancestor
 *  I will find LCA of two vertices in O(n).
 *  Algorithm :
 *  Fisrt store path of both vertices from root vertex.
 *  Then traverse through array of path,
 *  vertex, before first vertex which will differ in path, will be LCA.
 **/


/// NOTE : Binary Uplifting Algorithm works in O(log(n)) time to find LCA.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector <int> graph[N]; 
int parent[N];

void dfs(int vertex, int par = -1)
{
    parent[vertex] = par;
    for(int child:graph[vertex]){

        if(child == par) continue;
        dfs(child, vertex);
    }
}

vector <int> Path(int v)
{
    vector <int> path;
    while(v != -1){
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int v,e,i,j;  // v = number of verteces. e = number of edges.
    cin>>v>>e;

    for(i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    int LCA=1, x, y;
    cout<<"Vertices for LCA : "<<"\n";
    cin>>x>>y;
    
    vector <int> path_x = Path(x);
    vector <int> path_y = Path(y);

    for(i=0; i<min(path_x.size(), path_y.size()); i++){
        if(path_x[i] == path_y[i]) LCA = path_x[i];
        else break;
    }
    
    cout<< "LCA is : " <<LCA;
}