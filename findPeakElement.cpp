#include<bits/stdc++.h>
using namespace std;
int find_peak(int n,int arr[])
{
    if(n==0)return 0;
    if(n==1)return arr[0];
    int great=arr[0];
    for(int i=1;i<n-1;i++)
    {
        if(great<=arr[i])
        {
            if(arr[i]>=arr[i+1]){
                great = arr[i];
            }
        }
    }
    if(arr[n-1]>great)great=arr[n-1];
    return great;
}
int binary_find(int n,int l,int r,int arr[])
{
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(mid==0) return arr[0];
        else if(mid==n-1)return arr[n-1];
        else if (arr[mid]>= arr[mid-1] && arr[mid]>=arr[mid+1])return arr[mid];
        else if (arr[mid]>=arr[mid-1] && arr[mid]<arr[mid+1])l=mid+1;
        else if (arr[mid]>=arr[mid+1] && arr[mid]<arr[mid-1])r=mid-1;
        else l=mid+1;
    }
   return arr[l];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<find_peak(n,arr);
    cout<<binary_find(n,0,n-1,arr);
}