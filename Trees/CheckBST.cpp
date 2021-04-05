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
// To check the given tree is Binary Search Tree or not
// Bst==> all the left sub tree < =root and all the rightsubtree >=root principality
// while simple checking each node, if it's left node < node and right node> node doesnot
// ensure that the tree is BST 
//                        10
 //                 8            13
//              4      11     12       15 
// In this Tree the right child of 8 violates BST which is greater than the root and lying in left subtree so checking each nodes does not necessarily gives BST checkup
// therefore if the max value in LST is < root node and min value in RST is greater than  root will ensure BST 
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
    if(root==nullptr)
        return newNode(key);
    if(root->data<key)
    {
        root->right= insertion(root->right,key);
    }
    else root->left= insertion(root->left, key);
    return root;
}
// printing Tree
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// prev node is passed as reference as it is modified at every point
bool isValidBST(Node *root,Node*& prev)
{
    if(root!=nullptr)
    {
        if(!isValidBST(root->left,prev))
            return false;
        
        if(prev!=nullptr && root->data <=prev->data)
            return false;
        prev= root;

        if(!isValidBST(root->right,prev))
            return false;
    }
    return true;
}
bool isBST(Node* root)
{
    Node* prev=nullptr;    // to track the previous node value
    return isValidBST(root,prev);

}
int32_t main()
{
    Node *root= nullptr;

    int vals[]={6,3,8,1,4,7,9};

    // insertion
    for(auto v:vals)
    {
        root= insertion(root,v);
    }
    // swap nodes to make BST==BT
    swap(root->left,root->right);
   // inorder(root);
    if(isBST(root))
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";

    validationUsingBottomUP();
}

