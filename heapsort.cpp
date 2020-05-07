#include<algorithm>
#include<iostream>
#include<ctime>
#include<time.h>
#include<bits/stdc++.h>
void heapify(int a[], int n);
void heapsort(int a[], int n);
using namespace std;
int main()
{
	srand(time(0));	
	int n,i;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	{
		a[i] = rand()%1000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	time = clock();
	heapsort(a,n);
	time = clock() - time;
	cout<<"\nThe time required for heap sort is "<<fixed<<setprecision(7)<<(float)time/CLOCKS_PER_SEC<<"\n";	
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;  	
	return 0;
}
void heapify(int a[], int n)
{
	int i,p,c,item;;
	for(i=((n-1)/2);i>=0;i--)
	{
		p = i;
		item = a[p];
		c = 2*p+1;
		while(c<n)
		{
			if((c+1)<n)
			{
				if(a[c]<a[c+1])
					c = c+1;
			}
			if(item<a[c])
			{
				a[p] = a[c];
				p = c;
				c = 2*p+1;
			}
			else
				break;
		}
		a[p] = item;
	}
}
void heapsort(int a[], int n)
{
	int i;
	heapify(a,n);
	for(i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i);
	}
}

/*Output:
Enter the number of elements
10
Enter the elements
642 226 835 869 112 711 569 784 343 448 
The time required for heap sort is 0.0000030
The sorted array is
112 226 343 448 569 642 711 784 835 869 
*/
