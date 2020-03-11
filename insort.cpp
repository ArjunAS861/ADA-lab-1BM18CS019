//program to sort array using insertion Sort
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main()
{
	int n,i,j,item;
	int *a;
	clock_t time;
	cout<<"Enter the Size : ";
	cin>>n;
	a=new int[n];
	cout<<"Enter the Elements"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	time = clock();
	for(i=1;i<n;i++)
	{
		item = a[i];
		j=i-1;
		while(j>=0 && a[j]>item)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
	time = clock() - time;
	cout<<"The Time required for Insertion sort is "<<time<<" Clock Cycles."<<endl;
	cout<<"The sorted array is"<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;  	
	return 0;
}
/*OUTPUT:
Enter the Size : 5
Enter the Elements
7 9 2 5 6
The Time required for Insertion sort is 2 Clock Cycles.
The sorted array is
2 5 6 7 9 
*/
