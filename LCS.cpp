#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll LCS(string s1,string s2,ll m,ll n)
{
   if(m==0 || n==0)
   return 0;
   if(s1[m-1]==s2[n-1])
   return 1+LCS(s1,s2,m-1,n-1);
   else
   return max(LCS(s1,s2,m,n-1),LCS(s1,s2,m-1,n));

}
int main()
{
   int m,n;
   cin>>m>>n;
   string s1,s2;
   cin>>s1>>s2;
   cout<<LCS(s1,s2,m,n)<<endl;
}
