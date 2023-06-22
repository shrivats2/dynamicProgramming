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
        int mn = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i]-mn);
        }
        return profit;
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
    cout <<result << endl;

    return 0;
}