#include<bits/stdc++.h>
using namespace std;
#define Max 100001
bool prime[Max];
void seive()
{
    for(int i=i;i*i<=Max;i++)
    {
        if(!prime[i])
        for(int j=i*i;j<=Max;j+=i)
        prime[j]=true;
    }
    
}
void seg_seive(int l,int r)
{
    l==1?l+=1:l=l;
    int size=r-l+1;
    bool temp[size]={};
    for(int i=2;i*i<=r;i++)
    {
        if(!prime[i])
        {
            int t=(l/i)*i;
            if(t<l)t+=i;
            while(t<=r)
            {
                if(t!=i)
                temp[t-l]=1;
                t+=i;
            }

        }
    }
    for(int i=0;i<size;i++)
    if(!temp[i])
    cout << l+i << '\n';
    cout << '\n';
}
int main()
{
  
    
    seive();
    int t;
    cin >> t;
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        seg_seive(l,r);
    }
    return 0;
}