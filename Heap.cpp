#include<bits/stdc++.h>
using namespace std;
int getParent(int index) {return index/2;}
int getLeftChild(int index){ return 2*index;}
int getRightChild(int index) {return 2*index+1;}
void shiftUp(vector<int> &arr)
{
      int index = arr.size()-1;
      int p = index/2;
      while( p>=0 && arr[p] > arr[index])
     {
       swap(arr[p],arr[index]);
       index = p;
       p = index/2;
     }
}
void shiftDown(vector<int> &a,int cur)
{
    int r = 2*cur+2;
    int l = 2*cur+1;
    int small = cur;
    if(l<a.size() && a[l]<a[cur]){small = l;}
    if(r<a.size() && a[r]<a[small]){small = r;}
    if(small != cur)
    {
      swap(a[small],a[cur]);
      shiftDown(a,small);
    }
}
int getMin(vector<int> &arr){if(arr.size()>0)return arr[0];return -1;}
int extractMin(vector<int> &arr)
{
  int x=-1;
  if(arr.size()==1)
  {x= arr[0];arr.pop_back();}
  else if(arr.size()>1)
  {
    int last=arr.size()-1;
    x=arr[0];
    arr[0]=arr[last];
    arr.pop_back();
    shiftDown(arr,0);
  }
  return x;
}
int main()
{
     int n;
      cin>>n;
      vector<int> a;
      for(int i=0;i<n;i++)
      {
          int x;cin>>x;
          a.push_back(x);
          shiftUp(a);
      }
      for(int i=0;i<a.size();i++){
          cout<<a[i]<<" ";
      }
      cout<<endl;
     cout<< extractMin(a) << endl;
     cout<< extractMin(a) << endl;
     cout<< extractMin(a) << endl;
     cout<< extractMin(a) << endl;
     cout<< extractMin(a) << endl;
     cout<< extractMin(a) << endl;
    return 0;
}

// 6 4 2 5 9 1 0