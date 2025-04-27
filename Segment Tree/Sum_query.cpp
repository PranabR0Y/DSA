#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int tree[4*N];
void build(int current_index,int st_index,int en_index,int a[])
{
    if(st_index==en_index)
    {
        tree[current_index]=a[st_index];
        return;
    }
    int mid=(st_index+en_index)/2;
    build(current_index*2,st_index,mid,a);//result of left subtree will be at 2*current_index
    build(current_index*2+1,mid+1,en_index,a);//result of right subtree will be at 2*current_index+1
    tree[current_index]=tree[current_index*2]+tree[2*current_index+1];//after left and right calculated their result root will calculate his own result using 2 of them


}
int sum_query(int curren_index,int st_index,int en_index,int l,int r)
{
    if(l>en_index||r<st_index)// l and r is out of range  (l.....r...st_index ...en_index) OR (st_index...en_index....l....r)
    return 0;
    if(st_index>=l&&en_index<=r)// start and end lies between l and r.example: l....st_index...en_index...r
    return tree[curren_index];

    // Now for partial segment l...s..r..end OR s...l..end...r

    int mid=(st_index+en_index)/2;
    int t1=sum_query(2*curren_index,st_index,mid,l,r);
    int t2=sum_query(2*curren_index+1,mid+1,en_index,l,r);
    return t1+t2;


}
void Update(int current_index,int st_index,int en_index,int index,int a[])
{
   if(st_index==en_index)
   {
	  tree[current_index]=a[st_index];
      return;
    
   }
   int mid=(st_index+en_index)/2;
   if(index<=mid)Update(2*current_index,st_index,mid,index,a);
   else Update(2*current_index+1,mid+1,en_index,index,a);

   tree[current_index]=tree[2*current_index]+tree[2*current_index+1];

}
int main()
{
    int a[]={1,2,3,4,1,2,4,5,0,1};
    build(1,0,9,a);// here root will be at index 1 not 0.
    int l,r;
    cin >> l >> r;
    cout << sum_query(1,0,9,l,r) << endl;

    int index,value;
    cin >> index >> value;
    a[index]=value;
    Update(1,0,9,index,a);
    cout << value << endl;
    cin >> l >> r ;
    cout << sum_query(1,0,9,l,r) << endl;
    

    
    return 0;
}