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
// Generate all the structurally different binary trees from n nodes
struct Node
{
    int val;
    Node *left,*right;
    Node()
    {
         val=0;
        left=right=NULL;
    }
};

void printTree(Node *root)
{
    if(root==NULL)
    {
        cout<<"null ";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp= q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<"null ";
            continue;
        }
        else
        {
            cout<<temp->val<<" ";
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}

int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 unordered_map<int,vector<Node*>> ump;

 vector<Node*>zero;
 zero.pb(NULL);  
 ump[0]=zero;

Node *temp= new Node();
 vector<Node*>one;
 one.pb(temp);
 ump[1]=one;

//copulating the map
for(int i=2;i<=n;i++)
{
    vector<Node*> tree;
    for(int cnt1=0;cnt1<i;cnt1++)  
    {
        vector<Node*> left= ump[cnt1];  // for left subtree
        vector<Node*> right= ump[i-cnt1-1];

        //creating tree
        for(int x =0; x<left.size();x++)
        {
            for(int y=0;y<right.size();y++)
            {
                Node *temp1= new Node();
                temp1->left=left[x];
                temp1->right= right[y];
                tree.pb(temp1);    
            }
        }

    }
    ump[i]=tree;
}
for(int i=0;i<ump[n].size();i++)
{
    printTree(ump[n][i]);
    cout<<"\n";
}

}
