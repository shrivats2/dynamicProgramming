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
    ll n;
    cin>>n;

    vector<int>h(n),dp(n+1);

    for(int i=0;i<n;i++)
        cin>>h[i];

    dp[0]=0;
    dp[1]=abs(h[0]-h[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
    } 

    cout<<dp[n-1]<<"\n"; 
       
    return 0;
}