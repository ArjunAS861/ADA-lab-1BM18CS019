//Knapsack Problem
#include<algorithm>
#include<iostream>
using namespace std;
int knapsack(int n, int m, int w[], int p[]);
int main()
{	int *w,*p;
	int n,m,ops,i;
	cout<<"Enter the No. of objects: ";
	cin>>n;
	cout<<"Enter the maximum capacity of the Knapsack : ";
	cin>>m;
	w=new int[n];
	p=new int[n];
	cout<<"Enter the weights of the objects\n";
	for(i=0;i<n;i++)
		cin>>w[i];
	cout<<"Enter the profits for each objects\n";
	for(i=0;i<n;i++)
		cin>>p[i];
	cout<<endl;
	ops = knapsack(n,m,w,p);
	cout<<"The optimal solution from selected items produces profit = "<<ops<<endl;
	return 0;
}
int knapsack(int n, int m, int w[], int p[])
{
	int x[n],v[n+1][m+1],i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				v[i][j] = 0;
			else if(w[i-1]>j)
				v[i][j] = v[i-1][j];
			else 
				v[i][j] = max(v[i-1][j],(v[i-1][j-w[i-1]]+p[i-1]));
		}
	}
	for(i=0;i<n;i++)
		x[i] = 0;
	i = n;
	j = m;
	while(i!=0 && j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i-1] = 1;
 			j = j-w[i-1];
		}
		i--;
	}
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
			cout<<"Object "<<i+1<<" is selected"<<endl;
		else
			cout<<"Object "<<i+1<<" is not selected"<<endl;
	}
	return v[n][m];
}
/*OUTPUT:
Enter the No. of objects: 5                                                                                                                   
Enter the maximum capacity of the Knapsack : 6                                                                                                
Enter the weights of the objects                                                                                                              
2 3 1 2 3                                                                                                                                     
Enter the profits for each objects                                                                                                            
15 16 12 11 16                                                                                                                                
                                                                                                                                              
Object 1 is selected                                                                                                                          
Object 2 is selected                                                                                                                          
Object 3 is selected                                                                                                                          
Object 4 is not selected                                                                                                                      
Object 5 is not selected                                                                                                                      
The optimal solution from selected items produces profit = 43     
*/