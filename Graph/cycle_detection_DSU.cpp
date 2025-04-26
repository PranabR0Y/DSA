#include<bits/stdc++.h>
using namespace std;
int find(int a,int parent[]){
    if(parent[a]!=a){
        parent[a]=find(parent[a],parent);

    }
    return parent[a];
}
void unite(int parent[],int a,int b)
{
    int parent_a=find(a,parent);
    int parent_b=find(b,parent);
    if(parent_a!=parent_b){
        parent[parent_b]=parent_a;
    }
    else {
        cout<<"Cycle detected between " << a << " " << b <<endl;
    }
}
void create(int parent[],int n,vector<pair<int,int>>edges)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<edges.size();i++)
    {
        unite(parent,edges[i].first,edges[i].second);
    }
    

}

int main()
{
    vector<pair<int,int>>edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {3, 7}, {7, 8}, {8, 9},{2,9}};
    int n=11;
    int parent[n];
    create(parent,n,edges);
    cout << "Parent of  9 " << find(9,parent) << endl;
    
    return 0;
}