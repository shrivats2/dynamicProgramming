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

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));

    function<int(int, int)> helper = [&](int i, int w) {
        if (i == 0 || w == 0) {
            return 0;
        }
        if (dp[i][w] != -1) {
            return dp[i][w];
        }

        int result;
        if (weight[i - 1] <= w) {
            int include = value[i - 1] + helper(i - 1, w - weight[i - 1]);
            int exclude = helper(i - 1, w);
            result = max(include, exclude);
        } else {
            result = helper(i - 1, w);
        }

        dp[i][w] = result;

        return result;
    };

    return helper(n, maxWeight);
}

int main() 
{
    ll n;
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++) 
    {
        cin >> value[i];
    }

    ll maxWeight;
    cin >> maxWeight;

    int maxVal = knapsack(weight, value, n, maxWeight);
    cout << maxVal << "\n";

    return 0;
}