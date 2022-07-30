/** Question Link
 *  https://www.spoj.com/problems/NAKANJ/
 **/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
bool vis[9][9];
int level[9][9];

vector <pair<int,int> > movements = {
    {-1, 2}, {1, 2},
    {-1, -2}, {1, -2},
    {2, -1}, {2, 1},
    {-2, -1}, {-2, 1}
};

bool isValid(pair<int,int> p){
    int x = p.first, y = p.second;
    return x>0 && y>0 && x<=8 && y<=8;
}

void bfs(pair <int,int> sorc)
{
    queue <pair<int,int>> q;
    q.push(sorc);
    vis[sorc.first][sorc.second] = true;
    level[sorc.first][sorc.second] = 0;
    while(!q.empty()){
        pair <int,int> curr_cell = q.front();
        q.pop();
        int x = curr_cell.first, y = curr_cell.second;
        vis[x][y] = true;
        for(auto it=movements.begin(); it!=movements.end(); it++){
            int childX = x + it->first, childY = y + it->second;
            if(!isValid({childX, childY})) continue;
            if(vis[childX][childY]) continue;
            q.push({childX, childY});
            level[childX][childY] = level[x][y]+1;
        }
    }
}

pair <int,int> points(string point)
{
    pair <int,int> p;
    p.first = point[0] - 'a';  p.first++;
    p.second = point[1] - '1'; p.second++;
    return p;
}

void reset()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            vis[i][j] = 0;
            level[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        reset();
        string sor, des;
        cin>>sor>>des;
        pair <int,int> sorc;
        pair <int,int> dest;
        sorc = points(sor);
        dest = points(des);
        bfs(sorc);
        //cout<<sorc.first<<" "<<sorc.second<<"   "<<dest.first<<" "<<dest.second<<endl;
        cout<<level[dest.first][dest.second]<<endl;
    }
}