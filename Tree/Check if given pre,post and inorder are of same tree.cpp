#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left,*right;
};
TreeNode* newNode(int data)
{
  TreeNode* temp = new TreeNode();
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
int searchIndex(vector<int> &in,int istart,int iend,int data)
{
    // cout<<istart<<" s: "<<iend<<endl;
    int i;
    for(i=istart;i<=iend;i++){
       if(in[i]==data)
       break;
    }
    return i;
}
TreeNode* buildTree(vector<int> &in, vector<int> &post,int istart,int iend)
{

    if(istart>iend)return NULL;
    int lastRoot = post[post.size()-1];
    int index = searchIndex(in,istart,iend,lastRoot);
    // cout<<index<<" "<<lastRoot<<endl;
    post.pop_back();
    if(index<istart || index>iend)return NULL;
    TreeNode* root = newNode(lastRoot);
    root->right = buildTree(in,post,index+1,iend);
    root->left = buildTree (in,post,istart,index-1);
    return root;
}
void preorder(TreeNode* tree,vector<int> &pre)
{
    if(tree==NULL)return;
    pre.push_back(tree->data);
    preorder(tree->left,pre);
    preorder(tree->right,pre);
}
int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int pIndex = B.size()-1;
    TreeNode* tree = buildTree(B,C,0,B.size()-1);
    vector<int> pre;
    preorder(tree,pre);
    // for(auto x:pre)cout<<x<<" ";
    if(pre==A)return 1;
    return 0;
}

int main()
{
  int n,x;
  vector<int> pre,in,post;
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>x;
      pre.push_back(x);
  }
  for(int i=0;i<n;i++){
      cin>>x;
      in.push_back(x);
  }
  for(int i=0;i<n;i++){
      cin>>x;
      post.push_back(x);
  }
  if(solve(pre,in,post))cout<<"SAME";
  else cout<<"NOT SAME";
  return 0;
}

/*
   ----- SAME -------
    A =  1 2 4 5 3
    B =  4 2 5 1 3
    C =  4 5 2 3 1
    -------NOT SAME -----
    A = 1 5 4 2 3
    B = 4 2 5 1 3
    C = 4 1 2 3 5
*/