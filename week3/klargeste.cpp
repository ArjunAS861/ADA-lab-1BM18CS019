#include<algorithm>
#include<iostream>
#include<cstdlib>

 using namespace std;
 
 int main()
 {
 	
 	
 	int n,k,*a;
 	int i,j,pos,small,temp=0;
 	cout<<"Enter Size : "<<endl;
 	cin>>n;
 	a=new int[n]; 
 	cout<<"Enter the Elements : "<<endl;
 	for(i=0;i<n;i++)
 	 cin>>a[i];
 	 cout<<"Enter 'K' : ";
 	 cin>>k;
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
 
 	 cout<<k<<"- Largest elements : "<<endl;
 	 for(i=n-1;i>=n-k;i--)
 	 cout<<a[i]<<" ";
 	 cout<<endl;
 	
 	 return 0;
}
/*OUTPUT:
Enter Size : 
5
Enter the Elements : 
4 7 1 3 4
Enter 'K' : 3
3- Largest elements : 
7 4 4 
*/

