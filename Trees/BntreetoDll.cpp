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
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
class Node
{
public:
  int val;
  Node* left;
  Node* right;
};
Node* bintreetoll(Node* root)
{
  if(root==NULL) return root;

  if(root->left!=NULL)
  {
    Node* left= bintreetoll(root->left);
    for(;left->right!=NULL;left= left->right);
    left->right=root;
    root->left= left;
  }
  if(root->right!=NULL)
  {
    Node* right=bintreetoll(root->right);
    for(;right->left!=NULL;right=right->left);
    right->left= root;

    root->right= right;
  }
  return root;
}
Node* bin2Dll(Node *root)
{
  if(root==NULL) return root;

  root= bintreetoll(root);

  while(root->left!=NULL)
    root= root->left;

  return(root);
}
Node* newNode(int data)
{
  Node* new_node= new Node();
  new_node->val= data;
  new_node->left= new_node->right=NULL;
  return (new_node);
}
void printDll(Node *node)
{
  while(node!=NULL)
  {
    cout<<node->val<<" ";
    node= node->right;
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 Node *root= newNode(10);
 root->left= newNode(12);
 root->right= newNode(15);
 root->left->left= newNode(25);
 root->left->right= newNode(30);
 root->right->left= newNode(35);
 Node *head= bin2Dll(root);
 printDll(head);
}
