#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(dp[i-1]<0)
                dp[i]=nums[i];
            else
                dp[i]=nums[i]+dp[i-1];
        }
        return *max_element(dp,dp+nums.size());
}
int main()
{
    vector<int>vc={-4,-2,-1,-3,-5};
    cout << maxSubArray(vc) << endl;

    return 0;
}
