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
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // function<int(int,int)>helper=[&](int i,int by)
        // {
        //     if(i>=n) return 0;
        //     if(dp[i][by]!=-1) return dp[i][by];

        //     int profit=0;
        //     if(by==0)
        //     {
        //         profit=max(helper(i+1,0),-prices[i]+helper(i+1,1));
        //     }
        //     else
        //     {
        //         profit=max(helper(i+1,1),prices[i]+helper(i+2,0));
        //     }
        //     return dp[i][by]=profit;
        // };

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;
            
            if (buy == 0) {
                profit = max(dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            } else {
                profit = max(dp[ind + 1][1], prices[ind] + dp[ind + 2][0]);
            }
            
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

int main() 
{
    vector<int> prices= {7, 1, 5, 3, 6, 4};
    int result1 = maxProfit(prices);


    cout << "Maximum Profit: " << result1 << "\n";
    return 0;
}