#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int dis[100001];
void dfs(int node,int d)
{
    dis[node]=d;
    vis[node]=true;

    for(auto it:vc[node])
    {
        if(!vis[it])
            dfs(it,dis[node]+1);
    }
}
int main()
{
    int node,edge,a,b;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
        cin >> a >> b,vc[a].push_back(b),vc[b].push_back(a);
    dfs(1,0);
    for(int i=1;i<=node;i++)
        cout << dis[i] << ' ';
    return 0;
}
