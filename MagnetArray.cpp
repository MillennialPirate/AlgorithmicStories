#include<bits/stdc++.h>
using namespace std;
//function to find the net force on a point x given the arrangement array arr
double isZero(vector<double> arr, double x) 
{
    int i;
    double sum = 0;
    for(i = 0; i < arr.size(); i++)
    {
        sum = sum + (1/(x - arr[i]));
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // arr stores the magnet array arrangement
        //soln stores the points where the net force is zero
        vector<double> arr,soln;
        int i;
        for(i = 0; i < n; i++)
        {
            double x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        for(i = 1; i < arr.size(); i++)
        {
            double l, r;
            l = arr[i-1];//left bound
            r = arr[i];//right bound
            while(l <= r)
            {
                double val;
                double mid;
                mid = (l + r)/2;
                val = isZero(arr,mid);
                //checking the precision as given in the question
                if(abs(val) < 0.0000000000001)
                {
                    printf("%0.2f ", mid);
                    break;
                }
                //search space towards right
                else if(val > 0)
                l = mid;
                //search space towards left
                else
                r = mid;
            }
        }
        cout << endl;
    }
}
