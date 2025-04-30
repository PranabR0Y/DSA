#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>v,int data)
{
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==data)
            return mid;
        else if(v[mid]<data)
        {
            low=mid+1;
        }
        else
            high=mid-1;
    }

}
int main()
{
    vector<int>vc={2,4,10,1,5,3,0,-1,-2,100,200};
    for(int i=0;i<vc.size();i++)
    {
        for(int j=0;j<vc.size()-i-1;j++)
            if(vc[j]>vc[j+1])
            swap(vc[j],vc[j+1]);
    }
    for(int i=0;i<vc.size();i++)
        cout << vc[i] << endl;
    cout << binary_search(vc,200)+1 << endl;
    return 0;
}
