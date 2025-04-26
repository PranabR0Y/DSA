#include<bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    int price[length];
    for(int i=0;i<length;i++)
    {
        cin >> price[i];

    }
    int dp[length+1]={};
    int Max=-1;
    for(int i=1;i<=length;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]=max(dp[i],price[j-1]+dp[i-j]);
        }
        Max=max(Max,dp[i]);
    }
    cout << Max << endl;
    return 0;
}