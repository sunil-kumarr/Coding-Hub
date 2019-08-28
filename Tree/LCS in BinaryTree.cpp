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


TreeNode* buildTree(TreeNode* root,int node)
{
  if(!root){
    // cout<<"empty: "<<node<<" ";
    return newNode(node);
    }
  if(root && root->data>node){
    // cout<<"left: "<<node<<" ";
    root->left=buildTree(root->left,node);
  }
  if(root && root->data<=node){
    // cout<<"right: "<<node<<" ";
     root->right=buildTree(root->right,node);
   }
  return root;
}
void printInorder(TreeNode* root)
{
  if(!root)return;
  printInorder(root->left);
   cout<<root->data<<" ";
  printInorder(root->right);
}
 int lcpath(TreeNode* root,int len)
 {
     if(!root)return 0;
     int l,r;
     if(root->left && root->left->data-root->data==1)
      l=lcpath(root->left,len+1);
     else
      l=lcpath(root->left,1);
     if(root->right && root->right->data-root->data==1)
      r=lcpath(root->right,len+1);
     else
      r=lcpath(root->right,1);
      return max(len,max(l,r));
 }
int main()
{
  int n,x;
  cin>>n;
  TreeNode* root=NULL;
  for(int i=0;i<n;i++){
      cin>>x;
      root=buildTree(root,x);
  }
  cout<<endl;
  printInorder(root);
  cout<<lcpath(root,1);
  return 0;
}