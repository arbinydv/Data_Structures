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
//Reversing the linked list in recursive fashion
struct Node
{
  int data;
  Node* next;
};
Node* head= NULL;
void push(int x)
{
  Node* new_node= new Node;
  new_node->data=x;
  new_node->next= head;
  head=new_node;
}
void reverse()
{
  if(head==NULL || head->next==NULL)
  {
    return head;
  }
}
void display()
{
  Node *temp=head;
  while(temp)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int x;cin>>x;
   push(x);
 }
 display();
 cout<<endl;
 reverse();
 display();
}
