#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int color[100001];
bool dfs(int node,int c)
{
    vis[node]=true;
    color[node] = c;
    for(auto it:vc[node])
    {
        if(!vis[it])
        {
            if(dfs(it,c^1)==false)
                return false;

        }
        else if(color[it]==color[node])
            return false;

    }
    return true;

}
int main()
{
    int nodes,edges,a,b;// a graph of having cycle odd length is always not bipartite
    cin >> nodes >> edges;
    for(int i=1;i<=edges;i++)
        cin >> a >> b,vc[a].push_back(b),vc[b].push_back(a);
    if(dfs(1,1))
        cout << "Bipartite\n";
    else

        cout << "No  bipartite\n";
    return 0;
}
