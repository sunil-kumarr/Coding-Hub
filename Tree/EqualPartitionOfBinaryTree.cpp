
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
 typedef long long ll;

 ll getSumTree(TreeNode* root)
 {
     if(root==NULL)return 0;
     return (root->val+getSumTree(root->left)+getSumTree(root->right));
 }
 ll isPartition(TreeNode* root,ll size,int &result)
 {
     if(!root)return 0;
     ll left = isPartition(root->left,size,result) ;
     ll right = isPartition(root->right,size,result);
     if(root->left && 2*left == size)result=1;
     if(root->right && 2*right == size)result =1;
     return root->val+left+right;
 }
int solve(TreeNode* a) {
    ll total = getSumTree(a);
    int result = 0;
    isPartition(a,total,result);
    return result;
}

int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   TreeNode* root = buildBinaryTree(arr,n,0);
   printInorder(root);
   cout<<solve(root);
}
