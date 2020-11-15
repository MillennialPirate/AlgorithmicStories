// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
long long int merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int c = 0;
    long long int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    long long int left[n1+1], right[n2+1];
    long long int i, j, k;
    for(i = 0; i < n1; i++)
    left[i] = arr[l + i];
    for(i = 0; i < n2; i++)
    right[i] = arr[m + 1 + i];
    i = 0; 
    j = 0;
    k =  l;
    while(i < n1 && j < n2)
    {
        if(left[i] > right[j])
        {
            c = c + (n1 - i);
            arr[k] = right[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = left[i];
            i++;
            k++;
        }
    }
    while(i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
    return c;
}
long long int inversions(long long int a[], long long int l, long long int r)
{
    long long int c = 0;
    if(r > l)
    {
        long long int m;
        m = l + ((r - l)/2);
        c = c + inversions(a,l,m);
        c = c + inversions(a,m+1,r);
        c = c + merge(a,l,m,r);
    }
    return c;
}
long long int inversionCount(long long arr[], long long n)
{
    // Your Code Here
    //OM GAN GANAPATHAYE NAMO NAMAH 
    //JAI SHRI RAM 
    //JAI BAJRANGBALI 
    //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
    return  inversions(arr,0,n-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
