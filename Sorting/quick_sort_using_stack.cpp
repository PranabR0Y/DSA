#include<bits/stdc++.h>
using namespace std;
int loc;
void quick_sort(int a[],int str,int ed)
{
    int left=str,right=ed;
    loc=str;
    while(1)
    {
       while(a[loc]<=a[right]&&loc!=right)
       {
          right--;

        }
       if(loc==right)break;
       swap(a[loc],a[right]);
       loc=right;
       while(a[left]<=a[loc]&&left!=loc)
       {
          left++;
       }
       if(loc==left)break;
       swap(a[loc],a[left]);
        loc=left;
    }
}
int main()
{
    int a[]={100,-1,8,2,3,0,111,33,55,1901,112,33};
    stack<int>up,low;
    low.push(0);
    up.push(11);
    int top=1,begin,end;
     while(top!=0)
    {
        begin=low.top();
        end=up.top();
        low.pop();
        up.pop();
        top--;
        quick_sort(a,begin,end);
        if(loc-1>begin)
        {
            low.push(begin);
            up.push(loc-1);
            top++;
        }
        if(loc+1<end)
        {
            low.push(loc+1);
            up.push(end);
            top++;
        }

    }
    for(int i=0;i<=11;i++)
    cout << a[i] << " ";


    return 0;
}
