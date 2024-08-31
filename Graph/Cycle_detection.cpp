#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
bool dfs(int node,int parent)
{
    vis[node]=1;
    for(auto it:vc[node])
    {
        if(vis[it])
        {
            if(parent!=it)
                return true;

        }
        else
            if(dfs(it,node))
            return true;
    }
    return false;
}
int main()
{
    int node,edge,a,b;
    cin >> node >> edge ;
    for(int i=0;i<edge;i++)
        cin >> a >> b,
        vc[a].push_back(b),vc[b].push_back(a);
    if(dfs(1,-1))
        cout<< "Contain cycle\n";
    else

        cout << "No cycle";
    return 0;
}

