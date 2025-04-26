#include<bits/stdc++.h>
using namespace std;// finding a path from any cell of first row to go in last row in any cell which minimize/maximize cost
int a[50][50],dp[50][50];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    for(int i=1;i<=m;i++)
        dp[n][i]=a[n][i];
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==1)
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            else if(j==m)
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j-1]);
            else
            {
                int temp=min({dp[i+1][j],dp[i+1][j+1],dp[i+1][j-1]});
                dp[i][j]=a[i][j]+temp;
            }
        }
    }
    for(int i=1;i<=n;i++)//now print min from dp first row
    {
        for(int j=1;j<=m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}
