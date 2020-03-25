#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
void merge(int t[], int , int , int , int , int a[]);
void mergesort(int t[], int , int , int a[]);
void mergesortdp(int n, int a[]);
using namespace std;
int main()
{
	int *a;
	int n,i;
	cout<<"Enter the number of elements:";
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesortdp(n,a);
	cout<<"The sorted array is"<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
void mergesortdp(int n, int a[])
{
	int dpa[1000],i;
	if(n==0)
		return;
	for(i=0;i<n;i++)
		dpa[i] = a[i];
	mergesort(dpa,0,n,a);
	for(i=0;i<n;i++)
		a[i] = dpa[i];
}
void mergesort(int a[],int low, int high, int t[])
{
	int mid1,mid2;
	if(high-low<2)
		return;
	else
	{
		mid1 = (int)(low+(high-low)/3);
		mid2 = (int)low+2*(high-low)/3+1;
		mergesort(t,low,mid1,a);
		mergesort(t,mid1,mid2,a);
		mergesort(t,mid2,high,a);
		merge(t,low,mid1,mid2,high,a);
	}
}
void merge(int t[],int low, int mid1, int mid2, int high, int a[])
{
	int i,j,l,k;
	i = low;
	j = mid1;
	l = mid2;
	k = low;
	while(i<mid1 && j<mid2 && l<high)
	{
		if(a[i]<a[j]) 
		{
			if(a[i]<a[l])
			{
				t[k] = a[i];
				i++;
				k++;
			}
			else
			{
				t[k] = a[l];
				l++;
				k++;
			}
		}
		else 
		{
			if(a[j]<a[l])
			{
				t[k] = a[j];
				j++;
				k++;
			}
			else
			{
				t[k] = a[l];
				l++;
				k++;
			}
		}
	}
	while(i<mid1 && j<mid2)
	{
		if(a[i]<a[j])
		{
			t[k] = a[i];
			i++;
			k++;
		}
		else
		{
			t[k] = a[j];
			j++;
			k++;
		}
	}
        while(j<mid2 && l<high)
	{
		if(a[j]<a[l])
		{
			t[k] = a[j];
			j++;
			k++;
		}
		else
		{
			t[k] = a[l];
			l++;
			k++;
		}
	}
	while(l<high && i<mid1)
	{
		if(a[l]<a[i])
		{
			t[k] = a[l];
			l++;
			k++;
		}
		else
		{
			t[k] = a[i];
			k++;
			i++;
		}
	}
	while(i<mid1)
	{
		t[k] = a[i];
		k++;
		i++;
	}
	while(j<mid2)
	{
		t[k] = a[j];
		k++;
		j++;
	}
	while(l<high)
	{
		t[k] = a[l];
		k++;
		l++;
	}
}