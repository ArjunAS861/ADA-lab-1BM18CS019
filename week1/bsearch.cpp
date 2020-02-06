#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int A[100],key,n,j,fpos,lpos,count,m,i,k,h,l=0;
	cout<<"Enter Size : ";
	cin>>n;
	h=n-1;
	cout<<"Enter the Sorted Array : "<<endl;
	for(j=0;j<n;j++)
		cin>>A[j];
	cout<<"Enter Key : ";
	cin>>key;
	while(l<=h)
	{
		m=(l+h)/2;	
		if(A[m]==key)
			{	i=k=m;
				while(A[i]==key)
				{
					fpos=i;
					i--;
				}
				while(A[k]==key)
				{
					lpos=k;
					k++;
				}
				count=lpos-fpos+1;
				cout<<"Element Found."<<endl;
				cout<<"First Occurence : "<<fpos<<endl;
				cout<<"Last Occurence : "<<lpos<<endl;
				cout<<"Count : "<<count<<endl;
				break;
			}
		else if(A[m]>key)
			h=m-1;
		else
			l=m+1;
	}
	if(l>h)
		cout<<"Element Not found."<<endl;
	return 0;
}
/*OUTPUT:
Enter Size : 5
Enter the Sorted Array : 
1 1 2 2 3
Enter Key : 2
Element Found.
First Occurence : 2
Last Occurence : 3
Count : 2
*/

		
