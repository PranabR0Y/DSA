#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a[]={100,19,-1,2,5,2,3,10};
        for(int i=1;i<8;i++)
        {
                int value=a[i];
                int free_space=i;
                while(free_space>0&&a[free_space-1]>value)
                {
                        a[free_space]=a[free_space-1];
                        free_space--;
                }
                a[free_space]=value;
        }
        for(int i=0;i<8;i++)
        cout << a[i] << " ";
        return 0;
}