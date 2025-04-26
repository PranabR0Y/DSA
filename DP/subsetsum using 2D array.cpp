#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin >> n >> sum ;
    int a[100];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    bool dp[n+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<a[i])
                dp[i][j]=dp[i-1][j];
            else
            {
                int extra=j-a[i];
                if(dp[i-1][extra]||dp[i-1][j])
                    dp[i][j]=true;
                    else
                        dp[i][j]=false;
            }
        }
    }
    if(dp[n][sum])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
