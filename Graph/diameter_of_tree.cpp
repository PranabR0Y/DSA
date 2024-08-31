#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int Max_d,Max_n;
void dfs(int node,int dis)
{
    vis[node]=true;
    if(dis>Max_d)
        Max_d=dis,Max_n=node;
    for(auto it:vc[node])
        if(!vis[it])
        dfs(it,dis+1);
}
int main()
{
    int node ,edge,a,b;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
        cin >> a >> b,vc[a].push_back(b),vc[b].push_back(a);
    Max_d=-1;

    dfs(1,0);
    cout << Max_d << ' ' << Max_n << endl;
    for(int i=1;i<=node;i++)
        vis[i]=false;

    dfs(Max_n,0);

    cout << Max_d << ' ' << Max_n  << endl;


    
    return 0;
}
