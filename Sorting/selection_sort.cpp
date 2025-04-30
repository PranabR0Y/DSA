#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a[]={77,33,44,11,88,22,66,55};
       
        for(int i=0;i<8-1;i++)
        {
                int index=i;

                for(int j=i+1;j<8;j++)
                if(a[index]>a[j])index=j;

                if(index!=i)
                swap(a[i],a[index]);

        }
        for(int i=0;i<8;i++)
        cout << a[i] << " ";
        return 0;
}