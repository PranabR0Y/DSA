#include<bits/stdc++.h>
using namespace std;
vector<int>vc[10001];
bool vis[10001];
int discovery[10001],low[10001];
set<int>Arp;
void dfs(int node,int par=-1)
{
    static int timer=0;
    vis[node]=true;
    discovery[node]=low[node]=timer++;
    int children=0;
    for(int child:vc[node])
    {
        if(child==par) continue;
        if(vis[child])
        {
            low[node]=min(low[node],discovery[child]);
        }
        else
        {
            children++;
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(par==-1&&children>1)//this is a root node if toot has more than one subtree then it is an articulation point also
            Arp.insert(node);
            else if(par!=-1&&low[child]>=discovery[node])//not a root node
            Arp.insert(node);
            

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
    dfs(1);
    for(auto it:Arp)
    cout << it  << endl;
    
    return 0;
}