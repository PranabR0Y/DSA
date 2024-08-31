//undirected graph
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<pair<int,long long>>>graph;
long long dp[100][100];
void warshall(int node)
{
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(i==j)dp[i][j]=0;
            else dp[i][j]=LONG_MAX;
        }
    }
    for(int i=1;i<=node;i++)
    {
        
        for(pair<int,int>j:graph[i])
        {
            int n=j.first;
            long long c=j.second;
            dp[i][n]=min(dp[i][n],c);//for multiple direct path
        }

    }
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(j==i)continue;
            for(int k=1;k<=node;k++)
            {
                if(k==i||dp[j][i]==LONG_MAX||dp[i][k]==LONG_MAX)continue;   
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    
    }
    
    


}
int main()
{
    int node,edge,x,y,q;
    long long z;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        cin >> x >> y >> z;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    
    warshall(node);
    
    return 0;
}