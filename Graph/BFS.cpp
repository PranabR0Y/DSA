#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
int dis[10001];
bool vis[100001];
void BFS(int root)
{
    dis[root]=0;
    vis[root]=true;
    queue<int>p;
    p.push(root);
    while(!p.empty())
    {
        root=p.front();
        p.pop();
        for(auto it:vc[root])
        {
            if(!vis[it])
            {
                p.push(it);
                vis[it]=true;
                dis[it]=dis[root]+1;
            }
        }
    }
}
int main()
{
    int node,edge,a,b;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
        cin >> a >> b,
        vc[a].push_back(b),
        vc[b].push_back(a);
    BFS(3);
    for(int i=1;i<=node;i++)
        cout << dis[i] << " ";

    return 0;
}
