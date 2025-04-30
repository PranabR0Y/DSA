#include<bits/stdc++.h>
using namespace std;
int partition(int left,int right,int a[])
{
    int pivot=a[left],j=left,i=right;
    while(1)
    {
        while(a[j]<=pivot&&j<=i)
        {
            j++;
        }
        while(a[i]>pivot)
        {
            i--;

        }
        if(i>j)
        swap(a[i],a[j]);
        if(j>i){
            swap(a[left],a[i]);
            break;
        }
    }
    return i-1;


}
void quicksort(int l, int r, int a[])
{
    while(l<r)
    {
        int p=partition(l,r,a);
        quicksort(l,p-1,a);
        quicksort(p+1,r,a);
    }
}
int main()
{
    int a[]={2,1,4,5,7,6};
    quicksort(0,5,a);
    for (int i:a)
    cout << i << endl;
    return 0;
}