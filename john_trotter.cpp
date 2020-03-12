//Program for John-Trotter Algorithm
#include<iostream>
#include<algorithm>
using namespace std;
int fact(int);
void printpermutation(int);
int search(int a[], int n,int mob);
void  printper(int a[],int dir[],int n);
int fetchmobile(int a[],int dir[],int n);
void swap(int *,int *);
bool R_T_L =false;
bool L_T_R =true;

int main()
{   int n,i;
    cout<<"Enter No. of Objects: ";
    cin>>n;
    printpermutation(n);
    return 0;
}
void printpermutation(int n)
{
    int *a,*dir,i;
    a = new int[n];
    dir=new int[n];
    cout<<"Permutations : "<<endl;
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        cout<<a[i];
        dir[i]=R_T_L;
    }
    cout<<endl;
    for(i=1;i<fact(n);i++)
       {
            printper(a,dir,n);
            cout<<endl;
        }
}
int search(int a[], int n,int mob)
{
    for(int i=0;i<n;i++)
    if(a[i]==mob)
        return i+1;
}
int fetchmobile(int a[],int dir[],int n)
{   
    int mob=0,mob_prev=0;
    for(int i=0;i<n;i++)
    {
            if(dir[a[i]-1]==R_T_L && i!=0)
            {
                if(a[i]>a[i-1]&& a[i]>mob_prev)
                mob=a[i];
                mob_prev=mob;
            }
    }
     for(int i=0;i<n;i++)
    {
            if(dir[a[i]-1]==L_T_R && i!=n-1)
            {
                if(a[i]>a[i+1]&& a[i]>mob_prev)
                mob=a[i];
                mob_prev=mob;
            }
    }
    if(mob==0 && mob_prev==0)
        return 0;
    else
        return mob;
}
void  printper(int a[],int dir[],int n)
{
    int mobile=fetchmobile(a,dir,n);
    int pos =search(a,n,mobile);
     
    if (dir[a[pos - 1] - 1] ==  R_T_L) 
       swap(a[pos-1], a[pos-2]); 
  
    else if (dir[a[pos - 1] - 1] == L_T_R) 
       swap(a[pos], a[pos-1]); 
  

    for (int i = 0; i < n; i++) 
    { 
        if (a[i] > mobile) 
        { 
            if (dir[a[i] - 1] == L_T_R) 
                dir[a[i] - 1] = R_T_L; 
            else if (dir[a[i] - 1] == R_T_L) 
                dir[a[i] - 1] = L_T_R; 
        } 
    } 
  
    for (int i = 0; i < n; i++) 
        cout << a[i]; 
    cout << " "; 
} 
    
void swap(int *x,int *y)
{
    *x=*x-*y;
    *y=*x+*y;
    *x=*x-*y;
}
int fact(int n)
{   if(n==0)
        return 1;
    
    return (n*fact(n-1));
}
/*OUTPUT:
Enter No. of Objects: 4 
Permutations :                                                                                                                         
1234                                                                                                                                            
1243                                                                                                                                            
1423                                                                                                                                            
4123                                                                                                                                            
4132                                                                                                                                            
1432                                                                                                                                            
1342                                                                                                                                            
1324                                                                                                                                            
3124                                                                                                                                            
3142                                                                                                                                            
3412                                                                                                                                            
4312                                                                                                                                            
4321                                                                                                                                            
3421                                                                                                                                            
3241                                                                                                                                            
3214                                                                                                                                            
2314                                                                                                                                            
2341                                                                                                                                            
2431                                                                                                                                            
4231                                                                                                                                            
4213                                                                                                                                            
2413                                                                                                                                            
2143                                                                                                                                            
2134                                                                                                                                            
*/