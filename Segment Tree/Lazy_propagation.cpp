#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tree[4*N];
int Lazy[4*N];
void build(int c_index,int s_index,int en_index,int a[])
{
    if(s_index==en_index)
    {
        tree[c_index]=a[s_index];
        return;
    }
    int mid=(s_index+en_index)/2;
    build(2*c_index,s_index,mid,a);
    build(2*c_index+1,mid+1,en_index,a);
    tree[c_index]=tree[2*c_index]+tree[2*c_index+1];
}
void lazy_Update(int c_index,int s_index,int en_index,int l,int r,int value)
{
    if(Lazy[c_index]!=0)
    {
            int elements=en_index-s_index+1;
            tree[c_index]+=Lazy[c_index]*elements;
            if(s_index!=en_index)
            {
                  Lazy[2*c_index]+=Lazy[c_index];
                  Lazy[2*c_index+1]+=Lazy[c_index];
            }
            Lazy[c_index]=0;
    }
    if(s_index>r||en_index<l)return;
    
    else if(s_index>=l&&en_index<=r)
    {
        int elements=en_index-s_index+1;
        tree[c_index]+=(elements)*value;
        Lazy[2*c_index]+=value;
        Lazy[2*c_index+1]+=value;
        return;

    }
    else
    {
        int mid=(s_index+en_index)/2;
        lazy_Update(2*c_index,s_index,mid,l,r,value);
        lazy_Update(2*c_index+1,mid+1,en_index,l,r,value);
        tree[c_index]=tree[2*c_index]+tree[2*c_index+1];
    }


}
int query(int c_index,int s_index,int en_index,int l,int r)
{
    if(Lazy[c_index]!=0)
    {
            int elements=en_index-en_index+1;
            tree[c_index]+=Lazy[c_index]*elements;
            if(s_index!=en_index)
            {
                  Lazy[2*c_index]+=Lazy[c_index];
                  Lazy[2*c_index+1]+=Lazy[c_index];
            }
            Lazy[c_index]=0;
    }
    if(s_index>r||en_index<l)
    {
       
        return 0;
    }
   
    else if(s_index>=l&&en_index<=r)
    {
        
        return tree[c_index];
    }
    else
    {
         int mid=(s_index+en_index)/2;
         return query(2*c_index,s_index,mid,l,r)+query(2*c_index+1,mid+1,en_index,l,r);

    }
}
int main()
{
    int a[]={1,2,3,4,1,2,4,5,0,1};
    build(1,0,9,a);// here root will be at index 1 not 0.
    int l=0,r=5,value=5;
    

    cout <<  query(1,0,9,l,r) << endl;//1,2,3,4,1,2,4,5,0,1

    lazy_Update(1,0,9,l,r,value);//6 7 8 9 6 7 4 5 0 1

    cout << query(1,0,9,l,r) << endl;

    lazy_Update(1,0,9,1,7,3);//6 10 11 12 9 10 7 8 0 1

    cout << query(1,0,9,2,9) << endl;//11 12 9 10 7 8 0 1
    cout << query(1,0,9,0,9) << endl;//6 10 11 12 9 10 7 8 0 1

    return 0;
}