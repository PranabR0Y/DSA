#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>vc(10001);
int in[10001];
vector<int>top;
void kahns(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        top.push_back(front);
        for(int i:vc[front])
        {
            in[i]--;
            if(in[i]==0)
            q.push(i);

        }
    }
}
int main()
{
    
    int node,edge,x,y;
    cin >>node >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y;
        vc[x].push_back(y);
        in[y]++;
    }
    kahns(node);
    if(top.size()==0)
    cout << "Sandro fails\n";
    else
    for(int i:top)
    cout << i << " ";
    
    return 0;
}