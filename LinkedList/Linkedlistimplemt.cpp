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
//General implementation of linkelist from scratch for understanding.
struct Node
{
  int data;
  Node* next; //pointer which points to the next node
};
Node* head= NULL;
void insert(int new_data)  // creation of nodes and allocation of memory dynamically
{
  Node* new_node= (Node*)malloc(sizeof(Node)); //memory allocation
  new_node->data= new_data;  //store data in newly created node
  new_node->next= head;   // pointing to head
  head=new_node;  // head is the starting position of the node to form linkedlist
}

void display()   // to traverse and print the data in  the linkedlist
{
  Node* ptr;  //here head is not lost so ptr will store the head and then simply iterate over the linkedlist in this way we will not loose the head of linkedlist.
  ptr= head;   // pointer to iterate through the linkedlist
  while(ptr)
  {
    cout<<ptr->data<<" ";
    ptr= ptr->next;    //pointing to next node
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int x; cin>>x;
   insert(x);
 }
 display();

}
