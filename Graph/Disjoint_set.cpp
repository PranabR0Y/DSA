#include<bits/stdc++.h>
using namespace std;
int find(int a,int parent[])
{
    if(parent[a]!=a){
        parent[a]=find(parent[a],parent);
    }
    else
       return parent[a];
    
}
void unite(int parent[],int a,int b)
{
    int parent_a=find(a,parent);
    int parent_b=find(b,parent);
    if(parent_a!=parent_b)
    {
        parent[parent_b]=parent_a;
    }
}
void create (int parent[],int n,vector<pair<int,int>> edges)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;//initially all are parent of themselves
    }

    for(int i=0;i<edges.size();i++)
    {
        unite(parent,edges[i].first,edges[i].second);
    }
   
}

int main()
{
    int n=11;
    int parent[n];
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {3, 7}, {7, 8}, {8, 9}, {2, 9}};
    create(parent,n,edges);
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout << "Find(1): " << find(1, parent) << endl;
    cout << "Find(2): " << find(2, parent) << endl;
    cout << "Find(3): " << find(3, parent) << endl;
    cout << "Find(7): " << find(7, parent) << endl;
    cout << "Find(9): " << find(9, parent) << endl;
    cout << "Find(4): " << find(4, parent) << endl;
    cout << "Find(6): " << find(6, parent) << endl;

    cout << "Are 1 and 9 connected? " << (find(1, parent) == find(9, parent) ? "Yes" : "No") << endl;
    cout << "Are 4 and 6 connected? " << (find(4, parent) == find(6, parent) ? "Yes" : "No") << endl;
    cout << "Are 1 and 6 connected? " << (find(1, parent) == find(6, parent) ? "Yes" : "No") << endl;

    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {4, 5}, {6, 7}, {5,6}, {3,7}};
    int parent2[n];

    create(parent2, 8, edges2);
    for(int i=1;i<8;i++)
    {
        cout<<parent2[i] << " ";
    }
    cout << endl;
    cout << "Find(1): " << find(1, parent2) << endl;
    cout << "Find(2): " << find(2, parent2) << endl;
    cout << "Find(3): " << find(3, parent2) << endl;
    cout << "Find(7): " << find(7, parent2) << endl;
    cout << "Find(4): " << find(4, parent2) << endl;
    cout << "Find(6): " << find(6, parent2) << endl;

     for(int i=1;i<8;i++)
    {
        cout<<parent2[i] << " ";
    }

    return 0;
}