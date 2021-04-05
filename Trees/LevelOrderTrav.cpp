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
vector<vi> ans;
void levelorder(Node *root)
{
    if(root==NULL) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        int s= q.size();
        vi temp;
        while(s--)
        {
        Node *curr= q.front();
        q.pop(); //removing element at the front once visited
        temp.pb(curr->val);
        if(curr->left!=NULL) 
            q.push(curr->left);   // left children is pushed
        if(curr->right!=NULL)
            q.push(curr->right);   // right chilren is pushed
        }
        ans.pb(temp); 
    }

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
 levelorder(root);
 for(auto it:ans)
 {
     vi res= it;
     for(auto r:res)
     {
         cout<<r<<" ";
     }
     cout<<endl;
 }

}
