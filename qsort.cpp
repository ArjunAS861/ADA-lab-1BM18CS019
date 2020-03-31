//Quick sort (input using random number generation)
#include<algorithm>
#include<iostream>
#include<ctime>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int part(int l, int h, int a[]);
void qsort(int l, int h, int a[]);
int main()
{
	srand(time(0));	
	int a[1000],n,i,h,l=0;
	clock_t time;
	cout<<"Enter the Size : ";
	cin>>n;
	cout<<"Elements :";
	for(i=0;i<n;i++)
	{
		a[i] = rand()%1000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	h=n-1;
	time = clock();
	qsort(l,h,a);
	time = clock()-time;
	cout<<"The sorted array is "<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"The time required for quick sort is "<<fixed<<setprecision(7)<<(float)time/CLOCKS_PER_SEC<<endl;
	
	return 0;
}
int part(int l, int h, int a[])
{
	int i,j,pivot;
	i = l;
	j = h+1;
	pivot = a[l];
	while(i<j)
	{
		do
		{	
			i+=1;
		}
		while(a[i]<=pivot);
		do
		{
			j-=1;
		}	
		while(a[j]>pivot);
		if(i<j)
			swap(a[i],a[j]);
	}
	swap(a[l],a[j]);
	return j;
}

void qsort(int l, int h, int a[])
{
	int j;
	if(l<h)
	{
		j = part(l,h,a);
		qsort(l,j-1,a);
		qsort(j+1,h,a);
	}
}
/*OUTPUT:
Enter the Size : 10                                                                                                                            
Elements :68 303 387 385 686 592 978 372 199 714                                                                                               
The sorted array is                                                                                                                            
68 199 303 372 385 387 592 686 714 978                                                                                                         
The time required for quick sort is 0.0000040      
*/
