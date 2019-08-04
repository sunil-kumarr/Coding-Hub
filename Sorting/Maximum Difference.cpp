#include<bits/stdc++.h>
using namespace std;

solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int s1=0;
    for(int i=1;i<A.size();i++)
    {
        A[i]+=A[i-1];
    }
    int n=A.size()-1;
    if(s1 <abs(A[B-1]-(A[n]-A[B-1])))
    {
        s1 = abs(A[B-1]-(A[n]-A[B-1]));
        // cout<<s1<<endl;
    }
    if(s1 < abs(A[n-B]-(A[n]-A[n-B])))
    {
        s1= abs(A[n-B]-(A[n]-A[n-B]));
        // cout<<A[n-B]<<endl;
    }
    return s1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    int b;
    cin>>b;
    cout<<solve(a,b);
}
