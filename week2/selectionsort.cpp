//selection sort
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{	clock_t timereq;
 	
 	int n,*a,pos,small;;
 	int i,j,temp=0;
 	cout<<"Enter Size : "<<endl;
 	cin>>n;
 	a=new int[n]; 
	cout<<"Enter the Elements:"<<endl;
 	for(i=0;i<n;i++)
 	 cin>>a[i];
 	timereq=clock();
 	for(i=0;i<n-1;i++)
 	 {	pos=i;
		small=a[i];
 	 		for(j=i+1;j<n;j++)
				if(a[j]<small)
				{
					small=a[j];
					pos=j;
				}
			temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
			
 	 }
 	timereq=clock()-timereq;
 	 cout<<"Sorted Array : "<<endl;
 	 for(i=0;i<n;i++)
 	 cout<<a[i]<<" ";
 	 cout<<endl;
 	 cout<<"Time taken : "<<timereq<<" Clock Cycles.";
 	 return 0;
}
/*OUTPUT:
Enter Size : 
5
Enter the Elements:
9 8 7 6 5
Sorted Array : 
5 6 7 8 9 
Time taken : 2 Clock Cycles.
*/
