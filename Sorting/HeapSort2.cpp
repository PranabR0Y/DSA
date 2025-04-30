#include<bits/stdc++.h>
using namespace std;
void Insert(int a[],int size,int data)
{
      size++;
      int ptr=size;
      while(ptr>1)
      {
            int parent=ptr/2;
            if(a[parent]<data)
            {
                  int temp=a[parent];
                  a[parent]=data;
                  a[ptr]=temp;
                  ptr=parent;
            }
            else
            {
                  a[ptr]=data;
                  return;
            }
      }
      a[ptr]=data;//setting as root 
}
void print_heap(int a[],int size)
{
      for(int i=1;i<=size;i++)
      cout << a[i] <<" ";
      cout << endl;
}
void  del(int a[],int size,int item)
{
      int last=a[size];
      a[size]=item;
      size--;
      int curr_loc=1,right=2*1+1,left=2*1;
      while(right<=size)
      {
            if(last>=a[left]&&last>=a[right])
            {
                  a[curr_loc]=last;
                  return;
            }
            else if(a[left]>=a[right])
            {
                  a[curr_loc]=a[left];
                  curr_loc=left;
            }
            else
            {
                  a[curr_loc]=a[right];
                  curr_loc=right;
            }
            right=2*curr_loc+1;
            left=2*curr_loc;
      }
     
      if(left==size&&last<a[left])
      {
           a[curr_loc]=a[left];
           curr_loc=left;
           
      }
     
      a[curr_loc]=last;
     
      


}

int main()
{
      int heapSize=9,tempSize=heapSize;
      int a[]={-1,12,7,1,3,10,17,19,2,5};
      for(int i=0;i<heapSize;++i)
      Insert(a,i,a[i+1]);
      print_heap(a,heapSize);
      for(int i=heapSize;i>1;i--)
      {
            del(a,i,a[1]);
            
      }

      print_heap(a,heapSize);
      
      return 0;
}