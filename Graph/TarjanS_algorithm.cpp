#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100];
int timer,discovery[100],low[100];
bool onStack[100],vis[100];
stack<int>st;
void dfs(int node)
{
        vis[node]=true;
        discovery[node]=low[node]=timer++;
        onStack[node]=true;
        st.push(node);
        for(int child:vc[node])
        {
                if(vis[child]&&onStack[child])
                {
                        low[node]=min(discovery[child],low[node]);

                }
                else if(!vis[child])
                {
                        dfs(child);
                        if(onStack[node])
                        {
                                low[node]=min(low[child],low[node]);
                        }


                }

        }
        if(low[node]==discovery[node])
        {
                
                while(1)
                {
                        cout << st.top() << " ";
                        if(st.top()==node)
                        {

                                onStack[st.top()]=false;
                                st.pop();
                                break;

                        }
                        else
                        onStack[st.top()]=false,st.pop();

                }
                cout << endl;
        }


        
}
int main()
{
     int node,edge,x,y;
     cin >> node >> edge;
     for(int i=0;i<edge;i++)
     cin >> x >> y,vc[x].push_back(y);
     for(int i=1;i<=node;i++)
     if(!vis[i]) dfs(i);
     
     return 0;
     

}