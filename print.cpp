#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void print(ll n)
{
  if(n==0)
    return;
  print(n-1);
  cout<<n<<endl;
}
int main()
{
   ll n;
   cin>>n;
   print(n);

}
