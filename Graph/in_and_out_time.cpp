#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int in[100001];
int out[100001];
int t=1;
void dfs(int node)
{
    vis[node]=true;
    in[node]=t++;
    for(auto it:vc[node])
    {
        if(!vis[it])
            dfs(it);
    }
    out[node]=t++;
}
int main()
{
    int node,edge,a,b;
    cin >> node >> edge ;
    for(int i=1;i<=edge;i++)
    {
        cin >> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a);

    }
    dfs(1);
    for(int i=1;i<=node;i++)
        cout << in[i] << " " ;
    cout << endl;
    for(int i=1;i<=node;i++)
        cout << out[i] << " ";
    return 0;
}
