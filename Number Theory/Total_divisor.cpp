#include<bits/stdc++.h>
using namespace std;
int factor(int n)
{
    long long divisor=1;
    for(int i=2;i*i<=n;i++)
    {
        int c=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                c++;
                n/=i;
            }

        }
        divisor*=(c+1);

    }
    if(n>1)
    divisor*=2;
    return divisor;
}
int main()
{
    long long  n;
    while(1)
    {
    cin >> n;
    cout << "total divisor of " << n << " is " << factor(n) << endl;
    }
    return 0;
}