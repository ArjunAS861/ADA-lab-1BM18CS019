#include<algorithm>
#include<iostream>
int N;
bool isvalid(int board[50][50], int row, int col);
bool solvenqueen(int board[50][50], int col);
using namespace std;
int main() 
{   
	cout<<"Enter the value of N for NxN chessboard\n";
	cin>>N;
   	int board[50][50],i,j;
   	for(i=0;i<N;i++)
   	{
		for(j=0;j<N;j++)
   			board[i][j] = 0; 
	}   	
	if(solvenqueen(board,0)==false) 
   		cout<<"\nSolution does not exist\n";
      	else
   	{
		cout<<"\nThe places of "<<N<<" queens on the chessboard are\n";
		for(i=0;i<N;i++) 
		{
	      		for(j=0;j<N;j++)
	        		cout<<board[i][j]<<" ";
        		cout<<endl;
   		}	
	}	
   	return 0;
}
bool isvalid(int board[50][50], int row, int col) 
{
	int i,j;
   	for(i=0;i<col;i++) 
	{
      		if (board[row][i])
         		return false;
	}
   	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1) 
	       		return false;
	}
   	for(i=row,j=col;i<N && j>=0;i++,j--)
	{
		if(board[i][j]==1)
       			return false;
	}
   	return true;
}
bool solvenqueen(int board[50][50], int col) 
{
	int i,j;
   	if(col>=N)
      		return true;
   	for(i=0;i<N;i++) 
	{ 
      		if(isvalid(board,i,col))
		{
         		board[i][col] = 1; 
         		if(solvenqueen(board,col+1))
            			return true;
         		board[i][col] = 0;       
		}
   	}
   	return false; 
}

/*Output:
1.
Enter the value of N for NxN chessboard
5
The places of 5 queens on the chessboard are
1 0 0 0 0 
0 0 0 1 0 
0 1 0 0 0 
0 0 0 0 1 
0 0 1 0 0
2.
Enter the value of N for NxN chessboard
2
Solution does not exist
*/

