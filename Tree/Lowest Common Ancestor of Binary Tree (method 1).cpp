#include<iostream>
#include<vector>

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
bool path(TreeNode* tree,int data,vector<int> &p)
{
    if(!tree)return false;
     p.push_back(tree->val);
    if(tree->val==data)return true;
    if((tree->left && path(tree->left,data,p))||
    (tree->right && path(tree->right,data,p)))
    return true;
    p.pop_back();
    return false;
}
int lca(TreeNode* A, int B, int C) {
    vector<int> pathB,pathC;
    if(!path(A,B,pathB)||
    !path(A,C,pathC))return -1;
    int i;
    for(i=0;i<pathB.size()&&i<pathC.size() ;i++)
    {
        if(pathB[i]!=pathC[i])
         break;
    }
    return pathB[i-1];
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
   int x,y;
   cin>>x>>y;
   cout<<"LCA: "<<lca(root,x,y);
}