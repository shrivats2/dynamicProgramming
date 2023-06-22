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

int unboundedKnapsack(int n, int w, vector<int>& profit, vector<int>& weight) 
{
    int c = -1e9;
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    function<int(int, int)> helper = [&](int i, int w) {
        if (i == 0) {
            return (w / weight[i]) * profit[i];
        }
        if (dp[i][w] != -1) return dp[i][w];

        int take = c;

        if (weight[i] <= w) {
            take = profit[i] + helper(i, w - weight[i]);
        }
        int notake = helper(i - 1, w);

        return dp[i][w] = max(take, notake);
    };

    return helper(n - 1, w);
}

int main() 
{
    ll n,w;
    cin >> n>> w;

    vector<int> profit(n);
    vector<int> weight(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> profit[i];
    }

    for (int i = 0; i < n; i++) 
    {
        cin >> weight[i];
    }

    int maxProfit = unboundedKnapsack(n, w, profit, weight);
    cout <<maxProfit << "\n";

    return 0;
}