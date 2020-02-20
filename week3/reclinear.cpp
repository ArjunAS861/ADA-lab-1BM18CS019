#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
int lsearch(int a[],int i,int n,int key);
using namespace std;
int main()
{
	int a[20],n,i,pos,key;
	clock_t time;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the key element"<<endl;
	cin>>key;
	time = clock();
	pos = lsearch(a,0,n,key);
	time = clock() - time;
	cout<<"\nThe time taken = "<<fixed<<setprecision(10)<<(float)time/CLOCKS_PER_SEC<<"\n";
	if(pos!=-1)
		cout<<"\nThe key element is present at position "<<pos<<endl;
	else
		cout<<"\nThe key element is not present in the array"<<endl;
	return 0;
}
int lsearch(int a[],int i,int n,int key)
{
	int pos;
	if(i<n)
	{
		if(a[i]==key)
		{
			pos = i;
			return pos;
		}
		else
			return lsearch(a,i+1,n,key);
	}
	return -1;
}
