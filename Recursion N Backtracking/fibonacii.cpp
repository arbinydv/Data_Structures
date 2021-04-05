//This program will print the fibonaicc of the given term
// This code considers fibonaic starts from 0
#include<bits/stdc++.h>
using namespace std;
int fibonaic(int n)
{
  // base case where fibonaic of 0 is o
  if(n==0|| n==1)
  {
    return n;
  }
  // recursion part
  int fib= fibonaic(n-1) + fibonaic(n-2);
return fib;
}
int main()
{
  int n;
  cin>>n;
  int term=fibonaic(n);
  cout<<n<<"-th term of the fibonaic is: "<<term;
}
