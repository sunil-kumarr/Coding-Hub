#include<bits/stdc++.h>
using namespace std;
int search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) return mid;
        else if(A[0]<=A[mid]){//i.e. left part is sorted
            if(A[0]<=B && B < A[mid]) high = mid-1;//B lies on left part
            else low = mid+1;
        }else{//right part is sorted
            if(A[mid] < B && B<=A[n-1]) low = mid+1;//B lies on right part
            else high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int n,B;
    vector<int> A;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;
      A.push_back(x);
    }
    cin>>B;
    cout<<search(A,B);
}