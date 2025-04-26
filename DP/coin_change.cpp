#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>coins={1,2,5,10,20,50,100,500,1000};
    int sum=3806;
    int dp[sum+1];
    dp[0]=0;

    for(int i=1;i<=sum;i++)
    {
        int ans=INT_MAX;
        dp[i]=ans;
        for(int j=0;j<coins.size();j++)
        {
            if(coins[j]<=i)
            {
                ans=min(ans,dp[i-coins[j]]);
            }
        }
        if(ans!=INT_MAX)
            dp[i]=ans+1;
    }
    cout << dp[sum] << endl;
    /*for(int i=0;i<=sum;i++)
        cout << dp[i] << endl;*/

    return 0;
}
