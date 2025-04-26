#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100000];
bool visited[100000];
void dfs(int node)
{
    visited[node]=true;
    cout << node << endl;
    for(auto it:vc[node])
    {
        if(!visited[it])
            dfs(it);
    }
}
int main()
{
    int nodes,edges,a,b;
    cin >> nodes >> edges;
    for(int i=1;i<=edges;i++)
        cin >> a >> b,
        vc[a].push_back(b),
        vc[b].push_back(a);
    dfs(1);
    for (vector<int> vect1D : vc)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }   
        cout << endl;
    }
    return 0;
}
