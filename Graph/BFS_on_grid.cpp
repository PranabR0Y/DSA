#include<bits/stdc++.h>
using namespace std;
bool vis[1000][1000];
int dis[1000][1000],matrix[1000][1000];
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool is_valid(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
    return false;
    if(vis[x][y])
    return false;
    return true;
}
void bfs(int x,int y)
{
    vis[x][y]=true;
    queue<pair<int,int>>pq;
    pq.push({x,y});
    dis[x][y]=0;
    while(!pq.empty())
    {
        int X=pq.front().first;
        int Y=pq.front().second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int newX=X+dx[i];
            int newY=Y+dy[i];
            if(is_valid(newX,newY))
            {
               vis[newX][newY]=true;
               dis[newX][newY]=dis[X][Y]+1;
               pq.push({newX,newY});
            }
        }
        
    }

}
int main()
{
    
    cin >> n >> m;
    int s1,s2;
    cin >> s1 >> s2;
    bfs(s1,s2);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout << dis[i][j] << " ";
        cout << "\n";
    }

    return 0;
}