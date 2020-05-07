#include<algorithm>
#include<iostream>
using namespace std;
int minimum(int visited[], int dist[], int n);
void dijkstras(int src, int a[][30], int n);
int main()
{
	int a[30][30],n,i,j,src;
	cout<<"Enter the no. of vertices\n";
	cin>>n;
	cout<<"Enter the weighted adjacency matrix (Enter 10000 if there is no edge between the two vertices)\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<"Enter the source vertex\n";
	cin>>src;
	dijkstras(src,a,n);
	return 0;
}
int minimum(int visited[], int dist[], int n)
{
	int md = 10000,mi,i;
	for(i=0;i<n;i++)
	{
		if(!visited[i] && dist[i]<md)
		{
			md = dist[i];
			mi = i;
		}
	}
	return mi;
}
void dijkstras(int src, int a[][30], int n)
{
	int dist[n],visited[n],i,j,v,u;
	for(i=0;i<n;i++)
	{
		dist[i]=10000;
		visited[i]=0;
	}
	dist[src] = 0;
	for(i=0;i<n-1;i++)
	{
		u = minimum(visited,dist,n);
		visited[u] = 1;
		for(v=0;v<n;v++)
		{
			if(!visited[v] && a[u][v]!=10000 && dist[u]!=10000 && (dist[u]+a[u][v])<dist[v])
				dist[v]=dist[u]+a[u][v];
		}
	}
	cout<<"\nThe shortest paths to all other vertices from "<<src<<" are\n";
	cout<<"Vertices\tDistance from source\n";
	i=0;
	while(i<n)
	{
		if(i==src)
		{
			i++;
			continue;
		}
		cout<<i<<"\t\t"<<dist[i]<<endl;
		i++;
	}
}

/*Output:
Enter the no. of vertices
5
Enter the weighted adjacency matrix (Enter 10000 if there is no edge between the two vertices)
0 10000 10000 7 10000
3 0 4 10000 10000
10000 10000 0 10000 6
10000 2 5 0 10000
10000 10000 10000 4 0
Enter the source vertex
0
The shortest paths to all other vertices from 0 are
Vertices	Distance from source
1		9
2		12
3		7
4		18
*/
