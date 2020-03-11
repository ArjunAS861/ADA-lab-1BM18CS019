#include<algorithm>
#include<iostream>
using namespace std;
int a[20][20],n,visited[20],s[20],top=-1,c=1,flag=0;
void dfs(int);
int main()
{
	int v,i,j;
	cout<<"Enter the No. of vertices :";
	cin>>n;
	cout<<"Enter the Adjacency matrix: "<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(1);
	if(c==n)
		cout<<"The graph is a connected graph."<<endl;
	else
		cout<<"The graph is not a connected graph."<<endl;
	return 0;
}
void dfs(int v)
{
	int i,j;
	visited[v]=1;
	s[++top]=v;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1 && !visited[i])
		{
			flag=1;
			c++;
			dfs(i);
		}
	}
	if(flag==0)
	{
		for(j=1;j<=n;j++)
		{
			if(a[s[top]][j]==1 && !visited[j])
			{
				flag==1;
				c++;
				dfs(j);
			}
		}
		if(flag==0)
			top--;
	}
}
/*OUTPUT:
Enter the No. of vertices :3
Enter the Adjacency matrix: 
0 1 1
1 0 1
1 1 0
The graph is a connected graph.
*/
