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
  int data;
  Node* next;
};
Node* head= NULL;
void insert(int new_data)
{
//  Node* new_node= (Node*)malloc(sizeof(Node));
 //we can replace above memory allocation by simply using new
  Node* new_node= new Node;
  new_node->data= new_data;
  new_node->next= head;
  head= new_node;
}
int findmiddle(Node*head)
{
  Node *slow,*fast;
  slow= head;
  fast= head;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow= slow->next;
    fast= fast->next->next;
  }
  return slow->data;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 while(n--)
 {
   int x;cin>>x;
   insert(x);
 }
 //finding the middle element
 cout<<findmiddle(head);

}
