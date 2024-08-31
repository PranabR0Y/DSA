#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
bool visited[1000];
int in_degree[1000];
unordered_map<int,vector<int>>graph;

bool Cycle_check(int node)
{
    queue<int>q;
    for(int i=1;i<=node;i++)
    if(in_degree[i]==0)q.push(i);

    vector<int>Top;
    while(!q.empty())
    {
        int front=q.front();
       
        Top.push_back(front);
        q.pop();
        for(int i:graph[front])
        {
           
            if(--in_degree[i]==0)
            {
                q.push(i);
               
            }


        }
    }
    if(Top.size()==node)
    return false;
    else
    return true;

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
        in_degree[y]++;
    }
    if(Cycle_check(node))
    cout << "Contain Cycle" << endl;
    else
    cout << "No cycle\n";

    return 0;
}