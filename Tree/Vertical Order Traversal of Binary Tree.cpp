#include<iostream>
#include<vector>
#include<map>
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
void vTraversal(TreeNode* root,map<int,vector<int> > &mp,int key)
{
    if(!root)return ;
    mp[key].push_back(root->data);
    vTraversal(root->left,mp,key-1);
    vTraversal(root->right,mp,key+1);

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
  cout<<endl;
  map<int,vector<int> > mp;
  vTraversal(root,mp,0);
  for(auto a:mp)
  {
      for(int i=0;i<a.second.size();i++)
      {
          cout<<a.second[i]<<" ";
      }
      cout<<endl;
  }
  return 0;
}