#include<bits/stdc++.h>
using namespace std;
bool prime[1000000];
void seive()
{
    for(int i=2;i*i<=1000000;i++)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
                prime[j]=true;
        }
    }
}
int main()
{
    seive();
    vector<int>vc;
    for(int i=2;i<=1000000;i++)
    {
        if(!prime[i])
        vc.push_back(i);

    }
    int n;
    while(1)
    {
        cin >> n;
        cout << n << "-th prime is " << vc[n-1] << endl;
    }
    return 0;
}
