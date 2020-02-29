
//Farmer Problem Algorithm Used is:Conver Hull Algorithm
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

typedef long long int ll;

const ll MAX = 100;

ll n,sz;
vector<pair<ll,ll>>points;

int comp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.ff!=b.ff)
        return a.ff<b.ff;
        
    return a.ss<b.ss;    
}

ll check_slope(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
     return (b.ff-a.ff)*(c.ss-a.ss)-(b.ss-a.ss)*(c.ff-a.ff);
}

void convex_hull()
{
    ll len=0;
    
    vector<pair<ll,ll>>hull(sz+sz);
    
    for(int i=0;i<sz;++i) 
    {
        while (len>1 and check_slope(hull[sz-2], hull[sz-1],points[i])<=0) --len;
            hull[len++]=points[i];
    }
    
    for(int i=sz-2,j=len+1;i>=0;--i) 
    {
        while (len>=j and check_slope(hull[len-2], hull[len-1],points[i])<=0) --len;
            hull[len++] = points[i];
    } hull.resize(len-1);
    
    cout<<"\n\n";
    cout<<"Trees containg fencing is/are \n";
    
    for(auto &mem : hull)
    {
        cout<<mem.ff<<" "<<mem.ss<<endl;
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter the number of trees in farmer's field: \n";
    
    cin>>sz;
    
    cout<<"Enter the trees locations: \n";
    for(int i=0;i<sz;i++)
    {
        ll x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    
    sort(points.begin(),points.end(),comp);
    
    convex_hull();
    
    
}
