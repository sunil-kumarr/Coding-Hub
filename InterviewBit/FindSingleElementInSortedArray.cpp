#include<bits/stdc++.h>
using namespace std;

int array_xor(int n,int arr[])
{
  int ans=arr[0];
  for(int i=1;i<n;i++)ans=ans xor arr[i];
  return ans;
}

int binary_element(int n,int arr[])
{
   int l=0,r=n-1;
   while ( l<=r)
   {
       int mid=l+(r-l)/2;
       if((mid+1)%2==0 and arr[mid] == arr[mid-1])l=mid+1;
       else if((mid+1)%2!=0 and arr[mid] == arr[mid+1])l=mid+1;
       else r=mid-1;
   }
   return arr[l];
}

int main()
{
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)cin>>arr[i];
      cout<<binary_element(n,arr);
}