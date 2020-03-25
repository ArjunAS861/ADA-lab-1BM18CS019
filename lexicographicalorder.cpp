#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
#define MAX 15
void topological(int a[MAX][MAX],int n);
bool dfs(int v, set<int>&wSet, set<int>&gSet, set<int>&bSet, int n, int a[MAX][MAX]);
bool hascycle(int n, int a[MAX][MAX]);
int main()
{
	int a[MAX][MAX],n,in[MAX];
	int i,j,k=0;
	bool res;
        cout<<"Enter the number of vertices"<<endl;
        cin>>n;
        cout<<"Enter the adjacency matrix"<<endl;
        for(i=0;i<n;i++)  
        {
		for(j=0;j<n;j++)
 			cin>>a[i][j];
	}
	res = hascycle(n,a);
	if(res)
		cout<<"\n-1 (The graph contains one or more cycles)";
	else
		topological(a,n);
    	cout<<endl;
    	return 0;
}
void topological(int a[MAX][MAX], int n)
{
	int in[MAX], out[MAX], stack[MAX], top=-1, max, temp;
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
        	for(i=0;i<n;i++)
	        {
	       		if(in[i]==0)
	       		{
	               		stack[++top] = i;
	               			in[i] = -1;
        		}
        	}
  		if(top==-1)
        		break;
		if(top>=1)
		{	
			for(i=0;i<top;i++)
			{
				max = i;
				for(j=i+1;j<(top+1);j++)
				{
					if(stack[j]>stack[max])
					max = j;
				}
				temp = stack[i];
				stack[i] = stack[max];
				stack[max] = temp;
			}
		}
  		out[k] = stack[top--];
       		for(i=0;i<n;i++)
       		{
        		if(a[out[k]][i]==1)
       				in[i]--;
       		}
        	k++;
  	}
	cout<<"Lexicographically smallest topological ordering of the graph is"<<endl;
        for(i=0;i<k;i++)
        	cout<<(out[i]+1)<<" ";
}
bool dfs(int v, set<int>&wSet, set<int>&gSet, set<int>&bSet, int n, int a[MAX][MAX]) 
{
	int i;
	wSet.erase(wSet.find(v));
	gSet.insert(v);
	for(i=0;i<n;i++) 
	{
	        if(a[v][i]!=0) 
		{   
	  		if(bSet.find(i) != bSet.end())
          			continue;    
         		if(gSet.find(i) != gSet.end())
                		return true;    
         		if(dfs(i, wSet, gSet, bSet, n, a))
           			return true; 
	        }
   	}
        gSet.erase(gSet.find(v));
        bSet.insert(v);
        return false;
}
bool hascycle(int n, int a[MAX][MAX]) 
{
	int i,v;
	set<int> wSet, gSet, bSet;    
        for(i=0;i<n;i++)
      		wSet.insert(i);    
   	while(wSet.size()>0) 
	{
		for(v=0;v<n;v++) 
		{
		        if(wSet.find(v)!=wSet.end())
			{
        			if(dfs(v, wSet, gSet, bSet, n, a))
               				return true;
			}
  	        }
        }
        return false;
}
