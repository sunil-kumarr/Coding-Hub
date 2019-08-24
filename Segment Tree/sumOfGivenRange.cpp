#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void updateUtil(int* st,int diff,int index,int start,int end,int cur)
{
    if(index<start || index>end) return;
    st[cur]=st[cur]+diff;
    if(start!=end)
    {
        int mid=start+(end-start)/2;
        updateUtil(st,diff,index,start,mid,2*cur+1);
        updateUtil(st,diff,index,mid+1,end,2*cur+2);
    }
}
void update(int* st,int index,int val,vector<int> &arr,int n)
{
  if(index < 0 || index > n-1)
  {
      return;
  }
  arr[index] = val;
  int diff = val - arr[index];
  return updateUtil(st,diff,index,0,n-1,0);
}
int findSumUtil(int *st,int start,int end,int qstart,int qEnd,int cur)
{
    // cout<<qstart<<" "<<start<<" "<<qEnd<<" "<<end<<" "<<cur<<endl;
   if(qstart <= start && qEnd >=end){
       return st[cur];
   }
   if(end<qstart || start> qEnd)
   {
       return 0;
   }
   int mid = start + (end-start)/2;
   return findSumUtil(st,start,mid,qstart,qEnd,2*cur+1)+
          findSumUtil(st,mid+1,end,qstart,qEnd,2*cur+2);
}
int findSum(int start,int end,int* st,int n)
{
   if(start>end || start<0 || end>n-1)return -1;
   return findSumUtil(st,0,n-1,start,end,0);
}

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
    int q;
    cin>>q;
    while(q--){
     cin>>x>>y;
     cout<<findSum(x,y,st,n);
    }
    int up;
    cin>>up;
    while(up--)
    {
        cin>>x>>y;
        update(st,x,y,a,n);
    }
    for(auto x:a)cout<<x<<" ";
    return 0;
}