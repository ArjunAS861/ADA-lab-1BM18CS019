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
	
 	for(i=0;i<n;i++)
 	 a[i]=rand()/10000000;
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
}/*OUTPUT:
Enter Size : 
40
Sorted Array : 
3 23 27 29 30 33 42 46 52 59 62 63 71 78 84 86 102 105 110 110 112 118 130 131 135 136 136 154 164 165 168 171 172 180 180 195 196 204 208 214 
Time taken : 10 Clock Cycles.
*/
