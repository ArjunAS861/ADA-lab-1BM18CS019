#include<algorithm>
#include<iostream>
using namespace std;
void twh(int,char,char,char);
int main()
{
		
			int n;char a='A',b='B',c='C';
			cout<<"Enter the Size : ";
			cin>>n;
			twh(n,a,c,b);
			return 0;
}
void twh(int n, char st, char des , char tem)
{
		if(n==1)
			{
			cout<<"Mov Disc 1 from "<<st<<" to "<<des<<endl;
			return;
			}
		twh(n-1,st,tem,des);
		cout<<"Mov Disc "<<n<<" from "<<st<<" to "<<des<<endl;
		twh(n-1,tem,des,st);
}			
/*
Output:
Enter the Size : 3
Mov Disc 1 from A to C
Mov Disc 2 from A to B
Mov Disc 1 from C to B
Mov Disc 3 from A to C
Mov Disc 1 from B to A
Mov Disc 2 from B to C
Mov Disc 1 from A to C
*/			
