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
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
    Node (int val)
    {
        this->val= val;
        left=right=NULL;
    }
};

void PreOrder(Node *root)
{
    if(root==NULL) return;

    stack<Node*>st1;
    st1.push(root);   // pushed the first root

    while(!st1.empty())
    {
        auto temp= st1.top();   // here temp is the root node on the stack top
        cout<<temp->val<<" ";
        st1.pop();

        // push the right child first so that we can operate on the left one at the top
        if(temp->right)
        {
            st1.push(temp->right);   // pushing the right child of the root node stored in temp
        }
        if(temp->left)
        {
            st1.push(temp->left);
        }
    }
}

void Inorder(Node *root)
{
    stack<Node*>st;
    Node *curr= root; // pointer traversing in the tree

    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            // push the curr pointer acting as parent for subtree
            st.push(curr);
            // go for the left subtree
            curr=curr->left;

        }
        // if the curr is NULL or reaches to the end  
        curr= st.top();  // get the value and move to the right sub tree
        st.pop();

        cout<<curr->val<<" ";

        //reassign to the right subtree
        curr= curr->right;
    }


}

void PostOrder(Node *root)
{
   

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 struct Node *root= new Node(1);
 root->left= new Node(2);
 root->right= new Node(3);
 root->left->left=new Node(4);
 root->left->right= new Node(5);
 root->right->left= new Node(6);
 root->right->right= new Node(7);

 cout<<"Preorder Traversal using Stack method and no use of pair concept \n";
 PreOrder(root);
 cout<<endl;

 cout<<"Inorder Traversal using Stack method and no use of pair concept \n";
 Inorder(root);
 cout<<endl;

 cout<<"Postorder Traversal using Stack method and no use of pair concept \n";
 //PostOrder(root);
 cout<<endl;
 return 0;

}
