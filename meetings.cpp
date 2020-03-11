//meetings 
#include<algorithm>
#include<iostream>
using namespace std;
void isort(int a[],int n);
int main()
{
	int n,i,s[50],f[50],resst[50],resf[50],manum[50],p=0,q=0;
	cout<<"Enter Total number of Meetings: ";
	cin>>n;
	cout<<"Enter the start times of the meetings : "<<endl;
	for(i=0;i<n;i++)
		cin>>s[i];
	cout<<"Enter the finishing times of the meetings :"<<endl;
	for(i=0;i<n;i++)
		cin>>f[i];
	isort(s,n);
	isort(f,n);
	resst[0]=s[0];
	resf[0]=f[0];
	
	manum[0]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]>resf[p])
		{
			resst[++q]=s[i];
			resf[++p]=f[i];
			manum[q]=i+1;
		}
	}
	cout<<"Maximum number of Meetings = "<<q+1<<endl;
	cout<<"Meeting numbers are : ";
	for(i=0;i<=q;i++)
		cout<<manum[i]<<" ";
	cout<<endl;
	for(i=0;i<=q;i++)
	{
		cout<<"("<<resst[i]<<","<<resf[i]<<")"<<endl;
	}
	return 0;
}
void isort(int a[],int n)
{
	int i,j,item;
	for(i=1;i<n;i++)
	{
		item = a[i];
		j=i-1;
		while(j>=0 && a[j]>item)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
}
/*OUTPUT:
Enter Total number of Meetings: 5
Enter the start times of the meetings : 
0 56 78 87 90
Enter the finishing times of the meetings :
48 76 86 89 100
Maximum number of Meetings = 5
Meeting numbers are : 1 2 3 4 5 
(0,48)
(56,76)
(78,86)
(87,89)
(90,100)
*/
