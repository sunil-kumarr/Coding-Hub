#include<iostream>
#include<vector>
#include<queue>
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
void printBFS(TreeNode* root)
{
  if(!root)return;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty())
  {
     TreeNode* temp = q.front();
     q.pop();
     cout<<temp->data<<" ";
     if(temp->left)q.push(temp->left);
     if(temp->right)q.push(temp->right);
  }
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
  printBFS(root);
  return 0;
}