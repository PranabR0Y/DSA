#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int tree[4*N];
void build(int c_index,int st_index,int en_index,int a[])
{
    if(st_index==en_index)
    {
        tree[c_index]=a[st_index];//leaf node
        return;
    }
    int mid=(st_index+en_index)/2;
    build(2*c_index,st_index,mid,a);
    build(2*c_index+1,mid+1,en_index,a);
    tree[c_index]=tree[2*c_index]^tree[2*c_index+1];

}
int Xor(int c_index,int st_index,int en_index,int l,int r)
{
    if(r<st_index||l>en_index)return 0;
    else if(l<=st_index&&r>=en_index) return tree[c_index];
    else
    {
        int mid=(st_index+en_index)/2;
        int x1=Xor(2*c_index,st_index,mid,l,r);
        int x2=Xor(2*c_index+1,mid+1,en_index,l,r);
        return x1^x2;
        
    }
}
void Update(int c_index,int st_index,int en_index,int index,int a[])
{
    if(st_index==en_index)
    {
        tree[c_index]=a[st_index];//leaf node
        return;
        
    }
    else
    {
        int mid=(st_index+en_index)/2;
        if(index<=mid)Update(2*c_index,st_index,en_index,index,a);
        else Update(2*c_index+1,mid+1,en_index,index,a);
        tree[c_index]=tree[2*c_index]^tree[2*c_index+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    build(1,0,n-1,a);
    int l,r;
    while(q--)
    {
        cin >> l >> r;
        cout << Xor(1,0,n-1,l-1,r-1) << '\n';
    }
    return 0;
}