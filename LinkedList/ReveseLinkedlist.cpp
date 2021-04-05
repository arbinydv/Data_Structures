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
//Reversing the linked list iterative
struct Node
{
  int data;
  Node * next;
};
//create head
Node* head= NULL;
void push(int x)
{
  //Node* new_node= new Node;
  Node* new_node= (Node*)malloc(sizeof(Node));
  new_node->data= x;
  new_node->next= head;   //pointer initially at head
  head= new_node;
}
void reverse()
{
  Node* current= head;
  Node* prev=NULL;
  while(current!=NULL)
  {
    Node* temp= current->next;   // first store the next node pointer
    current->next= prev;
    prev= current;
    current= temp;
  }
  head= prev;
}

void display()
{
  Node* temp= head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp= temp->next;
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 while(n--)
 {
   int a;cin>>a;
   push(a);
 }
 display();
 cout<<endl;
 reverse();
 display();
}
