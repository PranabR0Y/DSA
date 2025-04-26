#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={3,0,2,1,1};
    int total_subset=1<<5;
    for(int i=0;i<total_subset;i++)
    {
        for(int j=0;j<5;j++)
        {
            int temp=1<<j;
            if(temp&i)
                cout << a[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
