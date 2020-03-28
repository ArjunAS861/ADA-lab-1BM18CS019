//progtram to implement floyd algorithm
#include<algorithm>
#include<iostream>
using namespace std;
void floyd(int n, int a[][20]);
int main()
{ 
	int a[20][20],q[20],i,j,n;  
        cout<<"Enter the No. of vertices of the digraph/graph:"; 
        cin>>n; 
	cout<<"Enter the Adjacency matrix of the graph (Enter 1000 for INF): "<<endl; 
        for(i=0;i<n;i++)
	{ 
	        for(j=0;j<n;j++)
	        	cin>>a[i][j];  
        }
	floyd(n,a);
	return 0;
}
void floyd(int n, int a[][20])
{
	int i,j,k,d[20][20];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			d[i][j] = a[i][j];
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				d[i][j] = min(d[i][j],(d[i][k]+d[k][j]));
		}
	}
	cout<<"The distance matrix of shortest paths of the given graph is "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
}
/*OUTPUT:
Enter the No. of vertices of the digraph/graph:4                                                                                                
Enter the Adjacency matrix of the graph (Enter 1000 for INF):                                                                                   
0 5 1000 10                                                                                                                                     
1000 0 3 1000                                                                                                                                   
1000 1000 0 1                                                                                                                                   
1000 1000 1000 0                                                                                                                                
The distance matrix of shortest paths of the given graph is                                                                                     
0 5 8 9                                                                                                                                         
1000 0 3 4                                                                                                                                      
1000 1000 0 1                                                                                                                                   
1000 1000 1000 0   
*/