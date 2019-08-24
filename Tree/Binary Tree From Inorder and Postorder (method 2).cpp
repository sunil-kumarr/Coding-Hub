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

TreeNode* help(vector<int> &a, vector<int> &b, int l, int r, unordered_map<int,int> &mp){
    if(l>r)return NULL;
    int k=b[b.size()-1];
    TreeNode *n= newNode(k);
    b.pop_back();
    n->right=help(a,b,mp[k]+1,r,mp);
    n->left=help(a,b,l,mp[k]-1,mp);
    return n;
}

TreeNode* buildTree(vector<int> &a, vector<int> &b) {
    int n=a.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[a[i]]=i;
    return help(a,b,0,n-1,mp);
}
void printPreorder(TreeNode* root)
{
  if(!root)return;
  cout<<root->data<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
}
int main()
{
  int n,x;
  vector<int> in,post;
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>x;
      in.push_back(x);
  }
  for(int i=0;i<n;i++){
      cin>>x;
      post.push_back(x);
  }
  TreeNode* root = buildTree(in,post);
  printPreorder(root);
  return 0;
}
