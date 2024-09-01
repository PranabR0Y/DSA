#include<bits/stdc++.h>
using namespace std;
int Binary_exp(int base,int power,int mod)
{
    int result=1;
    while(power)
    {
        if(power&1)
        {
            result*=base;
            power--;

        }
        else
        {
            base*=base;
            power/=2;
        }
    }
    return result%mod;
}
int main()
{
    int a,b,m;
    cin >> a >> m;
    cout << "a^-1 =" << Binary_exp(a,m-2,m) << endl;/*ONly works when m is prime*/
    return 0;
}
