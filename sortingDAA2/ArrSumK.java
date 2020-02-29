import java.util.*;
class ArrSumK
{
   public static boolean checkK(int[] A,int[] B,int k)
   {
      for(int i=0;i<A.length;i++)
	  {
	  for(int j=0;j<B.length;j++)
	  {
	    if(A[i]+B[j]==k)
		return true;
	  }
	  }
	  return false;
   }



 public static void main(String[] args)
  {
	
	 int a[] = {10, 12, 13, 14, 18}; 
        int n = 5; 
       
        int b[] = {16, 17, 19, 20, 22}; 
        int m = 5; 
		int k=26;
       if(checkK(a,b,k)==true)
	   System.out.println("Elements present such that a+b =k");
	   else
	   System.out.println("elements not present such that a+b =k");
        
} 
	  
}