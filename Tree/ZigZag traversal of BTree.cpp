
// vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
//     vector<vector<int> > tree;
//     if(!A)return tree;
//     stack<TreeNode*> next,curr;
//     curr.push(A);
//     bool left2right=true;
//     vector<int> vec;
//     while(!curr.empty())
//     {
//         TreeNode* temp = curr.top();
//         curr.pop();
//         if(temp){
//          vec.push_back(temp->val);
//         if(left2right)
//         {
//             if(A->left)next.push(A->left);
//             if(A->right)next.push(A->right);
//         }
//         else{
//             if(A->right)next.push(A->right);
//             if(A->left)next.push(A->left);
//         }
//         }
//         if(curr.empty())
//         {
//             left2right=!left2right;
//             swap(curr,next);
//             tree.push_back(vec);
//             vec.clear();
//         }
//     }
//     return tree;
// }

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
typedef pair<TreeNode*,int> qpair;
#define mkp make_pair
#define node first
#define level second

void bfs(TreeNode *root, vector<vector<int> > &v){
    queue<qpair> q;
    q.push({root,0});
    int level = 0;
    vector<int> vec;
    while(!q.empty()){
        qpair current = q.front();
        root = current.node;
        q.pop();
        if(root->left)  q.push({root->left , current.level+1});
        if(root->right) q.push({root->right, current.level+1});
        if(current.level == level)
          vec.push_back(root->data);
        else {
            // reverse for odd level 1,3,5 (right to left);
            if(level&1){
                reverse(vec.begin(),vec.end());
                v.push_back(vec);
            }
            else v.push_back(vec);
            vec.clear();

            vec.push_back(root->data);
            level++;
        }
    }
    if(vec.size()){
        if(level&1){
            reverse(vec.begin(),vec.end());
            v.push_back(vec);
        }
        else v.push_back(vec);
    }
}
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > v;
    bfs(root,v);
    return v;
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
  vector<vector<int> > vec = zigzagLevelOrder(root);
  for(auto x:vec)
  {
      for(int i=0;i<x.size();i++)
      {
          cout<<x[i]<<" ";
      }
      cout<<endl;
  }
  return 0;
}