#include<bits/stdc++.h>

using namespace std;
int Mod(int x,int n,int mod)
{
    if(n==0)
         return 1;
    else if(n%2==0)
    {
        long temp=Mod(x,n/2,mod);
        return (temp*temp)%mod;
    }
    else
       return ((x%mod)*Mod(x,n-1,mod)%mod)%mod;
}
int main()
{
    while(1)
    {
    cout << "Enter x and n and MOD" << endl;
    cin >> x >> n >> MOD;
    cout << x << "^" << n << " % "<< MOD <<" = " << Mod(x,n,MOD) << endl;
    }
    return 0;
}