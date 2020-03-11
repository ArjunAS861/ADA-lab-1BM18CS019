//breadth first search
#include<algorithm>
#include<iostream>
using namespace std;
void bfs(int,int,int,int,int visited[],int a[][25],int q[]);
int main()
{ 
	int a[25][25],q[25],visited[25],f=0,r=-1,i,j,n,v;  
        cout<<"Enter no. of vertices: "; 
        cin>>n; 
        for(i=1;i<=n;i++) 
        { 
   	     q[i]=0; 
             visited[i]=0; 
        } 
        cout<<"Enter Adjacency Matrix of the graph"<<endl; 
        for(i=1;i<=n;i++)
	{ 
	        for(j=1;j<=n;j++)
		{ 
                cin>>a[i][j]; 
                } 
        } 
        cout<<"Enter the starting node of your choice : "; 
        cin>>v; 
        bfs(v,n,f,r,visited,a,q); 
        cout<<"All the nodes reachable from "<<v<<"->"<<n<<" are : "<<endl; 
        for(i=1;i<=n;i++)
	{ 
	        if(visited[i]) 
                cout<<i<<" "; 
        } 
	cout<<endl;
      	return 0; 
}
void bfs(int v,int n,int f, int r, int visited[], int a[][25], int q[])
{ 
	int i,j;
	for(i=1;i<=n;i++)
	{
                if(a[v][i] && !visited[i]) 
               		q[++r]=i; 
                if(f<=r)
		{ 
	                 visited[q[f]]=1; 
	                 bfs(q[f++],n,f,r,visited,a,q); 
                }  
        }
}
/*OUTPUT:
Enter no. of vertices: 3
Enter Adjacency Matrix of the graph
1 0 0
0 1 0
0 0 1
Enter the starting node of your choice : 1
All the nodes reachable from 1->3 are : 
1 
*/
