#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>graph;
template<class X>
void print(const X a)
{
    for(auto i:a)
    cout << i << ' ';
    cout << endl;
}
bool visited[100];
int destination,source;
vector<int>path;
void dfs(int node)
{
    path.push_back(node);
    visited[node]=1;
    if(node==destination)
    print(path);
    for(int child:graph[node])
    {
        if(!visited[child])dfs(child);
    }
    visited[node]=false;
    path.pop_back();
    

}

int main()
{
    int node,edge;
    cin >> node >> edge;
    int x,y;
    for(int i=0;i<edge;i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);

    }
    source=0;
    destination=node-1;
    dfs(source);
   
    
    
    return 0;
}
