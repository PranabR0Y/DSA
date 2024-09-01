#include<bits/stdc++.h>
#define MX 500001
using namespace std;
bool is_prime[MX];
void seive()
{
    for(int i=2;i*i<=MX;i++)
    {
        if(!is_prime[i])
        {
            for(int j=i*i;j<=MX;j+=i)
                is_prime[j]=true;
        }
    }
}
int main()
{
    seive();
    int n;
    while(1)
    {
        cin >> n;
        if(!is_prime[n])
            cout << n << " is prime\n";
        else
            cout << n << " Not prime\n";
    }
    return 0;
}
