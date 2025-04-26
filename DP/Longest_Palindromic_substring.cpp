#include<bits/stdc++.h>
using namespace std;
bool dp[100][100];
int main()
{
    string s="x",s2;
    cin >> s2;
    s+=s2;
    int size=s.size();
    for(int i=0;i<size;i++)
        dp[0][i]=1;
    
    for(int i=1;i<size;i++)
        dp[1][i]=1;

    for(int i=2;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int start=j-i+1;
            int end=j;
            if(s[start]==s[end])
            {
                if(dp[i-2][j-1])
                dp[i][j]=1;
            }
        }
    }
    //for(int i=0;i<size;i++)
    //{
    //    for(int j=0;j<size;j++)
    //    cout << dp[i][j] << ' ';
    //    cout << endl;
    //    
    //} 

    for(int i=size-1;i>0;i--)
    {

        for(int j=0;j<size;j++)
        if(dp[i][j])
        {
            cout << "Max length " << i << endl;
            for(int k=j-i+1;k<=j;k++)
            cout << s[k];
            return 0;
        }
    }

        
    

    return 0;
}