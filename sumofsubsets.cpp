#include<algorithm>
#include<iostream>
bool found = false;
void printsubsets(int A[], int size);
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int target_sum);
void generatesubsets(int s[], int size, int target_sum);
using namespace std;
int main()
{
   	int s[50],size,m,i;
   	cout<<"Enter the number of positive integers in the set\n";
	cin>>size;
	cout<<"Enter the positive integers belonging to the set\n";
	for(i=0;i<size;i++)
		cin>>s[i];
	cout<<"Enter the required sum of subset value\n";
	cin>>m;
   	generatesubsets(s,size,m);
	if(found==false)
		cout<<"\nSolution does not exist\n";
	return 0;
}
void printsubsets(int A[], int size)
{
	int i;
	cout<<"\nThe subset having the required sum is:\n";
	for(i=0;i<size;i++) 
	{
      		cout<<A[i]<<" ";
   	}
   	cout<<endl;
}
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int target_sum)
{
	int i;
   	if(target_sum==sum) 
	{
		printsubsets(t,t_size);
  		subset_sum(s,t,s_size,t_size-1,sum-s[ite],ite+1,target_sum);
      		found = true;
	}
   	else 
	{
		for(i=ite;i<s_size;i++) 
		{
   			t[t_size] = s[i];
         		subset_sum(s,t,s_size,t_size+1,sum+s[i],i+1,target_sum);
      		}
   	}
}
void generatesubsets(int s[], int size, int target_sum)
{
   	int* tuplet_vector = (int*)malloc(size * sizeof(int));
   	subset_sum(s,tuplet_vector,size,0,0,0,target_sum);
   	free(tuplet_vector);
}

/*Output:
1. 
Enter the number of positive integers in the set
6
Enter the positive integers belonging to the set
3 5 7 9 10 11
Enter the required sum of subset value
19
The subset having the required sum is:
3 5 11 
The subset having the required sum is:
3 7 9 
The subset having the required sum is:
9 10 
2. 
Enter the number of positive integers in the set
4
Enter the positive integers belonging to the set
3 5 6 7
Enter the required sum of subset value
17
Solution does not exist
*/

