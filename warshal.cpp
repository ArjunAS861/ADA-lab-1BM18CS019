//program to implement Warshall algorithm
#include<algorithm>
#include<iostream>
using namespace std;
void warshall(int n, int a[][20]);
int main()
{ 
	int a[20][20],i,j,n;  
        cout<<"Enter No. of vertices: "; 
        cin>>n; 
	cout<<"Enter the Adjacency matrix of the graph : "<<endl; 
        for(i=0;i<n;i++)
	{ 
	        for(j=0;j<n;j++)
	        	cin>>a[i][j];  
        }
	warshall(n,a);
	return 0;
}
void warshall(int n, int a[][20])
{
	int i,j,k,t[20][20];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			t[i][j] = a[i][j];
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(t[i][j]!=1 && (t[i][k]==1 && t[k][j]==1))
					t[i][j]=1;
			}
		}
	}
	cout<<"The path matrix of the given graph is"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
}