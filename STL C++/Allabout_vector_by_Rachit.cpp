#include<bits/stdc++.h> // this header file is the king of all the header files
#include<vector> // for vector library
#include<algorithm>  // for sorting and other operations which are builtin
using namespace std;
bool f(int x,int y)
{
  return x>y;
}
int main()
{
  vector<int> v={1,23,323,423,12};  // assigning the vector with elements
  for(auto x:v)                     // iteration in array. Atom will understand the concept used by vector for the iteration.
  {
    cout<<x<<" ";
  }
  cout<<endl;
  // sorting in vector takes O(NLogN) complexity
  sort(v.begin(),v.end());
  // 1 23 12 232 423

  // inserting values in vector.
  v.push_back(345);
  v.push_back(456);
  v.push_back(-123);
  sort(v.begin(),v.end());
  for(auto x:v)
  {
    cout<<x<<" ";
  }
  cout<<endl;
  // searching in vector
// we can manually search the elements in N complexity or use binary_search for logN complexity
// use of binary_search for searching
 bool find = binary_search(v.begin(),v.end(),5); // this is bool type which will tell us whether the element is present or not
 cout<<find<<endl;
 // lower_bound and upper_bound in  std::vector<int> v;
 // lower_bound is used to return the exact value present in the vector or just an element greater than the given values.
 // It can be used as binary_search to search any given element is present or not and the complexity is logn.
 auto a= lower_bound(v.begin(),v.end(),12)-v.begin();  // the diagnosis is that we have
 cout<<a<<endl;
 //upper_bound is used to return the value strictly greater than the assigned element
 auto b= upper_bound(v.begin(),v.end(),345);
 cout<<*b<<endl;

 //reversing std::vector<int> v;
// using in built function
reverse(v.rbegin(),v.rend());

//using comparative function
sort(v.begin(),v.end(),f);
for(auto y:v)
{
  cout<<y<<" ";
}
}
