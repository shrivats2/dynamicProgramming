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

    vector<int>nums(n);
    vector<int>dp(n,-1);

    for(int i=0;i<n;i++)
        cin>>nums[i];
    
    function<int(int)>helper=[&](int idx)
    {
        if(dp[idx]!=-1) return dp[idx];

        if(idx==0) return nums[idx];

        if(idx<0) return 0;

        int pick=nums[idx]+helper(idx-2);

        int dontpick=helper(idx-1);

        return dp[idx]=max(pick,dontpick);

    };

    cout <<helper(n-1)<<"\n";
       
    return 0;
}