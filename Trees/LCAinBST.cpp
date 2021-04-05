//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define se set<int>
#define pb push_back
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
// Lowest Common Ancestor in a Binary Search Tree recursive approach
// The lCA of two nodes n1 and n2 in a BST is the node that has both n1 and n2 as descendants.
// Each  node can be descendant of itself so if n2 is reachable from n1 then n1 is the descendant of n2 and n1
// Shared ancestors far from root for n1 and n2.
// The Tc of BST will be o(height) as we dont need to store all the nodes path and SC will be o(height) recursion stack 
// SC. can be further reduced to o(1) using iterative approach applied below

// The trick here is to find a node where n1 lies in left Subtree and n2 in right subtree then the node is LCA,
// else if n1 and n2 lies in leftsubtree and n2 is rooted undeer n1 then n1 is LCA ,
// If n1 is rooted under n2 and in rightsubtree then LCA is n1

struct Node
{
    int data;
    Node *left,*right;
};

Node* newNode(int key)
{
    Node* node= new Node;
    node->data= key;
    node->left=node->right=nullptr;
    return node;
}

Node* insertion(Node* root, int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left= insertion(root->left,key);
    else root->right= insertion(root->right,key);
    return root;

}
// function to search for the nodes in the BST
bool search(Node *root, int key)
{
    while(root)
    {
        if(key<root->data)
            root=root->left;
        else if(key>root->data)
            root=root->right;
        else return true;
    }
    return false;
}

// Recursive function for finding the Lowest Common Ancestors of the node n1 and node n2
Node *LCArecur(Node* root, int n1, int n2)
{
    if(root==nullptr)
        return nullptr;
    
    // if n1 and n2 < root then they both lies in leftsubtree
    if(root->data > max(n1,n2))
    {
        return LCArecur(root->left,n1,n2);
    }
    // if n1 and n2 are larger than the root ele then it lies in rightsubtree
    else if (root->data < min(n1,n2))
    {
        return LCArecur(root->right,n1,n2);
    }
    // if one key >= root and another is <=root then the curr node is LCA
    return root;
}

// Iterative LCA finding

Node *LCAiter(Node *root, int n1,int n2)
{
    if(root==nullptr || !search(root,n1) || !search(root,n2))
        return nullptr;
    
    Node* curr= root;
    
    while(curr)
    {
        if(curr->data > max(n1,n2))
        {
            curr= curr->left;
        }
        
        else if(curr->data < min(n1,n2))
        {
            curr= curr->right;
        }
        else return curr;
    }
    
}
int32_t main()
{
    Node* root= nullptr;

    int val[]={15,10,20,8,12,16,25};

    // insertion in BST
    for(int v: val)
    {
        root= insertion(root,v);
    }

    Node* lca= LCArecur(root,10,25);

    if(lca!=nullptr)
        cout<<"The LCA is "<<lca->data<<endl;
    else cout<<" NO LCA exists\n";

    // Iterative LCA in o(1) SC

    Node* lca2= LCAiter(root,10,25);

    if(lca2!=nullptr)
        cout<<"The LCA is "<<lca2->data<<endl;
    else cout<<" NO LCA exists\n";

}

