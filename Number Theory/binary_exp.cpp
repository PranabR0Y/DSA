#include<bits/stdc++.h>
using namespace std;
int power(int base,int power)
{
    int result=1;
    if(power==0)
    {
        return 1;
    }
    while(power>1)
    {
        if(power&1)
        {
            result*=base;
            power--;
        }
        else
        power/=2,base*=base;

    }
    return result*base;
    
}
int main()
{
    int b,p;
    cin >> b >>p;
    cout << power(b,p) << endl;
   
    return 0;
}
