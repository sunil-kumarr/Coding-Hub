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

int search(vector<int> &in,int el,int l,int r)
{
     int i;
     for(i=l;i<=r;i++)
     {
         if(in[i]==el)
          break;
     }
     return i;
 }
TreeNode* tree(vector<int> &intree,vector<int> &postree,int istart, int iend)
{
    if(istart > iend )
        return NULL;
    int k = postree[postree.size()-1];
    TreeNode* root = newNode(k);
    int index = search(intree,k,istart,iend);
    postree.pop_back();
    root->right = tree(intree,postree,index+1,iend);
    root->left = tree(intree,postree,istart,index-1);
    return root;
}
TreeNode* buildTree(vector<int> &in, vector<int> &post) {
    return tree(in,post,0,in.size()-1);
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
