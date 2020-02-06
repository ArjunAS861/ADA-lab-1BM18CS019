#include<algorithm>
#include<iostream>
using namespace std;
int gcd(int,int);
int main()
{
	int m,n,a;
	cout<<"Enter Two +ve Numbers: \n";
	cin>>m>>n;
	a=gcd(n,m);
	cout<<"GCD of "<<m<<" and "<<n<<" is "<<a;
	return 0;
}
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
/*OUTPUT:
Enter Two +ve Numbers: 
20 4
GCD of 20 and 4 is 4
*/
                                                            
