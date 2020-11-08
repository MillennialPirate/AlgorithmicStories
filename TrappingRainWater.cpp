#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; // the number of elements in the array 
    int arr[100000];//the array which represents the bar chart 
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    cin >> arr[i];
    int left, right;
    int sum = 0;//the final answer we want
    //let's traverse the array and find the maximum height bar on left and right side of each bar 
    for(i = 1; i < n-1; i++)
    {
        int l = arr[i];
        for(int j = 0; j < i; j++)
        {
            if(l < arr[j])
            l = arr[j];
        }
        int r = arr[i];
        for(int j = i+1; j < n; j++)
        {
            if(r < arr[j])
            r = arr[j];
        }
        //for each bar the water stored on top of it will be given by the formula -> minimum(l,r) - arr[i]. This is l and r are the boundaries of the water storage container and arr[i] units space is taken by the particular bar. 
        sum = sum + (min(l,r)-arr[i]);
    }
    cout << sum << endl;
}
