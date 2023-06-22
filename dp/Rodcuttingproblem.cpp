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

int cutRod(vector<int>& price, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> helper = [&](int i, int len) {
        if (i == 1) {
            return (len / i) * price[i - 1];
        }
        if (dp[i][len] != -1) return dp[i][len];

        int take = INT_MIN;
        if (i <= len) {
            take = price[i - 1] + helper(i, len - i);
        }
        int notake = helper(i - 1, len);

        return dp[i][len] = max(take, notake);
    };

    return helper(n, n);
}

int main() 
{
    ll n;
    cin >> n;

    vector<int> price(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> price[i];
    }

    int maxProfit = cutRod(price, n);
    cout <<maxProfit << "\n";

    return 0;
}