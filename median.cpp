#include<algorithm>
#include<iostream>
using namespace std;
float mergemedian(int a[], int b[], int n);
float median(int arr[], int n);
int main()
{
	int a[100],b[100],n,i;
	float median;
	cout<<"Enter the Size : ";
	cin>>n;
	cout<<"Enter the elements of the 1st  array in ascending order"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the elements of the 2nd array in ascending order"<<endl;
	for(i=0;i<n;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	median = mergemedian(a,b,n);
	cout<<"The median of the merged array = "<<median<<endl;
	return 0;
}
float mergemedian(int a[], int b[], int n) 
{
	float mea,meb; 
	if(n<=0) 
	        return -1; 
	if(n==1) 
        	return (float)(a[0]+b[0])/2; 
	if(n==2) 
        	return (float)(max(a[0],b[0])+min(a[1],b[1]))/2; 
	mea = median(a,n);  
	meb = median(b,n);  
	if(mea==meb) 
        	return mea; 
	if(mea<meb) 
	{ 
        	if(n%2==0) 
        		return mergemedian(a+n/2-1,b,n-n/2+1);
		else
		       	return mergemedian(a+n/2,b,n-n/2); 
    	} 
	if(n%2==0) 
	        return mergemedian(b+n/2-1,a,n-n/2+1); 
	else    	
		return mergemedian(b+n/2,a,n-n/2); 
} 
float median(int arr[], int n) 
{ 
	if(n%2==0) 
        	return (float)(arr[n/2]+arr[n/2-1])/2; 
    	else
        	return arr[n/2]; 
} 
/*OUTPUT:
Enter the Size : 5                                                                                                                              
Enter the elements of the 1st  array in ascending order                                                                                         
2 3 5 7 8                                                                                                                                       
Enter the elements of the 2nd array in ascending order                                                                                          
5 2 1 4 7                                                                                                                                       
The median of the merged array = 4.5                                                                                                            
*/