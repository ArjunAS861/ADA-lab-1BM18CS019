#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
int bsearch(int a[],int l,int h,int key);
using namespace std;
int main()
{
	int a[20],n,i,pos,key;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the key element\n";
	cin>>key;
	time = clock();
	pos = bsearch(a,0,n-1,key);
	time = clock() - time;
	cout<<"\nThe time taken = "<<fixed<<setprecision(10)<<(float)time/CLOCKS_PER_SEC<<endl;
	if(pos!=-1)
		cout<<"\nThe key element is present at position "<<pos<<endl;
	else
		cout<<"\nThe key element is not present in the array"<<endl;
	return 0;
}
int bsearch(int a[], int l, int h, int key)
{
	int mid;
	if(l<=h)
	{
		mid = (l+h)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)
			return bsearch(a,mid+1,h,key);
		else 
			return bsearch(a,l,mid-1,key);
	}
	return -1;
}
