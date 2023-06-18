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

int rob(vector<int>& nums) 
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    
    int dp[nums.size()], dp1[nums.size()];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size() - 1; i++)
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);

    dp1[0] = 0;
    dp1[1] = nums[1];

    for (int i = 2; i < nums.size(); i++)
        dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);

    return max(dp[nums.size() - 2], dp1[nums.size() - 1]);
}

int main()
{
    ll n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i<n;i++)
    {
        cin >> nums[i];
    }
    int maxAmount = rob(nums);
    cout << maxAmount << "\n";

    return 0;
}