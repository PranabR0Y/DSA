#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,vector<int>>graph;
int flag[100];
bool dfs(int node)
{
    flag[node]=0;//in stack
    for(int i:graph[node])
    {
        if(flag[i]==0)return true;
        else if(flag[i]==-1)
        {
            if(dfs(i))return true;
          
        }
    }
    flag[node]=1;//visited and out of stack
    return false;

}
int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=0;i<100;i++)flag[i]=-1;//unvisited
    for(auto it:graph)
    {
        if(flag[it.first]==-1)
        {
            if(dfs(it.first))
            {
                cout << "Contain Cycle\n";
                return 0;
            }
        }
    }
    cout <<  "No Cycle\n";


    return 0;
}