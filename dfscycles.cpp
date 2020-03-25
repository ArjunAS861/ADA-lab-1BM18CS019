#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
int arr[40][40];
bool dfs(int vertex,int parent,set<int>&visited,int n);
bool hasCycle(int n);
int main()
{
	bool res;
  	int n;
   	cout<<"Enter the no of vertices"<<endl;
	cin>>n;
	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
   	res = hasCycle(n);
   	if(res)
      		cout<<"The given graph has cycle"<<endl;
   	else
      		cout<<"The given graph has no cycle"<<endl;
    	return 0;
}
bool dfs(int vertex, int parent,set<int>&visited,int n) 
{
	visited.insert(vertex);
  	for(int v = 0; v<n; v++) 
	{
        	if(arr[vertex][v]) 
		{
         		if(v == parent)    
            			continue;
         		if(visited.find(v) != visited.end())    
            			return true;
         		if(dfs(v,vertex,visited,n))
            			return true;
      		}
   	}
   	return false;
}
bool hasCycle(int n) 
{
	set<int>visited;       
        for(int v = 0; v<n; v++) 
	{
      		if(visited.find(v) != visited.end())    
         		continue;
     		if(dfs(v,-1, visited,n))  
		{
         		return true;
      		}
  	}	
   	return false;
}
