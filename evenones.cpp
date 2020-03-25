#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countones(int n);
int sumofdigits(int n);
int main()
{
	int *a;
	int i,n,sum=0;
	cout<<"Enter the Size:";
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements"<<endl;	
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(countones(a[i])==1)
			sum = sum+sumofdigits(a[i]);
	}
	cout<<"The sum of digits of elements having even number of 1s = "<<sum<<endl;
	return 0;
}
int countones(int n)
{
	int count=0;
	while(n!=0)
	{
		n = n&(n-1);
		count++;
	}
	if(count%2==0)
		return 1;
	else
		return 0;
}
int sumofdigits(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum += n%10;
		n/=10;
	}
	return sum;
}

