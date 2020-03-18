#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 10
void topological(int a[MAX][MAX],int n);
int main()
{
	int a[MAX][MAX],n;
	int i,j;
        cout<<"Enter the number of vertices\n";
        cin>>n;
        cout<<"Enter the adjacency matrix\n";
        for(i=0;i<n;i++)  
        	{
			for(j=0;j<n;j++)
 				cin>>a[i][j];
		}
	topological(a,n);
    	cout<<endl;
    	return 0;
}
void topological(int a[MAX][MAX], int n)
{
	int in[MAX], out[MAX], stack[MAX], top=-1;
        int i,j,k=0;
        for(i=0;i<n;i++)
    	{
        	in[i] = 0;
        	for (j=0;j<n;j++)
        	{
	        	if(a[j][i]==1)
        	        	in[i]++;
		}
	}
        while(1)
        {
        	for (i=0;i<n;i++)
        	{
            		if (in[i] == 0)
            		{
                		stack[++top] = i;
                			in[i] = -1;
            		}
        	}
        	if (top == -1)
	        	break;
        	out[k] = stack[top--];
        	for(i=0;i<n;i++)
        	{
	        	if (a[out[k]][i] == 1)
        			in[i]--;
        	}
        	k++;
    	}
        cout<<"\nTopological Sorting of the graph is\n";
        for(i=0;i<k;i++)
        	cout<<(out[i] + 1)<<" ";
}