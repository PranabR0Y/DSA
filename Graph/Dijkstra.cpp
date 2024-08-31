#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<int,vector<pair<int,int>>>graph;
bool visited[100005];
void dijkstra(int source,ll d[])
{
    d[source]=1;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;

    q.push({0,source});
    while(!q.empty())
    {
        pair<ll,int>Top=q.top();
        int parent=Top.second;
        ll currentCost=Top.first;
        q.pop();
        if(visited[parent])continue;
        visited[parent]=1;
        for(pair<int,int>i:graph[parent])
        {
            int child=i.first;
            ll child_cost=i.second;
            ll Visit_cost=d[parent]+child_cost;
            if(Visit_cost<d[child])
            {
                d[child]=Visit_cost;
                q.push({Visit_cost,child});
            }
        }
    }

}
int main()
{
    int node,edge;
	cin >> node >> edge;
	int x,y,z;
    ll d[node+1];
    for(int i=1;i<=node;i++)
    d[i]=LLONG_MAX;

	for(int i=0;i<edge;i++)
	{
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
    dijkstra(0,d);
    for(int i=0;i<=node;i++)
    cout << d[i] << ' ';
  
    return 0;
}