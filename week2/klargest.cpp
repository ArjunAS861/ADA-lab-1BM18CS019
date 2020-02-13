#include<algorithm>
#include<iostream>
#include<cstdlib>

 using namespace std;
 
 int main()
 {
 	
 	
 	int n,k,*a;
 	int i,j,temp=0;
 	cout<<"Enter Size : "<<endl;
 	cin>>n;
 	a=new int[n]; 
 	cout<<"Enter the Elements : "<<endl;
 	for(i=0;i<n;i++)
 	 cin>>a[i];
 	 cout<<"Enter 'K' : ";
 	 cin>>k;

 	for(i=0;i<n-1;i++)
 	 {
 	 		for(j=0;j<n-i-1;j++)
 	 		{
 	 				if (a[j]>a[j+1])
 	 				{
 	 				   temp=a[j+1];
 	 				   a[j+1]=a[j];
 	 				   a[j]=temp;
 	 				 }
 	 		}
 	 }
 	timereq=clock()-timereq;
 	 cout<<k<<"- Largest elements : "<<endl;
 	 for(i=n-1;i>=n-k;i--)
 	 cout<<a[i]<<" ";
 	 cout<<endl;
 	
 	 return 0;
}

