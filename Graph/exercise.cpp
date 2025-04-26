#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>g;
int in[1000],low[1000],t;
bool vis[1000];
void dfs(int node,int parent)
{
      in[node]=low[node]=++t;
      vis[node]=1;
      for(int it:g[node])
      {
            if(vis[it]==false)
            {
                  dfs(it,node);
                  if(low[it]>in[node])
                  cout << it << ' ' << node << "form brige\n";

                  low[node]=min(low[it],low[node]);
            }
            else
            {
                  if(parent!=it)
                  low[node]=min(in[it],low[node]);

                

            }

      }

}

int main()
{
      int node,edge;
      cin >> node >> edge;
      int x,y;
      for(int i=1;i<=edge;i++)
      {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
      }
      dfs(1,-1);
       
      return 0;
}