#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>vc={-6,-1  ,-6 ,-1 ,-4  ,-5 ,-4};
    int Max_till_now=INT_MIN,Max_curr=0,End=0,start=0,temp=0;
    for(int i=0;i<vc.size();i++)
    {
        Max_curr+=vc[i];
        if(Max_curr>Max_till_now)
        {
            start=temp;
            Max_till_now=Max_curr;
            End=i;
        }


        if(Max_curr<0)
            Max_curr=0,temp=i+1;
    }
    cout << Max_till_now << endl;
    cout << "start postition " << start << "\nEnding position " << End << endl;
    return 0;
}
