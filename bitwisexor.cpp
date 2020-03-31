/*Given an integer N which is a multiple of 4, the task is to find an N x N grid for 
which the bitwise xor of every row and column is same.*/
#include<algorithm> 
#include<iostream>
using namespace std;
void xormatrix(int n);
int main()
{
	int n;
	cout<<"Enter a number which is a multiple of 4 : ";
	cin>>n;
	if(n%4==0)
		xormatrix(n);
	else
		cout<<"\nInvalid Input."<<endl;
	return 0;
}
void xormatrix(int n)
{
	int a[n][n];
	int q=0,i,j,k,l;
	for(i=0;i<n/4;i++)
	{
		for(j=0;j<n/4;j++)
		{
			for(k=0;k<4;k++)
			{
				for(l=0;l<4;l++)
				{
					a[i*4+k][j*4+l] = q;
					q++;
				}
			}
		}
	}
	cout<<"The matrix in which the bitwise XOR of each row and column is the same is "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
/*OUTPUT:
/*Given an integer N which is a multiple of 4, the task is to find an N x N grid for 
which the bitwise xor of every row and column is same.*/
#include<algorithm> 
#include<iostream>
using namespace std;
void xormatrix(int n);
int main()
{
	int n;
	cout<<"Enter a number which is a multiple of 4 : ";
	cin>>n;
	if(n%4==0)
		xormatrix(n);
	else
		cout<<"\nInvalid Input."<<endl;
	return 0;
}
void xormatrix(int n)
{
	int a[n][n];
	int q=0,i,j,k,l;
	for(i=0;i<n/4;i++)
	{
		for(j=0;j<n/4;j++)
		{
			for(k=0;k<4;k++)
			{
				for(l=0;l<4;l++)
				{
					a[i*4+k][j*4+l] = q;
					q++;
				}
			}
		}
	}
	cout<<"The matrix in which the bitwise XOR of each row and column is the same is "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
/*OUTPUT:
Enter a number which is a multiple of 4 : 4                                                                                                    
The matrix in which the bitwise XOR of each row and column is the same is                                                                      
0 1 2 3                                                                                                                                        
4 5 6 7                                                                                                                                        
8 9 10 11                                                                                                                                      
12 13 14 15     
*/

