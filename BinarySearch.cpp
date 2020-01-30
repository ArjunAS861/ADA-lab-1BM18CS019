#include <algorithm> 
#include <iostream> 
  
using namespace std; 
  
 
  
int main() 
{ 

    int t,a[100],n,ele;
    cout<< "Enter the number of test cases\n";
    cin>>t;
    for(int j=0;j<t;j++)
    {
    cout<< "Enter the number of elements and the element you want to search for\n";
    cin>>n;
    cin>>ele;
    cout<< "Enter the elements\n";
   	 for(int i=0;i<n;i++)
    	{
    	cin>> a[i];
   	 }
     
   
    
    if (binary_search(a, a + n-1, ele)) 
        cout << "\n(1) Element found in the array\n"; 
    else
        cout << "\n(-1) Element not found in the array\n"; 
  
    
    }
  
    return 0; 
} 
