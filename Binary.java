//Binary Search
import java.util.*;
class Binary
{
	static void search (int ele,int[] a)
	{		int l=0,h=a.length-1;
			int m;
			boolean f=false;
			while(l<=h)
			{
				m=(l+h)/2;
			if(a[m]==ele)
				{ 
					f=true;
					break;
				}
			else if(a[m]>ele)
				h=m-1;
			 else
			 	l=m+1;
			}
			if(f)
				System.out.println("1");
			else 	System.out.println(-1);	
	}
		
	public static void main(String args[])
	{	
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter number of test cases:");
				int n=sc.nextInt();
			for(int i=0;i<n;i++)
			{
				System.out.println("Enter Size :");
				int m=sc.nextInt();
				int a[] = new int[m];
				System.out.println("Enter the Key :");
				int ele=sc.nextInt();
				System.out.print("Enter the Elements: ");
				for(int j=0;j<m;j++)
					a[j]=sc.nextInt();
				search(ele,a);
			
				
			}
	}
}
