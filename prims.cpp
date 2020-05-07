#include<algorithm>
#include<iostream>
void prim(int v, int a[][30], int visited[], int n);
int wtmst = 0,c = 0;
using namespace std;
int main()
{
	int a[30][30],visited[30],n,i,j;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	cout<<"Enter the weight matrix of the graph (Enter 10000 if there exists no edge between the two vertices)\n";
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<"\nThe Minimum Spanning Tree (MST) is\n";
	cout<<"Edge\tWeight\n";
	prim(0,a,visited,n);
	cout<<"\nThe total weight of MST by Prim's algorithm = "<<wtmst<<"\n";
	return 0;
}
void prim(int v, int a[][30], int visited[], int n)
{
	int i,j,min = 10000,it,jt;
	visited[v] = 1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(visited[i]==1 && visited[j]==0)
			{
				if(a[i][j]<min)
				{
					min = a[i][j];
					it = i;
					jt = j;
				}
			}
		}
	}
	wtmst = wtmst+a[it][jt];
	cout<<it+1<<"->"<<jt+1<<"\t"<<a[it][jt]<<"\n";
	c++;
	visited[jt] = 1;
	if(c==n-1)
		return; 
	prim(jt,a,visited,n);
}

/*Output:
Enter the number of vertices
5
Enter the weight matrix of the graph (Enter 10000 if there exists no edge between the two vertices)
0 10000 3 10000 10000
10000 0 10 4 10000
3 10 0 2 6
10000 4 2 0 1
10000 10000 6 1 0
The Minimum Spanning Tree (MST) is
Edge	Weight
1->3	3
3->4	2
4->5	1
4->2	4
The total weight of MST by Prim's algorithm = 10
*/			
