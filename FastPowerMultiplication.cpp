// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007


// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}



long long power(int N,int R);

int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        
        //power of the number to it's reverse
        long long ans =power(N,R);
        cout << ans<<endl;
    }
}// } Driver Code Ends


//You need to complete this fucntion

long long power(int N,int R)
{
   //Your code here
   //OM GAN GANAPATHAYE NAMO NAMAH 
   //JAI SHRI RAM 
   //JAI BAJRANGBALI 
   //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
   long long int c = pow(10,9) + 7;
   long long int temp;
   if(R == 0)
   return 1;
   if(R == 1)
   return N;
   temp = power(N,R/2)%c;
   if(R % 2 == 0)
   {
       long long int y;
       y = ((temp)*(temp))%c;
       return y;
   }
   else
   {
       long long int y;
       y = ((temp)*(temp));
       if(R > 0)
       {
           return ((N%c)*(y%c))%c;
       }
       else
       {
           return (y/N);
       }
   }
}
