#include<bits/stdc++.h>
using namespace std;
char matrix[1000][1000];
bool vis[1000][1000];
int n,m,cc;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool is_valid(int x,int y)
{
    if(x<0||y<0||x==n||y==m)
    return false;
    if(vis[x][y]==true||matrix[x][y]=='#')
    return false;
    return true;
}
void dfs(int x,int y)
{
    vis[x][y]=true;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin >> matrix[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        if(!vis[i][j]&&matrix[i][j]=='.')
        dfs(i,j),cc++;


    }
    cout << cc << "\n";
    return 0;
}