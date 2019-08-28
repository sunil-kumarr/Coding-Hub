#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
};
TreeNode* newNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->left=temp->right=NULL;
    temp->val=data;
    return temp;
}
TreeNode* buildBinaryTree(int arr[],int n,int index)
{
    if(index>=n || arr[index]==-1)return NULL;
    TreeNode *temp = newNode(arr[index]);
    temp->left = buildBinaryTree(arr,n,2*index+1);
    temp->right = buildBinaryTree(arr,n,2*index+2);
    return temp;
}
void printInorder(TreeNode* root)
{
  if(!root)return;
  printInorder(root->left);
   cout<<root->val<<" ";
  printInorder(root->right);
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   TreeNode* root = buildBinaryTree(arr,n,0);
   printInorder(root);
}