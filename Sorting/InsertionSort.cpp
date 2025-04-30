#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=20000;
    clock_t start,end;
    start=clock();
    int a[n];
    ifstream read("output.txt");
    
    int i=0;
    string s;
    while(getline(read,s))
    {
        int value=0;
        stringstream ss(s);
        ss >> value;
        
        a[i++]=value;


    }
    
    for(int i=1;i<n;i++)
    {
          int key=a[i],j=i-1;
          while(j>=0&&a[j]>key)
     	{
		    int temp=a[j];
		    a[j]=key;
		    a[j+1]=temp;
		    j--;
        }

	}
   
    end=clock();
    cout << double(end-start) << endl;
    
   
    return 0;
}