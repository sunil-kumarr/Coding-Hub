#include<bits/stdc++.h>
using namespace std;

// O(30*n*log(m))

int findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int l=INT_MAX,r=INT_MIN;
    // find the min and max value in matrix to have a binary search range
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            l=min(l,A[i][j]);
            r=max(r,A[i][j]);
        }
    }
    // find the median index
    int median = (n*m+1)>>1;
    while(l<r)
    {
        int mid=l+r>>1;
        // find all smaller numbers than the mid in matrix
        int smaller=0;
        for(int i=0;i<n;i++)
        {
            smaller+=(upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        // if smaller numbers are less than median increase the left
        if(smaller<median)l=mid+1;
        // otherwise change right to mid
        else r=mid;
    }
    // l will be the ans as l and r not only range but candidates for answer
    return l;
}

int main()
{
    vector<vector<int> > A;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
          int x;cin>>x;
          A[i].push_back(x);
        }
    }
    cout<<findMedian(A);
}