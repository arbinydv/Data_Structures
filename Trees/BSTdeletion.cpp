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
// Deletion in Binary Search Tree
// Find the key
// Validate the cases:
// Delink the key

// Case 1: with no children( node is the leaf node) : In this case simply remove the node

// Case 2: with one child( left, right): In this case remove the node and replace it with its child.
// Case 3: with 2 children: In this case, call inorder successor or predecessor and get the value and go on recursive deletion until case 1 or 2 comes.
struct Node
{
    int data;
    Node *left,*right;
};

// Node creation 

Node* newNode(int key)
{
    Node* node= new Node;
    node->data= key;
    node->left=node->right=nullptr;
    return node;
}

// BST construction's insertion
Node* insert(Node* root, int key)
{
    if(root==nullptr)
        return newNode(key);
    if(key<root->data)
    {
        root->left= insert(root->left,key);
    }
    else 
    {
        root->right= insert(root->right,key);
    }
    return root;
}

// find successor of the curr node in the subtree
Node* minkey(Node* curr)
{
    while(curr->left)
        curr=curr->left;
    return curr;
}

// Print the BST tree Inorder

void inorder(Node* root)
{
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// delete node from the BST

// root passed as reference 
void deletenode(Node*& root,int key)   
{
    // 2 task: searching and de allocating the memory

   // searching for the node
    if(root==nullptr)
        return;
    if(key<root->data)
    {
        deletenode(root->left,key);
    }
    else if(key>root->data)
    {
         deletenode(root->right,key);
    }
    else 
    { 
        // key is found so perform deletion operation

        // case 1:
        if(root->left==nullptr && root->right==nullptr)
        {
            delete root;    // deallocate the memory of root and update to null
            root=nullptr;
        }

        // case 2: one child
        else if(root->left==nullptr || root->right==nullptr)
        {
            // get child node
            Node* child= (root->left)? root->left:root->right;
            Node* curr=root;
            
            root= child;
            
            //deallocate curr
            delete curr;

        }
        // case 3: 2 child
        else
        {
            Node* sucess= minkey(root->right);  // inorder succcessor of node

            root->data= sucess->data;

            // recursively delete the sucessor till case 1 or case 2 reaches
            deletenode(root->right,sucess->data);

        }
        
    }
    
}
int32_t main()
{
    Node* root= nullptr;
    int vals[]={15,10,20,8,12,18,25};

    for(int v:vals)
    {
        root= insert(root,v);
    }

    deletenode(root,20);
    inorder(root);

}

