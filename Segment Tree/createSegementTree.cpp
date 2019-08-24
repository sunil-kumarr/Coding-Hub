#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int constructSTUtill(vector<int> &arr,int start,int end,int *st,int current)
{
    if(start==end)
    {
        st[current]=arr[start];
        return arr[start];
    }
    int mid = (start+(end-start)/2);
    st[current]=constructSTUtill(arr,start,mid,st,current*2+1)+
                constructSTUtill(arr,mid+1,end,st,current*2+2);
    return st[current];
}
int* create_segTree(vector<int> &a)
{
    int n=a.size();
    int height=(int)(ceil(log2(n)));
    int maxz = 2*(int)pow(2,height)-1;
    int *st = new int[maxz];
    constructSTUtill(a,0,n-1,st,0);
    return st;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int * st = create_segTree(a);
    return 0;
}