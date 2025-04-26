#include<bits/stdc++.h>
using namespace std;
int dp[50][50],ar[50][50];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin >> ar[i][j];
    }
    for(int i=1;i<=m;i++)
        dp[n+1][i]=INT_MAX;
    for(int i=1;i<=n;i++)
        dp[i][m+1]=INT_MAX;
    dp[n][m+1]=dp[n+1][m]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            dp[i][j]=(ar[i][j]+min(dp[i+1][j],dp[i][j+1]));
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}
