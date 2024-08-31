#include<bits/stdc++.h>
using namespace std;
vector<int>vc[10001],transpose[10001];
bool vis[10001];
vector<int>order,scc;
void dfs(int node)
{

    vis[node]=true;
    for(int child:vc[node])
    if(!vis[child])
    dfs(child);

    order.push_back(node);
}
void dfs2(int node)
{
    vis[node]=true;
    for(auto child:transpose[node])
    {
        if(!vis[child])
        dfs2(child);
    }
    scc.push_back(node);

}
int main()
{
    int node,edge,x,y;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y;
        vc[x].push_back(y);
        transpose[y].push_back(x);
    }
    for(int i=1;i<=node;i++)
    if(!vis[i])dfs(i);
    
    for(int i=1;i<=node;i++)
    vis[i]=false;
    for(int i=order.size()-1;i>=0;i--)
    {
        scc.clear();
        if(!vis[order[i]])
        dfs2(order[i]);
        
        for(auto it:scc)
        cout << it << " ";
        cout << endl;
    }
    

    
    
    return 0;
}