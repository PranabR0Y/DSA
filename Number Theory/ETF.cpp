#include<bits/stdc++.h>
using namespace std;
int ETF(int n)
{
    int result=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            result*=i-1;
            result/=i;
            while(n%i==0)
            n/=i;
        }

    }
    if(n>1)
    result*=n-1,result/=n;
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    cout << ETF(n) << endl;}
    return 0;
}