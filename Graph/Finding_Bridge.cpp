#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int in[100001],low[100001],timer;
void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=low[node]=timer++;
    for(auto it:vc[node])
    {
        if(it==par) continue;
        if(vis[it])
        {
            //back edge
            low[node]=min(in[it],low[node]);
        }
        else
        {
            dfs(it,node);
            if(low[it]>in[node])
            cout << it << " " << node << " Form a bridge\n";
            low[node]=min(low[node],low[it]);

        }
    }
}

int main()
{
    int node,edge,x,y;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    dfs(1,-1);

    return 0;
}