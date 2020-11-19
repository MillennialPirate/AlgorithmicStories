#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() 
{
    int n;
    cin>>n;
    long long int a[1000000],prefix[1000000];
    long long int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    prefix[0]=0;
    for(i=1;i<=n;i++)
    prefix[i]=prefix[i-1]+a[i-1];
    long long int l=0,r=0;
    long long int ans=0;
    set<long long int>s={0};
    while(l<n)
    {
        while(r<n && !s.count(prefix[r+1]))
        {
            r++;
            s.insert(prefix[r]);
        }
        ans=ans+(r-l);
        s.erase(prefix[l]);
        l++;
    }
    cout<<ans<<endl;
}
