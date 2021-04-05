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

// A node's inorder predecessor is node with the max value in its left subtree( left subtree ko rightmost child).
// If the right subtree doesnot exist then inorder sucessor of the node will be one of the ancestors of it.
// which ancestor: we move up the tree towards root until we find a node which is the right child of it's parent.
//                            15
//                      10           20
//               8          12    16     25
// The inorder predecessor of 8: NULL, 12: 10 ( ancestor whose right child is 12) , and 20: 16

struct Node
{
    int data;
    Node *left,*right;
};

// creating new binary tree node having given values
Node* newNode(int key)
{
   Node* node= new Node;
   node->data= key;
   node->left=node->right=nullptr;
   return node;
}

// FUnction to insert key in the BST

Node* insert(Node* root, int key)
{
    if(root==nullptr)
        return newNode(key);
    
    if(key<root->data)
    {
        root->left= insert(root->left, key);
    }
    else
    {
        root->right= insert(root->right,key);
    }
    return root;

}

// finding max in the leftsubtree rightmost child
Node* maxkey(Node* root)
{
    while(root->right)
        root= root->right;
    return root;
}

// function to find the inorder predecessor of the key in BST
// predecessor is update on every call so passed by reference

void predecessor(Node *root, Node*& pres,int key)
{
    // base case
    if(root==nullptr)
    {
        pres=nullptr;
        return;
    }

    // if node with key  value is found then use max function to get the sucessor of the node
    if(root->data==key)
    {
        // call 1 left and then go till the rightmost child
        if(root->left)
            pres= maxkey(root->left);
    }
    else if(key> root->data)   // in case the left subtree does not exist then  we store the ancestor
    {
        pres= root;   // udpate ancestor as curr note before LST recursion for ancestor 
        predecessor(root->right,pres,key);
    }
    else predecessor(root->left,pres,key);
}

int32_t main()
{
    int keys[]= {15,10,20,8,12,17,25,6,11,16,27};

    Node* root= nullptr;
    
    //BST construction
    for(int k:keys)
    {
        root= insert(root,k);
    }

    // finding in-order successor for each keys

    for(int k:keys)
    {
        Node* prec= nullptr;  // successor at first is intialized as null

        predecessor(root,prec,k);
        
        if(prec!=nullptr)
        {
            cout<<"The sucessor of node : "<<k<<" is "<<prec->data<<endl;
        }
        else cout<<"The sucessor of node does not exists \n";
    }

}

