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
void printPreorder(TreeNode* root)
{
  if(!root)return;
  cout<<root->data<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
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
  cin>>n;
  TreeNode* root=NULL;
  for(int i=0;i<n;i++){
      cin>>x;
      root=buildTree(root,x);
  }
  cout<<endl;
  printInorder(root);
  return 0;
}