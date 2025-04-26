#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row=1,col=1;
    cin >> row >> col ;
    int dp[row][col];

    for(int i=0;i<col;i++)
        dp[row-1][i]=1;
    for(int i=0;i<row;i++)
        dp[i][col-1]=1;

    for(int i=row-2;i>=0;i--)
    {
        for(int j=col-2;j>=0;j--)
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
    }
    cout << dp[0][0] << endl;

    return 0;

}
