#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
        
        int left[m-l+1],right[r-m],j=0;
        for(int i=l;i<=m;i++)
        left[j++]=a[i];
        j=0;
        for(int i=m+1;i<=r;i++)
        right[j++]=a[i];
        int i=0,left_ptr=l,right_ptr=m+1,k=l;
        j=0;
        while(left_ptr<=m&&right_ptr<=r)
        {
                if(left[i]<=right[j])
                {
                        a[k++]=left[i++];
                        left_ptr++;
                }
                else
                {
                        a[k++]=right[j++];
                        right_ptr++;
                }
        }
        while(left_ptr<=m)
        {
                a[k++]=left[i++];
                left_ptr++;
        }
        while(right_ptr<=r)
        {
                a[k++]=right[j++];
                right_ptr++;
        }

}
void merge_sort(int a[],int left,int right)
{
        int mid;
        if(left>=right)return;
        mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
}
int main()
{
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        merge_sort(a,0,n-1);
        for(int i=0;i<n;i++)
        cout << a[i] << " ";
        
        return 0;
}