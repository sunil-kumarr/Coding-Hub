#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int cur)
{
    int large=cur;
    int r = 2*cur+2;
    int l = 2*cur+1;
    if(l<n && arr[l]<arr[large]){large = l;}
    if(r<n && arr[r]<arr[large]){large = r;}
    if(large!=cur){
        swap(arr[cur],arr[large]);
        heapify(arr,n,large);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1 ; i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  heapsort(arr,n);
  for(int i=0;i<n;i++)
  {
      cout<<arr[i]<<" ";
  }
}