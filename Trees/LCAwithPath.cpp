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
// Locest Common Ancestor of two nodes storing their path
// the LCA can be found by storing the paths of n1 from root to n1 and same for n2
// we will ignore the paths that matches in both array and the point where they arenot is the split point and it shoudl be the LCA
// TC= o(H) for bst and O(2H) for the path

struct Node
{
    int data;
    Node *left,*right;
};
vector<int>path1,path2;
Node* newNode(int key)
{
    Node * node= new Node;
    node->data= key;
    node->left= node->right= nullptr;
    return node;
}

Node* insertion(Node* root, int key)
{
    if(root==nullptr)
        return newNode(key);
    if(root->data <  key)
    {
        root->right= insertion(root->right,key);
    }
    else 
    {
        root->left= insertion(root->left, key);
    }
    return root;
}
// finding the path and storing for the n1 node
void lca1(Node* root, int n1)
{
    if(root->data==n1)
    {
        path1.push_back(root->data);
        return;
    }
    if(root->data<n1)
    {
        // right subtree 
        path1.push_back(root->data);
        lca1(root->right,n1);
    }
    else 
    {
        path1.push_back(root->data);
        lca1(root->left,n1);
    }

}

// finding the path and storing for the n2 node
void lca2(Node* root, int n2)
{
    if(root->data==n2)
    {
        path2.push_back(root->data);
        return;
    }
    if(root->data<n2)
    {
        // right subtree 
        path2.push_back(root->data);
        lca1(root->right,n2);
    }
    else 
    {
        path2.push_back(root->data);
        lca1(root->left,n2);
    }    

}
int32_t main()
{
    Node *root=nullptr;
    int val[]={6,2,8,1,4,7,9};

    //create a bst
    for(int v:val)
    {
        root= insertion(root,v);
    }
    lca1(root,2);
    lca2(root,8);
    int n=min(path1.size(),path2.size());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(path1[i]!=path2[i])
        {
            
            break;
        }
        ans=path1[i];
    }
    cout<<ans;

}

