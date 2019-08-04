#include<bits/stdc++.h>
using namespace std;
bool rangeSum(vector<int> &a,int b,int k)
{
    int s=0;
     for(int i=0;i<a.size();i++)
        {
           if(i>=k)s-=a[i-k];
           s+=a[i];
           if(s>b)return 0;
        }
        return 1;
}

int solve(vector<int> &a, int b) {
    int n=a.size();
    int l=1,r=n;
    int mx=0;
    while(l<=r)
    {
        int mid= l +(r-l)/2;
        if(rangeSum(a,b,mid))
        {
            mx=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int b;
    cin>>b;
    cout<<solve(a,b);
}