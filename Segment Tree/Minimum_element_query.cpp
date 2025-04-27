#include<bits/stdc++.h>
using namespace std;
const int n=2e5+2;
int tree[4*n];
void build(int current_index,int st_index,int en_index,int a[])
{
    if(st_index==en_index){
        tree[current_index]=a[st_index];//leaf node
        return;
    }
    int mid=(st_index+en_index)/2;
    build(2*current_index,st_index,mid,a);
    build(2*current_index+1,mid+1,en_index,a);
    tree[current_index]=min(tree[2*current_index],tree[2*current_index+1]);
}
int Query(int current_index,int st_index,int en_index,int l,int r)
{
    if(st_index>r||en_index<l)return INT_MAX;

    if(st_index>=l&&en_index<=r)return tree[current_index];
    int mid=(st_index+en_index)/2;

    int Min_left=Query(2*current_index,st_index,mid,l,r);
    int Min_right=Query(2*current_index+1,mid+1,en_index,l,r);
    return min(Min_left,Min_right);

}
void Update(int current_index,int st_index,int en_index,int index,int a[])
{
    if(st_index==en_index)
    {
        tree[current_index]=a[st_index];
        return;
    }
    int mid=(st_index+en_index)/2;
    if(index<=mid)Update(2*current_index,st_index,mid,index,a);// check weather given index fall in right or left subtree
    else Update(2*current_index+1,mid+1,en_index,index,a);

    tree[current_index]=min(tree[2*current_index],tree[2*current_index+1]);
}
int main()
{
    int a[]={1,2,3,4,1,2,4,5,0,1};
    build(1,0,9,a);
    /* for(int i=0;i<4*10;i++)
    cout << tree[i] << ' '; */
    int l,r;
    cin >> l >> r;
    cout << Query(1,0,9,l,r) << endl;

    
    
    return 0;
}