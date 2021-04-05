//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define vpp vector<pair<int,int> >
#define se set<int>
#define pb push_back
#define mp map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
//Tree Traversal preorder, inorder, postorder using recursion
// TC= O(N) and Sc= O(height of tree)
struct Node
{
    int val;
    Node *left,*right;

    Node(int val)
    {
        this->val= val;
        left=right=NULL;
    }
};

void printPreorder(Node *root)
{
    if(root==NULL)
     return;
    
    cout<<root->val<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root)
{
    if(root==NULL)
     return;
    
    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}

void printPostorder(Node *root)
{
    if(root==NULL)
     return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->val<<" ";
}

int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 struct Node *root= new Node(1);
 root->left= new Node(2);
 root->right= new Node(3);
 root->left->left= new Node(4);
 root->left->right= new Node(5);
 root->right->left= new Node(6);
 root->right->right=new Node(7);

 cout<<"PreOrder Traversal\n";
 printPreorder(root);
 cout<<endl;
 cout<<"Inorder Traversal\n";
 printInorder(root);
 cout<<endl;
 cout<<"PostOrder Traversal\n";
 printPostorder(root);
 return 0;
}
