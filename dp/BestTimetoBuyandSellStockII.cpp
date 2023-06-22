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

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    function<int(int, int)> helper = [&](int ind, int buy) 
    {
        if (ind == n) return 0;
        
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
            
        int profit;
        
        if (buy == 0) 
        {
            profit = max(helper(ind + 1, 0), -prices[ind] + helper(ind + 1, 1));
        }
        
        if (buy == 1)
         {
            profit = max(helper(ind + 1, 1), prices[ind] + helper(ind + 1, 0));
        }
        
        return dp[ind][buy] = profit;
    };

    return helper(0, 0);
}

int main() 
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << result << endl;

    return 0;
}