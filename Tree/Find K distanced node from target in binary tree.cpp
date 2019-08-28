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
void printInorder(TreeNode* root)
{
  if(!root)return;
  printInorder(root->left);
   cout<<root->val<<" ";
  printInorder(root->right);
}
void dfs(TreeNode* root,int l, int c, vector<int> &v){
    if(l>c)return ;
    if(l==c)v.push_back(root->val);
    if(root->left) dfs(root->left,l+1,c,v);
    if(root->right) dfs(root->right,l+1,c,v);
}

int findNode(TreeNode* root, int b, int c, int curlvl, vector<int> &vec){
    // when target node is found.
    if(root->val==b){
        // recur its subtree for k distance nodes
        dfs(root,0,c,vec);
        // return the level of target node.
        return curlvl;
    }
    int foundLeft=-1,foundRight=-1;
    if(root->left){
        // recur left subtree from root
        foundLeft=findNode(root->left,b,c,curlvl+1,vec);
        if(foundLeft!=-1 and root->right) dfs(root->right,foundLeft-curlvl+1,c,vec);
        if(foundLeft-curlvl==c)vec.push_back(root->val);
    }
    if(root->right){
        // recur right subtree from root
        foundRight=findNode(root->right,b,c,curlvl+1,vec);
        // again recur for the left subtree from ancestors of target node
        // the level passed here to the other node of parent of target is
        // its distance from target node. then do DFS on the subtree
        if(foundRight!=-1 and root->left) dfs(root->left,foundRight-curlvl+1,c,vec);
        if(foundRight-curlvl==c)vec.push_back(root->val);
    }
    // for leaf Node
    if(foundLeft==-1 and foundRight==-1)return -1;
    // for node having right child
    if(foundLeft==-1)return foundRight;
    // for node having left child
    if(foundRight==-1)return foundLeft;
    return -1;
}

vector<int> solve(TreeNode* root, int b, int c) {
    vector<int> v;
    int t=findNode(root,b,c,0,v);
    return v;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   TreeNode* root = buildBinaryTree(arr,n,0);
   printInorder(root);
   int b,c;
   cin>>b>>c;
   vector<int> vec = solve(root,b,c);
   for(auto x:vec)cout<<x<<" ";
   return 0;
}