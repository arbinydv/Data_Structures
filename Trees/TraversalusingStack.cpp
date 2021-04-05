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
//Tree Traversal preorder, inorder, postorder using stack and we use pair wala concept
// TC= O(2N) evry node is touched at max 2wice and SC= O(N)
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        this->val= val;
        left=right=NULL;
    }
};

vi printPreorder(Node *root)
{
    vi temp;
    if(root==NULL) return temp;

    stack<pair<Node*,int>> st1;
    st1.push({root,0});
    while(!st1.empty())
    {
        pair<Node*,int> p= st1.top();
        st1.pop();
        if(p.second==0)
        {
           //push right first and then left so that left is on the top
            if(p.first->right!=NULL)
            {
                st1.push({p.first->right,0});
            }
            if(p.first->left!=NULL)
            {
                st1.push({p.first->left,0});
            }
            st1.push({p.first,1});
        }
        else
        {
           temp.pb(p.first->val);
        }  
        
    }
    return temp;

}

int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 struct Node *root= new Node(1);
 root->left= new Node(2);
 root->right= new Node(3);
 root->left->right= new Node(4);
 root->right->left= new Node(5);
 root->right->right=new Node(6);

 cout<<"PreOrder Traversal\n";
 vi ans= printPreorder(root);
 for(auto i:ans)
   cout<<i<<" ";
}
