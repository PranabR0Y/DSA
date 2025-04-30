#include<bits/stdc++.h>
using namespace std;
bool ok;
void print_heap(int a[],int size)
{
      for(int i=1;i<=size;i++)
      cout << a[i] << " ";
      cout << endl;
}
void heapify(int temp[],int size,int i)
{
      int left=2*i;
      int right=2*i+1,largest=i;
      if(left<=size&&temp[i]<temp[left])
      largest=left;
      
      if(right<=size&&temp[largest]<temp[right])
      largest=right;
      if(i!=largest)
      {
            swap(temp[largest],temp[i]);
            heapify(temp,size,largest);
      }
      if(!ok)
      print_heap(temp,size);
}

int main()
{
      int heapSize=9,tempSize=heapSize;
      int heap[]={-1,12,7,1,3,10,17,19,2,5};
      for(int i=heapSize/2;i>=1;i--)
      heapify(heap,heapSize,i),cout << endl;
      print_heap(heap,heapSize);
      ok=true;
      for(int i=heapSize;i>1;i--)
      {
            swap(heap[1],heap[tempSize]);
            heapify(heap,--tempSize,1);
            
      }
      print_heap(heap,heapSize);

      return 0;
}