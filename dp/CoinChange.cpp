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

int helper(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) 
{
    if (i == 0) 
    {
        if (amt % coins[i] == 0)
            return amt / coins[i];
        return 1e9;
    }
    if (dp[i][amt] != -1)
        return dp[i][amt];

    int take = 1e9;
    if (coins[i] <= amt) 
    {
        take = 1 + helper(i, amt - coins[i], coins, dp);
    }
    int notake = helper(i - 1, amt, coins, dp);

    return dp[i][amt] = min(take, notake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = helper(n - 1, amount, coins, dp);

    return ans == 1e9 ? -1 : ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    int minCoins = coinChange(coins, amount);
    cout << minCoins << "\n";

    return 0;
}