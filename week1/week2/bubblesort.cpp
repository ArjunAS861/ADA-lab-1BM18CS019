#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>

 using namespace std;
 
 int main()
 {
 	clock_t timereq;
 	
 	int n,*a;
 	int i,j,temp=0;
 	cout<<"Enter Size : "<<endl;
 	cin>>n;
 	a=new int[n]; 

 	for(i=0;i<n;i++)
 	 a[i]=(rand()/10000000);
 	timereq=clock();
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
 	 cout<<"Sorted Array : "<<endl;
 	 for(i=0;i<n;i++)
 	 cout<<a[i]<<" ";
 	 cout<<endl;
 	 cout<<"Time taken : "<<timereq<<" Clock Cycles.";
 	 return 0;
}

 
