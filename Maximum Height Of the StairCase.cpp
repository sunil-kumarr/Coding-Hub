#include<bits/stdc++.h>
using namespace std;
solve(int A) {
    int l=0,r=A;
    int mx=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(1LL*mid*(mid+1)>>1>A)r=mid-1;
        else {
            mx=mid;
            l=mid+1;
        }
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
}