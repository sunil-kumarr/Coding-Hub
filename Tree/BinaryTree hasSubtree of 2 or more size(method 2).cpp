// C++ program to check if binary tree
// is subtree of another binary tree
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
/* A utility function to check
whether trees with roots as root1 and
root2 are identical or not */
bool areIdentical(node * maintree, node *subtree)
{
    /* base cases */
    if (maintree == NULL && subtree == NULL)
        return true;

    if (maintree == NULL || subtree == NULL)
        return false;

    /* Check if the data of both roots is
    same and data of left and right
    subtrees are also same */
    return ( maintree->data == subtree->data && // condition 1
            areIdentical(maintree->left, subtree->left) && // condition 2
            areIdentical(maintree->right, subtree->right) ); // condition 3
}

/* This function returns true if S
is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S)
{
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;

    /* If the tree with root as current
    node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
int main()
{
    // mainTree
    node *T = newNode(26);
    T->right         = newNode(3);
    T->right->right = newNode(3);
    T->left         = newNode(10);
    T->left->left     = newNode(4);
    T->left->left->right = newNode(30);
    T->left->right     = newNode(6);
    // subtree
    node *S = newNode(10);
    S->right     = newNode(6);
    S->left     = newNode(4);
    S->left->right = newNode(30);
    if (isSubtree(T, S))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";

    return 0;
}
