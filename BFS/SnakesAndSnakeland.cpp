#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int level[N][N];

void reset()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            level[i][j] = N;
        }
    }
}

vector <pair<int,int>> points = {
    {0,-1}, {-1,-1},
    {-1,0}, {-1,+1},
    {0,+1}, {+1,+1},
    {+1,0}, {+1,-1},
};

bool IsValid(int i,int j, int n, int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(vector <pair<int,int>> sources, int n, int m)
{
    queue <pair<int,int>> q;
    for(auto it:sources){
        q.push(it);
        level[it.first][it.second] = 0;
    }
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(auto it:points){
            int childX = x + it.first, childY = y + it.second;
            if(!IsValid(childX, childY, n, m)) continue;
            if(level[x][y]+1 < level[childX][childY]){
                q.push({childX, childY});
                level[childX][childY] = level[x][y]+1;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        reset();
        int n,m,i,j,mx=0;
        cin>>n>>m;
        int sn[n][m];
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cin>>sn[i][j];
                if(sn[i][j] > mx) mx = sn[i][j];
            }
        }
        vector <pair<int,int>> sources;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(sn[i][j] == mx) sources.push_back({i,j});
            }
        }
        bfs(sources,n,m);
        mx = 0;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(level[i][j] > mx) mx = level[i][j];
            }
        }
        cout<<mx<<endl;
    }
}