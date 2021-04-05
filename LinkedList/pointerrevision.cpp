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
void playingwithpointer(int x)
{
  int* ptr=&x;   // type of ptr is int*
 
  cout<<" The size of int taken by Vs studio complier is : "<< sizeof(int)<<endl;
  cout<<" The address of ptr is "<< ptr<<endl;
  cout<<" The value at ptr is "<< *ptr<<endl;

  cout<<" The modified incr address of ptr is : "<< ptr+1<<endl;
  cout<<" The dereferencing of pointer ptr is :"<< *ptr+2<<endl;

  // a pointer which stores the address of a pointer

  int **q;    // type of q is int**
  q= &ptr;  // store address of the pointer ptr

  cout<<"The address of q is :"<<q<<endl;
  cout<<"The dereferencing of pointer q : "<< *(*q)<<endl;  // should give value at ptr


}
void refcall(int *a)
{
  *a=*a+1;
}
int32_t main()
{
  // working on pointers
  // referencing= assigining address to a pointer to refeence somehwere
  // dereferencing= pointer will print value before which pointer is referenced to address first so we dereference it first

  int x=5;
 // playingwithpointer(x);
  
  // USAGE of POINTERS in passing in functions and all

  // pointer call by reference

  int a=10;
  refcall(&a);
  cout<<a<<" ";

  // POINTERS AND ARRAY
  

}

