//recursive program to find nth fibocci number
#include<algorithm>
#include<iostream>
using namespace std;
int fib(int n);
int main()
{	int n;
	cout<<"Enter N: ";
	cin>>n;
	cout<<n<<"th Fibonacci No is "<<fib(n)<<endl;
	return 0;
}
int fib(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if(n>2)
		return (fib(n-1)+fib(n-2));
}
/*OUTPUT:
Enter N: 5
5th Fibonacci No is 3
*/

