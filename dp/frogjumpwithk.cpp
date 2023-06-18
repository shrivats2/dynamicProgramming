#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout << "YES"<< "\n";
#define no cout << "NO" << "\n";
#define fr(i, a, b) for(int i = a; i<b; i++)
#define vi vector<ll>
#define pb push_back
#define aa(l,n) ll l[n]; fr(i,0,n) cin>>l[i];
#define av(l, n) vector<ll> l(n); fr(i,0,n) cin>>l[i];

const int mod = 1e9 + 7;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n,k;
    cin>>n>>k;

    vector<int>h(n),dp(n+1,1e9);

    for(int i=0;i<n;i++)
        cin>>h[i];

    dp[0] = 0 ;
    for(int i=1;i<n; i++)
    {
        for(int j=i-1;j>=i-k;j--)
        {
            if(j < 0)
                break ;
            dp[i] = min(dp[i],dp[j] + abs(h[i] - h[j])) ;
        }
    }
    cout << dp[n-1] ;
       
    return 0;
}