//recursive program to find factorial of a number
#include<algorithm>
#include<iostream>
using namespace std;
int fact(int n);
int main()
{	int n;
	cout<<"Enter Number: ";
	cin>>n;
	cout<<"Factorial of "<<n<<" is "<<fact(n)<<endl;
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;

		return (n*fact(n-1));
}
/*OUTPUT:
Enter Number: 3
Factorial of 3 is 6
*/
