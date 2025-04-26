#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin >> n >> sum;
    int a[n];
    bool dp[sum+1];
    for(int i=0;i<n;i++)
        cin >> a[i];
    dp[0]=1;
    for(int i=1;i<=sum;i++)
        dp[i]=false;
    for(int i=0;i<n;i++)
    {
        int temp=a[i];
        for(int j=sum;j>=temp;j--)
        {
            if(dp[j]||dp[j-temp])
                dp[j]=true;

        }
    }
    for(int i=0;i<=sum;i++)
        cout << dp[i] << " ";
    return 0;
}
