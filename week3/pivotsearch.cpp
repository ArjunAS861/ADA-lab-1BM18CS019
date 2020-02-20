#include<algorithm>
#include<iostream>
using namespace std;
int pivot(int[],int,int);
int bins(int[],int,int,int );
int pivse(int arr[],int n,int key);

int main ()
{
  
	int ar[50], key, n;
	cout<<"Enter the Size: "<<endl;
	cin>>n;
	cout<<"Enter Elements : "<<endl;
	for (int i = 0; i < n; i++)
 	cin>>ar[i];
	cout<<"Enter The KEY :"<<endl;
	cin>>key;	
	cout<<"Index of the element is :"<<pivse(ar,n,key);
 	return 0;
}
int pivse(int arr[], int n, int key)
{

	int piv = pivot (arr, 0, n - 1);
 	if (piv == -1)
    		return bins (arr, 0, n - 1, key);
 	if (arr[piv] == key)
  		return piv;
 	if (arr[0] <= key)
   		return bins (arr,0,piv-1,key);
 	else
   		return bins(arr, piv + 1, n - 1, key);
}

int pivot (int arr[], int low, int high)
{
	if (high < low)
   		return -1;
 	if (high == low)
  		return low;
  	int mid = (low + high) / 2;
 	if (mid < high && arr[mid] > arr[mid + 1])
  		return mid;
 	if (mid > low && arr[mid] < arr[mid - 1])
  		return (mid - 1);
	if (arr[low] >= arr[mid])
   		return pivot (arr, low, mid - 1);
  	else
    		return pivot (arr, mid + 1, high);
}
int bins(int arr[], int low, int high, int key)
{

	if (high < low)
   		return -1;
  	int mid = (low + high) / 2;
 	if (key == arr[mid])
    		return mid;
  	if (key > arr[mid])
   		return bins (arr, (mid + 1), high, key);
 	else
   		return bins(arr, low, (mid - 1), key);
}

