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

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    function<int(int, int)> helper = [&](int i, int amt) {
        if (i == 0) {
            return amt % coins[i] == 0 ? 1 : 0;
        }
        if (dp[i][amt] != -1) return dp[i][amt];
        int notake = helper(i - 1, amt);
        int take = 0;
        if (coins[i] <= amt) {
            take = helper(i, amt - coins[i]);
        }
        return dp[i][amt] = take + notake;
    };

    return helper(n - 1, amount);
}

int main() {
    ll n,amount;
    cin >> amount>> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int ways = change(amount, coins);
    cout << ways << "\n";

    return 0;
}