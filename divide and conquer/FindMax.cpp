#include<iostream>
using namespace std;
int findmax(int a[],int low,int high)
{
	if(low==high)  //for 1 element
	{
		return a[low];
	}
	if((high==low+1) && a[low]>=a[high]) // for 2 elements
		return a[low];
	if(high==low+1 && a[low]<a[high])
		return a[high];
	
	int mid=(low+high)/2;
	// for n elements
	if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
	{
		return a[mid];
	}
	if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
	{
		return findmax(a,low,mid-1);
		
	}
	else
	{
		return findmax(a,mid,high);
	}
}




int main()
{
	int a[]={12,34,56,78,98,76,54,43,32,21};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<findmax(a,0,n-1);
	return 0;
}
