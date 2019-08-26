#include<iostream>
#include<vector>
#include<unordered_map>
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

TreeNode* build(vector<int> &pre,unordered_map<int,int> &mp,int l,int r,int &pIndex)
 {
     if(l>r)return NULL;
     int node = pre[pIndex++];
     TreeNode* temp = newNode(node);
     if(l==r)return temp;
     int index = mp[node];
     temp->left = build(pre,mp,l,index-1,pIndex);
     temp->right = build(pre,mp,index+1,r,pIndex);
     return temp;
 }
TreeNode* buildTree(vector<int> &pre, vector<int> &in) {
    unordered_map<int,int> mp;
    int a =0;
    for(int i=0;i<in.size();i++)mp[in[i]]=i;
    return build(pre,mp,0,in.size()-1,a);
}
void printPostorder(TreeNode* root)
{
  if(!root)return;
  printPostorder(root->left);
  printPostorder(root->right);
  cout<<root->data<<" ";
}
int main()
{
  int n,x;
  vector<int> pre,in;
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>x;
      pre.push_back(x);
  }
  for(int i=0;i<n;i++){
      cin>>x;
      in.push_back(x);
  }
  TreeNode* root = buildTree(pre,in);
  printPostorder(root);
  return 0;
}
