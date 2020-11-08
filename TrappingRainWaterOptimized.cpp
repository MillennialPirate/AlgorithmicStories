#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;//n is the number of elements in the array 
    int arr[10000];//this is the barchart taken as input in the  form of array 
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    cin >> arr[i];
    int l[10000];//this stores the maximum at the left side for each array element
    int r[10000];//this stores the maximum at the right side for each array element
    int max = 0;//stores the maximum value
    for(i = 0; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        l[i] = max;
    }
    max = 0;
    for(i = n-1; i >= 0; i--)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        r[i] = max;
    }
    int sum = 0;//this is the final result
    for(i = 0; i < n; i++)
    {
        if(l[i] > r[i])
        {
            sum = sum + (r[i] - arr[i]);
        }
        else
        {
            sum = sum + (l[i] - arr[i]);
        }
    }
    cout << sum << endl;
}
