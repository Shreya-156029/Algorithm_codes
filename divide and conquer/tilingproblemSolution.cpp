#include<iostream>
using namespace std;

int count=0;
int t=0;
int calculate(int n)
{
	if(n==2)
        return 1;
        else
      {
            count=4*calculate(n/2)+1;
       }
return count;
}



int main()
{
	int n;
	cout<<"Enter Dimention:";
	cin>>n;
	cout<<calculate(n);
	return 0;
}
