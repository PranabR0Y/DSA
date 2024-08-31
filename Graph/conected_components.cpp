#include<bits/stdc++.h>
using namespace std;
bool visited[10000];
vector<int>vc[10000];
void dfs(int node)
{
    visited[node]=true;
    for(auto it:vc[node])
    {
        if(!visited[it])
            dfs(it);

    }
}
int main()
{
    int nodes,edges,a,b,cc=0;
    cin >> nodes >> edges;
    for(int i=1;i<=edges;i++)
        cin >> a >> b,
        vc[a].push_back(b),
        vc[b].push_back(a);

    for(int i=1;i<=nodes;i++)
    {
        if(!visited[i])
            dfs(i),cc++;
    }
    cout << cc << endl;
    return 0;
}
