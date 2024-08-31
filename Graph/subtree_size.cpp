#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100001];
bool vis[100001];
int sub_size[100001];
int dfs(int node)
{
    int curr_size=1;
    vis[node]=true;
    for(auto it:vc[node])
    {
        if(!vis[it])
            curr_size+=dfs(it);
    }
    sub_size[node]=curr_size;
    return curr_size;

}
int main()
{
    int node,edge,a,b;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
        cin >> a >> b,vc[a].push_back(b),vc[b].push_back(a);
    cout << dfs(1) << endl;
    for(int i=1;i<=node;i++)
        cout << sub_size[i] << " ";
    cout << endl;
    return 0;
}
