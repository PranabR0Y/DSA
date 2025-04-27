#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>tree(100);
void build(int c,int s,int e,int a[])
{
    if(s==e)
    {
        tree[c].push_back(a[s]);
        return;

    }
    int mid=(s+e)/2;
    build(2*c,s,mid,a);
    build(2*c+1,mid+1,e,a);
    int i=0,j=0;
    while(i<tree[2*c].size()&&j<tree[2*c+1].size())
    {
        if(tree[2*c][i]<tree[2*c+1][j])
        {
            tree[c].push_back(tree[2*c][i]);i++;
        }
        else tree[c].push_back(tree[2*c+1][j]),j++;
    }
    while(i<tree[2*c].size())
    {
        tree[c].push_back(tree[2*c][i]);i++;
    }
    while(j<tree[2*c+1].size())
    {
        tree[c].push_back(tree[2*c+1][j]);j++;
        
    }
}
int query(int c,int s,int e,int value,int l,int r)
{
   if(l>e||r<s)return 0;
   else if(s>=l&&e<=r)
   {
         return tree[c].size()-(upper_bound(tree[c].begin(),tree[c].end(),value)-tree[c].begin());
        
   }
   int mid=(s+e)/2;

   return query(2*c,s,mid,value,l,r)+query(2*c+1,mid+1,e,value,l,r);

   
    

}
int main()
{
    int a[]={1,4,3,5,6,4,3,2};
    build(1,0,7,a);

    cout << query(1,0,7,6,0,7) << endl;
  

    
    
    return 0;
}